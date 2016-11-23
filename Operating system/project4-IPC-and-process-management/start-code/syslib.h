/* syslib.h */
#ifndef SYSLIB_H
#define SYSLIB_H

// Includes
#include "common.h"

// Constants
enum {
    IGNORE = 0
};

//we do begin
int lock_init_do(void);
void lock_acquire_do(lock_id i);
void lock_release_do(lock_id i);
//we do end*/

/* yield the current process */
void yield(void);

/* terminate the current process */
void exit(void);

/* get the process id */
int getpid(void);

/* get the process priority */
int getpriority(void);

/* set the process priority
 * 1 - lowest priority
 * >1 - higher priority
 */
void setpriority(int);

/* sleep for the specified number of milliseconds */
void sleep(int);

/* shut down the computer */
void shutdown(void);

/* write the character to the serial port
 * Note that bochs is configured so that
 * every character written to the serial
 * port is appended to the file serial.out
 */
void write_serial(char);

/* reads a character from the keyboard
 * input buffer.  If the buffer is empty,
 * the process will block until a character
 * is available.
 */
char get_char(void);

/* start a new process from the given
 * name.
 * If the process name could not be found, return -1.
 * If the process table is full, return -2.
 * If successful, return the PID of the new process.
 *
 * Note that these a not really "filenames,"
 * but actually refer to names in the
 * ramdisk.  See 'ramdisk.h'
 */
pid_t spawn(const char *filename);

/* Kills a process; i.e. mark the process
 * as exited.  This should free-up the
 * entry in the process table, so that
 * later calls to spawn() can use that
 * process table entry.
 * Returns -1 if that process does not
 * exist, or 0 otherwise.
 */
int kill(pid_t pid);

/* Blocks until the specified process
 * terminates.  Returns -1 if that
 * process does not exist.
 * Returns 0 otherwise.
 */
int wait(pid_t pid);

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
mbox_t mbox_open(const char *name);

/* Closes a message box
 */
void mbox_close(mbox_t mbox);

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
 * If the message is longer than
 * MAX_MESSAGE_LENGTH, it will
 * be truncated.
 */
void mbox_send(mbox_t mbox, void *msg, int nbytes);

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
void mbox_recv(mbox_t mbox, void *msg, int nbytes);


#endif
