#include "common.h"
#include "mbox.h"
#include "sync.h"
#include "scheduler.h"
#include "util.h"

mailbox_t mail_box[MAX_MBOXEN];

/* Perform any system-startup
 * initialization for the message
 * boxes.
 */

void init_mbox_one(mbox_t i)
{
	mail_box[i].use_num = 0;
	mail_box[i].name[0] = '\0';
	mail_box[i].msg_count = 0;
	mail_box[i].write_place = 0;
	mail_box[i].read_place = 0;
	lock_init(&mail_box[i].l);
	mail_box[i].send_wait_queue.next = &mail_box[i].send_wait_queue;
	mail_box[i].send_wait_queue.prev = &mail_box[i].send_wait_queue;
	mail_box[i].recv_wait_queue.next = &mail_box[i].recv_wait_queue;
	mail_box[i].recv_wait_queue.prev = &mail_box[i].recv_wait_queue;
}

void init_mbox(void)
{
	int i;
	for(i = 0; i < MAX_MBOXEN; i++)
		init_mbox_one(i);
}

/* Opens the mailbox named 'name', or
 * creates a new message box if it
 * doesn't already exist.
 * A message box is a bounded buffer
 * which holds up to MAX_MBOX_LENGTH items.
 * If it fails because the message
 * box table is full, it will return -1.
 * Otherwise, it returns a message box
 * id.
 */
mbox_t do_mbox_open(const char *name)
{
  (void)name;
  int i, j;
  for(i = 0; i < MAX_MBOXEN; i++)
	if(same_string(name, mail_box[i].name))
	{
		current_running->mailbox[i] = TRUE;
		return i;
	}
  for(i = 0; i < MAX_MBOXEN; i++)
  {
	  if(strlen(mail_box[i].name) == 0)
	  {
		j = strlen(name);
		bcopy(name, mail_box[i].name, j);
		{
			current_running->mailbox[i] = TRUE;
			return i;
		}
	  }
  }
  return -1;
}

/* Closes a message box
 */
void do_mbox_close(mbox_t mbox)
{
  (void)mbox;
	mail_box[mbox].use_num--;
	current_running->mailbox[mbox] = FALSE;
	if(mail_box[mbox].use_num == 0)
		init_mbox_one(mbox);
}

/* Determine if the given
 * message box is full.
 * Equivalently, determine
 * if sending to this mbox
 * would cause a process
 * to block.
 */
int do_mbox_is_full(mbox_t mbox)
{
  (void)mbox;
	if(mail_box[mbox].msg_count == MAX_MBOX_LENGTH)
	{
		block_mail(&mail_box[mbox].send_wait_queue);
		return 1;
	}
	return 0;
}

/* Enqueues a message onto
 * a message box.  If the
 * message box is full, the
 * process will block until
 * it can add the item.
 * You may assume that the
 * message box ID has been
 * properly opened before this
 * call.
 * The message is 'nbytes' bytes
 * starting at offset 'msg'
 */
void do_mbox_keyboard(mbox_t mbox, void *msg, int nbytes)
{
  (void)mbox;
  (void)msg;
  (void)nbytes;
	if(mail_box[mbox].msg_count == MAX_MBOX_LENGTH)
		return;
	lock_acquire(&mail_box[mbox].l);
	int i;
	for(i = 0; i < nbytes && i < MAX_MESSAGE_LENGTH; i++)
		mail_box[mbox].box[mail_box[mbox].write_place].msg[i] = *((char *)msg + i);
	mail_box[mbox].write_place++;
	mail_box[mbox].write_place = mail_box[mbox].write_place % MAX_MBOX_LENGTH;
	mail_box[mbox].msg_count++;
	lock_release(&mail_box[mbox].l);
	unblock_mailbox_wait(&mail_box[mbox].recv_wait_queue);
}
void do_mbox_send(mbox_t mbox, void *msg, int nbytes)
{
  (void)mbox;
  (void)msg;
  (void)nbytes;
	do_mbox_is_full(mbox);
	lock_t *l = current_running->node_queue.l;
	lock_acquire(&mail_box[mbox].l);
	int i;
	for(i = 0; i < nbytes && i < MAX_MESSAGE_LENGTH; i++)
		mail_box[mbox].box[mail_box[mbox].write_place].msg[i] = *((char *)msg + i);
	mail_box[mbox].write_place++;
	mail_box[mbox].write_place = mail_box[mbox].write_place % MAX_MBOX_LENGTH;
	mail_box[mbox].msg_count++;
	lock_release(&mail_box[mbox].l);
	current_running->node_queue.l = l;
	unblock_mailbox_wait(&mail_box[mbox].recv_wait_queue);
}

/* Receives a message from the
 * specified message box.  If
 * empty, the process will block
 * until it can remove an item.
 * You may assume that the
 * message box has been properly
 * opened before this call.
 * The message is copied into
 * 'msg'.  No more than
 * 'nbytes' bytes will by copied
 * into this buffer; longer
 * messages will be truncated.
 */
int do_mbox_is_empty(mbox_t mbox)
{
  (void)mbox;
	if(mail_box[mbox].msg_count == 0)
	{
		block_mail(&mail_box[mbox].recv_wait_queue);
		return 1;
	}
	return 0;
}
void do_mbox_recv(mbox_t mbox, void *msg, int nbytes)
{
  (void)mbox;
  (void)msg;
  (void)nbytes;
	do_mbox_is_empty(mbox);
	lock_t *l = current_running->node_queue.l;
	lock_acquire(&mail_box[mbox].l);
	int i;
	for(i = 0; i < nbytes && i < MAX_MESSAGE_LENGTH; i++)
		*((char *)msg + i) = mail_box[mbox].box[mail_box[mbox].read_place].msg[i];
	mail_box[mbox].read_place++;
	mail_box[mbox].read_place = mail_box[mbox].read_place % MAX_MBOX_LENGTH;
	mail_box[mbox].msg_count--;
	lock_release(&mail_box[mbox].l);
	current_running->node_queue.l = l;
	unblock_mailbox_wait(&mail_box[mbox].send_wait_queue);
}


