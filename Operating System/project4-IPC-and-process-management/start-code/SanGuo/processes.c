#include "common.h"
#include "syslib.h"
#include "util.h"
#include "printf.h"

void init(void)
{
  ASSERT( spawn("SunQuan") >= 0 );
  ASSERT( spawn("LiuBei") >= 0 );
  ASSERT( spawn("CaoCao") >= 0 );
  exit();
}

void SunQuan(void)
{
  mbox_t pub = mbox_open("SunQuan-Publish-PID");
  pid_t myPid = getpid();

  /* Send PID twice, once for LiuBei,
   * and once for the CaoCao
   */
  mbox_send(pub, &myPid, sizeof(pid_t));
  mbox_send(pub, &myPid, sizeof(pid_t));

  /* Find LiuBei's PID */
  mbox_t sub = mbox_open("LiuBei-Publish-PID");

  for(;;)
  {
    pid_t liubei;
    mbox_recv(sub, &liubei, sizeof(pid_t));

    printf(1,1, "SunQuan (%d): I'm waiting for Liubei               ", myPid);

    wait(liubei);

    printf(1,1, "SunQuan(%d): I'm coming to save you, LiuBei!", myPid);

    sleep(1000);
    spawn("LiuBei");
    mbox_send(pub, &myPid, sizeof(pid_t));
  }
}

void LiuBei(void)
{
  mbox_t pub = mbox_open("LiuBei-Publish-PID");
  pid_t myPid = getpid();

  /* Send PID twice, once for sunquan Hood,
   * and once for the CaoCao
   */
  mbox_send(pub, &myPid, sizeof(pid_t));
  mbox_send(pub, &myPid, sizeof(pid_t));

  /* Find sunquan's PID */
  mbox_t sub = mbox_open("SunQuan-Publish-PID");

  for(;;)
  {
    pid_t aramis;
    mbox_recv(sub, &aramis, sizeof(pid_t));

    printf(2,1, "LiuBei(%d): I'm waiting for SunQuan         ", myPid);

    wait(aramis);

    printf(2,1, "LiuBei(%d): I'm coming to save you, SunQuan!", myPid);

    sleep(1000);
    spawn("SunQuan");
    mbox_send(pub, &myPid, sizeof(pid_t));
  }

}


void CaoCao(void)
{
  uint32_t myRand = get_timer();

  pid_t myPid = getpid();

  mbox_t subSunQuan = mbox_open("SunQuan-Publish-PID");
  mbox_t subLiuBei = mbox_open("LiuBei-Publish-PID");

  pid_t sunquan, liubei;

  mbox_recv(subSunQuan, &sunquan, sizeof(pid_t));
  mbox_recv(subLiuBei, &liubei, sizeof(pid_t));

  for(;;)
  {
    printf(10,1, "CaoCao(%d): I am working... muahaha ", myPid);

    sleep(5000);

    printf(10,1, "CaoCao(%d): I have my decision! ", myPid);

    myRand = rand_step(myRand);

    switch( myRand % 2 )
    {
      case 0:
        printf(11, 1, "CaoCao(%d): I will kill SunQuan (%d)!  ", myPid, sunquan);
        sleep(1000);
        printf(1,1, "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX ");
        kill( sunquan );
        mbox_recv(subSunQuan, &sunquan, sizeof(pid_t));
        printf(12, 1, "CaoCao(%d): Oops! SunQuan(%d) lives!                 ", myPid, sunquan);
        break;
      case 1:
        printf(11, 1, "CaoCao(%d): I will kill LiuBei(%d)! ", myPid, liubei);
        sleep(1000);
        printf(2,1, "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX ");
        kill( liubei );
        mbox_recv(subLiuBei, &liubei, sizeof(pid_t));
        printf(12, 1, "CaoCao(%d): Oops! LiuBei(%d) is alive again! ", myPid, liubei);
        break;
    }

    sleep(2000);
    printf(11, 1, "                                                           ");
    printf(12, 1, "                                                                      ");
  }
}




