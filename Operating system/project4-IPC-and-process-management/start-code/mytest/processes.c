#include "common.h"
#include "syslib.h"
#include "util.h"
#include "printf.h"
int col, liubei, caocao, sunquan;

static void get_line(char *buffer, int maxlen);

void init(void)
{
	spawn("rewatch");
	for(;;)
	{
		char buffer[100];
		get_line(buffer, 100);
		pid_t result = spawn(buffer);
		if( result == -1 )
			printf(19, 1, "*** Error: %s not found ***      ", buffer);
		else if( result == -2 )
			printf(19, 1, "*** Error: process table full ***");
		else
			printf(19, 1, "Started process PID=%d", result);
	}
}

void shutdown_process(void)
{
	shutdown();
}
void theplay(void)
{
	clear_screen(0, 0, 100, 100);
	col = 1;
	liubei = 0;
	caocao = 0;
	sunquan = 0;
	printf(19, 1, "Type shutdown to shutdown...");
	printf(1, 1," %d-Game Start!,The players are SunQuan, Liu Bei, and CaoCao.", col++);
	sleep(2000);
	spawn("SunQuan");
	spawn("LiuBei");
	spawn("CaoCao");
	mbox_t sub = mbox_open("SunQuan-Publish-PID");
	pid_t sunquan;
	mbox_recv(sub, &sunquan, sizeof(pid_t));
	mbox_close("SunQuan-Publish-PID");
	wait(sunquan);
	printf(14,1,"%d-The game end.", col++);
	printf(17,1,"if you want to rewatch, type 'rewatch'.");
	printf(18,1,"                                                    Directed by 12");
	for(;;);
	exit();
}

void SunQuan(void)
{
	sunquan++;
	mbox_t pub = mbox_open("SunQuan-Publish-PID");
	mbox_t subc = mbox_open("CaoCao-Publish-PID");
	mbox_t subl = mbox_open("LiuBei-Publish-PID");
	mbox_t lmail = mbox_open("LOCK-PID");
	pid_t myPid = getpid();
	pid_t kill_one;
	lock_id lid;
	if(sunquan == 1)
	{
		mbox_send(pub, &myPid, sizeof(pid_t));
		mbox_close("SunQuan-Publish-PID");
		mbox_recv(subc, &kill_one, sizeof(pid_t));
		kill(kill_one);
		sleep(2000);
		printf(4, 1, " %d-SunQuan(%d): I help CaoCao.           (I kill LiuBei(%d).)", col++, myPid, kill_one);
		mbox_recv(subl, &kill_one, sizeof(pid_t));
		kill(kill_one);
		sleep(2000);
		printf(7, 1, " %d-SunQuan(%d): I help LiuBei.           (I kill CaoCao(%d).)", col++, myPid, kill_one);
		mbox_recv(lmail, &lid, sizeof(lock_id));
		mbox_recv(subl, &kill_one, sizeof(pid_t));
		sleep(2000);
		printf(9, 1, " %d-SunQuan(%d): I want the JingZhou.     (I know lock(%d), and Liubei(%d).)", col++, myPid, lid, kill_one);
		mbox_send(subc, &kill_one, sizeof(pid_t));
		lock_acquire_do(0);
		sleep(2000);
		printf(11, 1, "%d-SunQuan(%d): I win the JingZhou.      (I get lock(%d) and spawn LiuBei later.)", col++, myPid, lid);
		spawn("LiuBei");
		mbox_recv(subl, &kill_one, sizeof(pid_t));
		sleep(2000);
		printf(13, 1, "%d-SunQuan(%d): I exit the game.", col++, myPid);
		exit();
	}
}

void LiuBei(void)
{
	liubei++;
	mbox_t pub = mbox_open("LiuBei-Publish-PID");
	mbox_t sub = mbox_open("CaoCao-Publish-PID");
	mbox_t lmail = mbox_open("LOCK-PID");
	pid_t myPid = getpid();
	pid_t kill_one;
	lock_id lid;
	if(liubei == 1)
	{
		lid = lock_init_do();
		mbox_send(pub, &myPid, sizeof(pid_t));
		mbox_send(lmail, &lid, sizeof(lock_id));
		lock_acquire_do(lid);
		sleep(2000);
		printf(2, 1, " %d-LiuBei (%d): I have the JingZhou.     (I get lock(%d).)", col++, myPid, lid);		
		for(;;);
	}
	else if(liubei == 2)
	{
		mbox_recv(lmail, &lid, sizeof(lock_id));
		mbox_recv(sub, &kill_one, sizeof(pid_t));
		sleep(2000);
		printf(6, 1, " %d-LiuBei (%d): I want the JingZhou Back.(I know lock(%d), and CaoCao(%d).)", col++, myPid, lid, kill_one);
		mbox_send(pub, &kill_one, sizeof(pid_t));
		lock_acquire_do(lid);
		sleep(2000);
		printf(8, 1, " %d-LiuBei (%d): I get JingZhou back.     (I get lock(%d) and spawn CaoCao later.)", col++, myPid, lid);
		spawn("CaoCao");
		mbox_send(lmail, &lid, sizeof(lock_id));
		mbox_send(pub, &myPid, sizeof(pid_t));
		for(;;);
	}
	else if(liubei == 3)
	{
		mbox_send(pub, &myPid, sizeof(pid_t));
		sleep(2000);
		printf(12, 1, "%d-LiuBei (%d): I exit the game.", col++, myPid, kill_one);
		exit();
	}
	exit();
}

void CaoCao(void)
{
	caocao++;
	pid_t myPid = getpid();
	mbox_t pub = mbox_open("CaoCao-Publish-PID");
	mbox_t sub = mbox_open("LiuBei-Publish-PID");
	mbox_t lmail = mbox_open("LOCK-PID");
	pid_t kill_one;
	lock_id lid;
	if(caocao == 1)
	{
		mbox_recv(sub, &kill_one, sizeof(pid_t));
		mbox_recv(lmail, &lid, sizeof(lock_id));
		sleep(2000);
		printf(3, 1, " %d-CaoCao (%d): I want JingZhou.         (I know lock(%d), and Liubei(%d).)", col++, myPid, lid, kill_one);
		mbox_send(pub, &kill_one, sizeof(pid_t));
		lock_acquire_do(lid);
		sleep(2000);
		printf(5, 1, " %d-CaoCao (%d): I get JingZhou.          (I get lock(%d) and spawn LiuBei later.)", col++, myPid, lid);
		spawn("LiuBei");
		mbox_send(lmail, &lid, sizeof(lock_id));
		mbox_send(pub, &myPid, sizeof(pid_t));
		for(;;);
	}
	else if(caocao == 2)
	{
		mbox_recv(pub, &kill_one, sizeof(pid_t));
		kill(kill_one);
		sleep(2000);
		printf(10, 1, "%d-CaoCao (%d): I exit the game.         (I kill LiuBei(%d) and exit.)", col++, myPid, kill_one);
		exit();
	}
	exit();	
}

static void get_line(char *buffer, int maxlen)
{
  int offset;
  for(offset=0; offset<maxlen; )
  {
    char c = get_char();
    if( c == '\n' || c == '\r' )
      break;
    else if( c == '\b' )
    {
      if( offset > 0 )
      {
        offset --;
        printf(21, 1 + 2 + offset, " ");
      }
      continue;
    }
    else
    {
      printf(21, 1 + 2 + offset, "%c", c);
      buffer[offset++] = c;
    }
  }
  if( offset >= maxlen )
    offset = maxlen - 1;
  buffer[offset] = '\0';
}


