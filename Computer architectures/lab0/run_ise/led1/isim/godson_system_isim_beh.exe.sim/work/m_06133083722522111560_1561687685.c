/**********************************************************************/
/*   ____  ____                                                       */
/*  /   /\/   /                                                       */
/* /___/  \  /                                                        */
/* \   \   \/                                                       */
/*  \   \        Copyright (c) 2003-2009 Xilinx, Inc.                */
/*  /   /          All Right Reserved.                                 */
/* /---/   /\                                                         */
/* \   \  /  \                                                      */
/*  \___\/\___\                                                    */
/***********************************************************************/

/* This file is designed for use with ISim build 0xfbc00daa */

#define XSI_HIDE_SYMBOL_SPEC true
#include "xsi.h"
#include <memory.h>
#ifdef __GNUC__
#include <stdlib.h>
#else
#include <malloc.h>
#define alloca _alloca
#endif
static const char *ng0 = "/home/ucas/cpu_lab/lab_0_20161010/rtl_led/AMBA/axi_mux.v";
static unsigned int ng1[] = {0U, 0U};
static unsigned int ng2[] = {1U, 0U};
static int ng3[] = {0, 0};
static int ng4[] = {2, 0};
static int ng5[] = {1, 0};



static void Always_1956_0(char *t0)
{
    char t4[8];
    char t24[8];
    char t35[8];
    char t42[8];
    char t84[8];
    char *t1;
    char *t2;
    char *t3;
    char *t5;
    char *t6;
    unsigned int t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    char *t12;
    char *t13;
    unsigned int t14;
    unsigned int t15;
    unsigned int t16;
    unsigned int t17;
    unsigned int t18;
    char *t19;
    char *t20;
    unsigned int t21;
    unsigned int t22;
    unsigned int t23;
    unsigned int t25;
    unsigned int t26;
    unsigned int t27;
    unsigned int t28;
    unsigned int t29;
    unsigned int t30;
    unsigned int t31;
    unsigned int t32;
    char *t33;
    char *t34;
    unsigned int t36;
    unsigned int t37;
    unsigned int t38;
    unsigned int t39;
    unsigned int t40;
    char *t41;
    unsigned int t43;
    unsigned int t44;
    unsigned int t45;
    char *t46;
    char *t47;
    char *t48;
    unsigned int t49;
    unsigned int t50;
    unsigned int t51;
    unsigned int t52;
    unsigned int t53;
    unsigned int t54;
    unsigned int t55;
    char *t56;
    char *t57;
    unsigned int t58;
    unsigned int t59;
    unsigned int t60;
    unsigned int t61;
    unsigned int t62;
    unsigned int t63;
    unsigned int t64;
    unsigned int t65;
    int t66;
    int t67;
    unsigned int t68;
    unsigned int t69;
    unsigned int t70;
    unsigned int t71;
    unsigned int t72;
    unsigned int t73;
    char *t74;
    unsigned int t75;
    unsigned int t76;
    unsigned int t77;
    unsigned int t78;
    unsigned int t79;
    char *t80;
    char *t81;
    char *t82;
    char *t83;
    char *t85;

LAB0:    t1 = (t0 + 4416U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(1956, ng0);
    t2 = (t0 + 6472);
    *((int *)t2) = 1;
    t3 = (t0 + 4448);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(1956, ng0);

LAB5:    xsi_set_current_line(1957, ng0);
    t5 = (t0 + 1344U);
    t6 = *((char **)t5);
    memset(t4, 0, 8);
    t5 = (t6 + 4);
    t7 = *((unsigned int *)t5);
    t8 = (~(t7));
    t9 = *((unsigned int *)t6);
    t10 = (t9 & t8);
    t11 = (t10 & 1U);
    if (t11 != 0)
        goto LAB9;

LAB7:    if (*((unsigned int *)t5) == 0)
        goto LAB6;

LAB8:    t12 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t12) = 1;

LAB9:    t13 = (t4 + 4);
    t14 = *((unsigned int *)t13);
    t15 = (~(t14));
    t16 = *((unsigned int *)t4);
    t17 = (t16 & t15);
    t18 = (t17 != 0);
    if (t18 > 0)
        goto LAB10;

LAB11:    xsi_set_current_line(1959, ng0);
    t2 = (t0 + 1664U);
    t3 = *((char **)t2);
    memset(t4, 0, 8);
    t2 = (t3 + 4);
    t7 = *((unsigned int *)t2);
    t8 = (~(t7));
    t9 = *((unsigned int *)t3);
    t10 = (t9 & t8);
    t11 = (t10 & 1U);
    if (t11 != 0)
        goto LAB16;

LAB14:    if (*((unsigned int *)t2) == 0)
        goto LAB13;

LAB15:    t5 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t5) = 1;

LAB16:    t6 = (t4 + 4);
    t12 = (t3 + 4);
    t14 = *((unsigned int *)t3);
    t15 = (~(t14));
    *((unsigned int *)t4) = t15;
    *((unsigned int *)t6) = 0;
    if (*((unsigned int *)t12) != 0)
        goto LAB18;

LAB17:    t22 = *((unsigned int *)t4);
    *((unsigned int *)t4) = (t22 & 1U);
    t23 = *((unsigned int *)t6);
    *((unsigned int *)t6) = (t23 & 1U);
    memset(t24, 0, 8);
    t13 = (t4 + 4);
    t25 = *((unsigned int *)t13);
    t26 = (~(t25));
    t27 = *((unsigned int *)t4);
    t28 = (t27 & t26);
    t29 = (t28 & 1U);
    if (t29 != 0)
        goto LAB19;

LAB20:    if (*((unsigned int *)t13) != 0)
        goto LAB21;

LAB22:    t20 = (t24 + 4);
    t30 = *((unsigned int *)t24);
    t31 = *((unsigned int *)t20);
    t32 = (t30 || t31);
    if (t32 > 0)
        goto LAB23;

LAB24:    memcpy(t42, t24, 8);

LAB25:    t74 = (t42 + 4);
    t75 = *((unsigned int *)t74);
    t76 = (~(t75));
    t77 = *((unsigned int *)t42);
    t78 = (t77 & t76);
    t79 = (t78 != 0);
    if (t79 > 0)
        goto LAB33;

LAB34:
LAB35:
LAB12:    goto LAB2;

LAB6:    *((unsigned int *)t4) = 1;
    goto LAB9;

LAB10:    xsi_set_current_line(1958, ng0);
    t19 = ((char*)((ng1)));
    t20 = (t0 + 3184);
    xsi_vlogvar_wait_assign_value(t20, t19, 0, 0, 2, 0LL);
    goto LAB12;

LAB13:    *((unsigned int *)t4) = 1;
    goto LAB16;

LAB18:    t16 = *((unsigned int *)t4);
    t17 = *((unsigned int *)t12);
    *((unsigned int *)t4) = (t16 | t17);
    t18 = *((unsigned int *)t6);
    t21 = *((unsigned int *)t12);
    *((unsigned int *)t6) = (t18 | t21);
    goto LAB17;

LAB19:    *((unsigned int *)t24) = 1;
    goto LAB22;

LAB21:    t19 = (t24 + 4);
    *((unsigned int *)t24) = 1;
    *((unsigned int *)t19) = 1;
    goto LAB22;

LAB23:    t33 = (t0 + 1824U);
    t34 = *((char **)t33);
    memset(t35, 0, 8);
    t33 = (t34 + 4);
    t36 = *((unsigned int *)t33);
    t37 = (~(t36));
    t38 = *((unsigned int *)t34);
    t39 = (t38 & t37);
    t40 = (t39 & 1U);
    if (t40 != 0)
        goto LAB26;

LAB27:    if (*((unsigned int *)t33) != 0)
        goto LAB28;

LAB29:    t43 = *((unsigned int *)t24);
    t44 = *((unsigned int *)t35);
    t45 = (t43 & t44);
    *((unsigned int *)t42) = t45;
    t46 = (t24 + 4);
    t47 = (t35 + 4);
    t48 = (t42 + 4);
    t49 = *((unsigned int *)t46);
    t50 = *((unsigned int *)t47);
    t51 = (t49 | t50);
    *((unsigned int *)t48) = t51;
    t52 = *((unsigned int *)t48);
    t53 = (t52 != 0);
    if (t53 == 1)
        goto LAB30;

LAB31:
LAB32:    goto LAB25;

LAB26:    *((unsigned int *)t35) = 1;
    goto LAB29;

LAB28:    t41 = (t35 + 4);
    *((unsigned int *)t35) = 1;
    *((unsigned int *)t41) = 1;
    goto LAB29;

LAB30:    t54 = *((unsigned int *)t42);
    t55 = *((unsigned int *)t48);
    *((unsigned int *)t42) = (t54 | t55);
    t56 = (t24 + 4);
    t57 = (t35 + 4);
    t58 = *((unsigned int *)t24);
    t59 = (~(t58));
    t60 = *((unsigned int *)t56);
    t61 = (~(t60));
    t62 = *((unsigned int *)t35);
    t63 = (~(t62));
    t64 = *((unsigned int *)t57);
    t65 = (~(t64));
    t66 = (t59 & t61);
    t67 = (t63 & t65);
    t68 = (~(t66));
    t69 = (~(t67));
    t70 = *((unsigned int *)t48);
    *((unsigned int *)t48) = (t70 & t68);
    t71 = *((unsigned int *)t48);
    *((unsigned int *)t48) = (t71 & t69);
    t72 = *((unsigned int *)t42);
    *((unsigned int *)t42) = (t72 & t68);
    t73 = *((unsigned int *)t42);
    *((unsigned int *)t42) = (t73 & t69);
    goto LAB32;

LAB33:    xsi_set_current_line(1960, ng0);
    t80 = (t0 + 3184);
    t81 = (t80 + 56U);
    t82 = *((char **)t81);
    t83 = ((char*)((ng2)));
    memset(t84, 0, 8);
    xsi_vlog_unsigned_add(t84, 2, t82, 2, t83, 2);
    t85 = (t0 + 3184);
    xsi_vlogvar_wait_assign_value(t85, t84, 0, 0, 2, 0LL);
    goto LAB35;

}

static void Always_1963_1(char *t0)
{
    char t4[8];
    char t24[8];
    char t35[8];
    char t42[8];
    char t84[8];
    char *t1;
    char *t2;
    char *t3;
    char *t5;
    char *t6;
    unsigned int t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    char *t12;
    char *t13;
    unsigned int t14;
    unsigned int t15;
    unsigned int t16;
    unsigned int t17;
    unsigned int t18;
    char *t19;
    char *t20;
    unsigned int t21;
    unsigned int t22;
    unsigned int t23;
    unsigned int t25;
    unsigned int t26;
    unsigned int t27;
    unsigned int t28;
    unsigned int t29;
    unsigned int t30;
    unsigned int t31;
    unsigned int t32;
    char *t33;
    char *t34;
    unsigned int t36;
    unsigned int t37;
    unsigned int t38;
    unsigned int t39;
    unsigned int t40;
    char *t41;
    unsigned int t43;
    unsigned int t44;
    unsigned int t45;
    char *t46;
    char *t47;
    char *t48;
    unsigned int t49;
    unsigned int t50;
    unsigned int t51;
    unsigned int t52;
    unsigned int t53;
    unsigned int t54;
    unsigned int t55;
    char *t56;
    char *t57;
    unsigned int t58;
    unsigned int t59;
    unsigned int t60;
    unsigned int t61;
    unsigned int t62;
    unsigned int t63;
    unsigned int t64;
    unsigned int t65;
    int t66;
    int t67;
    unsigned int t68;
    unsigned int t69;
    unsigned int t70;
    unsigned int t71;
    unsigned int t72;
    unsigned int t73;
    char *t74;
    unsigned int t75;
    unsigned int t76;
    unsigned int t77;
    unsigned int t78;
    unsigned int t79;
    char *t80;
    char *t81;
    char *t82;
    char *t83;
    char *t85;

LAB0:    t1 = (t0 + 4664U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(1963, ng0);
    t2 = (t0 + 6488);
    *((int *)t2) = 1;
    t3 = (t0 + 4696);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(1963, ng0);

LAB5:    xsi_set_current_line(1964, ng0);
    t5 = (t0 + 1344U);
    t6 = *((char **)t5);
    memset(t4, 0, 8);
    t5 = (t6 + 4);
    t7 = *((unsigned int *)t5);
    t8 = (~(t7));
    t9 = *((unsigned int *)t6);
    t10 = (t9 & t8);
    t11 = (t10 & 1U);
    if (t11 != 0)
        goto LAB9;

LAB7:    if (*((unsigned int *)t5) == 0)
        goto LAB6;

LAB8:    t12 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t12) = 1;

LAB9:    t13 = (t4 + 4);
    t14 = *((unsigned int *)t13);
    t15 = (~(t14));
    t16 = *((unsigned int *)t4);
    t17 = (t16 & t15);
    t18 = (t17 != 0);
    if (t18 > 0)
        goto LAB10;

LAB11:    xsi_set_current_line(1966, ng0);
    t2 = (t0 + 1504U);
    t3 = *((char **)t2);
    memset(t4, 0, 8);
    t2 = (t3 + 4);
    t7 = *((unsigned int *)t2);
    t8 = (~(t7));
    t9 = *((unsigned int *)t3);
    t10 = (t9 & t8);
    t11 = (t10 & 1U);
    if (t11 != 0)
        goto LAB16;

LAB14:    if (*((unsigned int *)t2) == 0)
        goto LAB13;

LAB15:    t5 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t5) = 1;

LAB16:    t6 = (t4 + 4);
    t12 = (t3 + 4);
    t14 = *((unsigned int *)t3);
    t15 = (~(t14));
    *((unsigned int *)t4) = t15;
    *((unsigned int *)t6) = 0;
    if (*((unsigned int *)t12) != 0)
        goto LAB18;

LAB17:    t22 = *((unsigned int *)t4);
    *((unsigned int *)t4) = (t22 & 1U);
    t23 = *((unsigned int *)t6);
    *((unsigned int *)t6) = (t23 & 1U);
    memset(t24, 0, 8);
    t13 = (t4 + 4);
    t25 = *((unsigned int *)t13);
    t26 = (~(t25));
    t27 = *((unsigned int *)t4);
    t28 = (t27 & t26);
    t29 = (t28 & 1U);
    if (t29 != 0)
        goto LAB19;

LAB20:    if (*((unsigned int *)t13) != 0)
        goto LAB21;

LAB22:    t20 = (t24 + 4);
    t30 = *((unsigned int *)t24);
    t31 = *((unsigned int *)t20);
    t32 = (t30 || t31);
    if (t32 > 0)
        goto LAB23;

LAB24:    memcpy(t42, t24, 8);

LAB25:    t74 = (t42 + 4);
    t75 = *((unsigned int *)t74);
    t76 = (~(t75));
    t77 = *((unsigned int *)t42);
    t78 = (t77 & t76);
    t79 = (t78 != 0);
    if (t79 > 0)
        goto LAB33;

LAB34:
LAB35:
LAB12:    goto LAB2;

LAB6:    *((unsigned int *)t4) = 1;
    goto LAB9;

LAB10:    xsi_set_current_line(1965, ng0);
    t19 = ((char*)((ng1)));
    t20 = (t0 + 3344);
    xsi_vlogvar_wait_assign_value(t20, t19, 0, 0, 2, 0LL);
    goto LAB12;

LAB13:    *((unsigned int *)t4) = 1;
    goto LAB16;

LAB18:    t16 = *((unsigned int *)t4);
    t17 = *((unsigned int *)t12);
    *((unsigned int *)t4) = (t16 | t17);
    t18 = *((unsigned int *)t6);
    t21 = *((unsigned int *)t12);
    *((unsigned int *)t6) = (t18 | t21);
    goto LAB17;

LAB19:    *((unsigned int *)t24) = 1;
    goto LAB22;

LAB21:    t19 = (t24 + 4);
    *((unsigned int *)t24) = 1;
    *((unsigned int *)t19) = 1;
    goto LAB22;

LAB23:    t33 = (t0 + 2144U);
    t34 = *((char **)t33);
    memset(t35, 0, 8);
    t33 = (t34 + 4);
    t36 = *((unsigned int *)t33);
    t37 = (~(t36));
    t38 = *((unsigned int *)t34);
    t39 = (t38 & t37);
    t40 = (t39 & 1U);
    if (t40 != 0)
        goto LAB26;

LAB27:    if (*((unsigned int *)t33) != 0)
        goto LAB28;

LAB29:    t43 = *((unsigned int *)t24);
    t44 = *((unsigned int *)t35);
    t45 = (t43 & t44);
    *((unsigned int *)t42) = t45;
    t46 = (t24 + 4);
    t47 = (t35 + 4);
    t48 = (t42 + 4);
    t49 = *((unsigned int *)t46);
    t50 = *((unsigned int *)t47);
    t51 = (t49 | t50);
    *((unsigned int *)t48) = t51;
    t52 = *((unsigned int *)t48);
    t53 = (t52 != 0);
    if (t53 == 1)
        goto LAB30;

LAB31:
LAB32:    goto LAB25;

LAB26:    *((unsigned int *)t35) = 1;
    goto LAB29;

LAB28:    t41 = (t35 + 4);
    *((unsigned int *)t35) = 1;
    *((unsigned int *)t41) = 1;
    goto LAB29;

LAB30:    t54 = *((unsigned int *)t42);
    t55 = *((unsigned int *)t48);
    *((unsigned int *)t42) = (t54 | t55);
    t56 = (t24 + 4);
    t57 = (t35 + 4);
    t58 = *((unsigned int *)t24);
    t59 = (~(t58));
    t60 = *((unsigned int *)t56);
    t61 = (~(t60));
    t62 = *((unsigned int *)t35);
    t63 = (~(t62));
    t64 = *((unsigned int *)t57);
    t65 = (~(t64));
    t66 = (t59 & t61);
    t67 = (t63 & t65);
    t68 = (~(t66));
    t69 = (~(t67));
    t70 = *((unsigned int *)t48);
    *((unsigned int *)t48) = (t70 & t68);
    t71 = *((unsigned int *)t48);
    *((unsigned int *)t48) = (t71 & t69);
    t72 = *((unsigned int *)t42);
    *((unsigned int *)t42) = (t72 & t68);
    t73 = *((unsigned int *)t42);
    *((unsigned int *)t42) = (t73 & t69);
    goto LAB32;

LAB33:    xsi_set_current_line(1967, ng0);
    t80 = (t0 + 3344);
    t81 = (t80 + 56U);
    t82 = *((char **)t81);
    t83 = ((char*)((ng2)));
    memset(t84, 0, 8);
    xsi_vlog_unsigned_add(t84, 2, t82, 2, t83, 2);
    t85 = (t0 + 3344);
    xsi_vlogvar_wait_assign_value(t85, t84, 0, 0, 2, 0LL);
    goto LAB35;

}

static void Cont_1970_2(char *t0)
{
    char t5[8];
    char t9[8];
    char t18[8];
    char t22[8];
    char t48[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t6;
    char *t7;
    char *t8;
    char *t10;
    char *t11;
    unsigned int t12;
    unsigned int t13;
    unsigned int t14;
    unsigned int t15;
    unsigned int t16;
    unsigned int t17;
    char *t19;
    char *t20;
    char *t21;
    char *t23;
    char *t24;
    unsigned int t25;
    unsigned int t26;
    unsigned int t27;
    unsigned int t28;
    unsigned int t29;
    unsigned int t30;
    char *t31;
    unsigned int t32;
    unsigned int t33;
    unsigned int t34;
    unsigned int t35;
    unsigned int t36;
    char *t37;
    char *t38;
    char *t39;
    unsigned int t40;
    unsigned int t41;
    unsigned int t42;
    unsigned int t43;
    unsigned int t44;
    unsigned int t45;
    unsigned int t46;
    unsigned int t47;
    char *t49;
    char *t50;
    unsigned int t51;
    unsigned int t52;
    unsigned int t53;
    unsigned int t54;
    unsigned int t55;
    unsigned int t56;
    unsigned int t57;
    unsigned int t58;
    unsigned int t59;
    unsigned int t60;
    unsigned int t61;
    unsigned int t62;
    char *t63;
    char *t64;
    char *t65;
    char *t66;
    char *t67;
    char *t68;
    unsigned int t69;
    unsigned int t70;
    char *t71;
    unsigned int t72;
    unsigned int t73;
    char *t74;
    unsigned int t75;
    unsigned int t76;
    char *t77;

LAB0:    t1 = (t0 + 4912U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(1970, ng0);
    t2 = (t0 + 3184);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t6 = (t0 + 3344);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    memset(t9, 0, 8);
    t10 = (t9 + 4);
    t11 = (t8 + 4);
    t12 = *((unsigned int *)t8);
    t13 = (t12 >> 0);
    t14 = (t13 & 1);
    *((unsigned int *)t9) = t14;
    t15 = *((unsigned int *)t11);
    t16 = (t15 >> 0);
    t17 = (t16 & 1);
    *((unsigned int *)t10) = t17;
    t19 = (t0 + 3344);
    t20 = (t19 + 56U);
    t21 = *((char **)t20);
    memset(t22, 0, 8);
    t23 = (t22 + 4);
    t24 = (t21 + 4);
    t25 = *((unsigned int *)t21);
    t26 = (t25 >> 1);
    t27 = (t26 & 1);
    *((unsigned int *)t22) = t27;
    t28 = *((unsigned int *)t24);
    t29 = (t28 >> 1);
    t30 = (t29 & 1);
    *((unsigned int *)t23) = t30;
    memset(t18, 0, 8);
    t31 = (t22 + 4);
    t32 = *((unsigned int *)t31);
    t33 = (~(t32));
    t34 = *((unsigned int *)t22);
    t35 = (t34 & t33);
    t36 = (t35 & 1U);
    if (t36 != 0)
        goto LAB7;

LAB5:    if (*((unsigned int *)t31) == 0)
        goto LAB4;

LAB6:    t37 = (t18 + 4);
    *((unsigned int *)t18) = 1;
    *((unsigned int *)t37) = 1;

LAB7:    t38 = (t18 + 4);
    t39 = (t22 + 4);
    t40 = *((unsigned int *)t22);
    t41 = (~(t40));
    *((unsigned int *)t18) = t41;
    *((unsigned int *)t38) = 0;
    if (*((unsigned int *)t39) != 0)
        goto LAB9;

LAB8:    t46 = *((unsigned int *)t18);
    *((unsigned int *)t18) = (t46 & 1U);
    t47 = *((unsigned int *)t38);
    *((unsigned int *)t38) = (t47 & 1U);
    xsi_vlogtype_concat(t5, 2, 2, 2U, t18, 1, t9, 1);
    memset(t48, 0, 8);
    t49 = (t4 + 4);
    t50 = (t5 + 4);
    t51 = *((unsigned int *)t4);
    t52 = *((unsigned int *)t5);
    t53 = (t51 ^ t52);
    t54 = *((unsigned int *)t49);
    t55 = *((unsigned int *)t50);
    t56 = (t54 ^ t55);
    t57 = (t53 | t56);
    t58 = *((unsigned int *)t49);
    t59 = *((unsigned int *)t50);
    t60 = (t58 | t59);
    t61 = (~(t60));
    t62 = (t57 & t61);
    if (t62 != 0)
        goto LAB13;

LAB10:    if (t60 != 0)
        goto LAB12;

LAB11:    *((unsigned int *)t48) = 1;

LAB13:    t64 = (t0 + 6664);
    t65 = (t64 + 56U);
    t66 = *((char **)t65);
    t67 = (t66 + 56U);
    t68 = *((char **)t67);
    memset(t68, 0, 8);
    t69 = 1U;
    t70 = t69;
    t71 = (t48 + 4);
    t72 = *((unsigned int *)t48);
    t69 = (t69 & t72);
    t73 = *((unsigned int *)t71);
    t70 = (t70 & t73);
    t74 = (t68 + 4);
    t75 = *((unsigned int *)t68);
    *((unsigned int *)t68) = (t75 | t69);
    t76 = *((unsigned int *)t74);
    *((unsigned int *)t74) = (t76 | t70);
    xsi_driver_vfirst_trans(t64, 0, 0);
    t77 = (t0 + 6504);
    *((int *)t77) = 1;

LAB1:    return;
LAB4:    *((unsigned int *)t18) = 1;
    goto LAB7;

LAB9:    t42 = *((unsigned int *)t18);
    t43 = *((unsigned int *)t39);
    *((unsigned int *)t18) = (t42 | t43);
    t44 = *((unsigned int *)t38);
    t45 = *((unsigned int *)t39);
    *((unsigned int *)t38) = (t44 | t45);
    goto LAB8;

LAB12:    t63 = (t48 + 4);
    *((unsigned int *)t48) = 1;
    *((unsigned int *)t63) = 1;
    goto LAB13;

}

static void Cont_1971_3(char *t0)
{
    char t8[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t9;
    char *t10;
    unsigned int t11;
    unsigned int t12;
    unsigned int t13;
    unsigned int t14;
    unsigned int t15;
    unsigned int t16;
    unsigned int t17;
    unsigned int t18;
    unsigned int t19;
    unsigned int t20;
    unsigned int t21;
    unsigned int t22;
    char *t23;
    char *t24;
    char *t25;
    char *t26;
    char *t27;
    char *t28;
    unsigned int t29;
    unsigned int t30;
    char *t31;
    unsigned int t32;
    unsigned int t33;
    char *t34;
    unsigned int t35;
    unsigned int t36;
    char *t37;

LAB0:    t1 = (t0 + 5160U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(1971, ng0);
    t2 = (t0 + 3184);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 3344);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    memset(t8, 0, 8);
    t9 = (t4 + 4);
    t10 = (t7 + 4);
    t11 = *((unsigned int *)t4);
    t12 = *((unsigned int *)t7);
    t13 = (t11 ^ t12);
    t14 = *((unsigned int *)t9);
    t15 = *((unsigned int *)t10);
    t16 = (t14 ^ t15);
    t17 = (t13 | t16);
    t18 = *((unsigned int *)t9);
    t19 = *((unsigned int *)t10);
    t20 = (t18 | t19);
    t21 = (~(t20));
    t22 = (t17 & t21);
    if (t22 != 0)
        goto LAB7;

LAB4:    if (t20 != 0)
        goto LAB6;

LAB5:    *((unsigned int *)t8) = 1;

LAB7:    t24 = (t0 + 6728);
    t25 = (t24 + 56U);
    t26 = *((char **)t25);
    t27 = (t26 + 56U);
    t28 = *((char **)t27);
    memset(t28, 0, 8);
    t29 = 1U;
    t30 = t29;
    t31 = (t8 + 4);
    t32 = *((unsigned int *)t8);
    t29 = (t29 & t32);
    t33 = *((unsigned int *)t31);
    t30 = (t30 & t33);
    t34 = (t28 + 4);
    t35 = *((unsigned int *)t28);
    *((unsigned int *)t28) = (t35 | t29);
    t36 = *((unsigned int *)t34);
    *((unsigned int *)t34) = (t36 | t30);
    xsi_driver_vfirst_trans(t24, 0, 0);
    t37 = (t0 + 6520);
    *((int *)t37) = 1;

LAB1:    return;
LAB6:    t23 = (t8 + 4);
    *((unsigned int *)t8) = 1;
    *((unsigned int *)t23) = 1;
    goto LAB7;

}

static void Cont_1973_4(char *t0)
{
    char t3[8];
    char *t1;
    char *t2;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    unsigned int t13;
    char *t14;
    char *t15;
    char *t16;
    char *t17;
    char *t18;
    unsigned int t19;
    unsigned int t20;
    char *t21;
    unsigned int t22;
    unsigned int t23;
    char *t24;
    unsigned int t25;
    unsigned int t26;
    char *t27;

LAB0:    t1 = (t0 + 5408U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(1973, ng0);
    t2 = (t0 + 3184);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    memset(t3, 0, 8);
    t6 = (t3 + 4);
    t7 = (t5 + 4);
    t8 = *((unsigned int *)t5);
    t9 = (t8 >> 0);
    *((unsigned int *)t3) = t9;
    t10 = *((unsigned int *)t7);
    t11 = (t10 >> 0);
    *((unsigned int *)t6) = t11;
    t12 = *((unsigned int *)t3);
    *((unsigned int *)t3) = (t12 & 1U);
    t13 = *((unsigned int *)t6);
    *((unsigned int *)t6) = (t13 & 1U);
    t14 = (t0 + 6792);
    t15 = (t14 + 56U);
    t16 = *((char **)t15);
    t17 = (t16 + 56U);
    t18 = *((char **)t17);
    memset(t18, 0, 8);
    t19 = 1U;
    t20 = t19;
    t21 = (t3 + 4);
    t22 = *((unsigned int *)t3);
    t19 = (t19 & t22);
    t23 = *((unsigned int *)t21);
    t20 = (t20 & t23);
    t24 = (t18 + 4);
    t25 = *((unsigned int *)t18);
    *((unsigned int *)t18) = (t25 | t19);
    t26 = *((unsigned int *)t24);
    *((unsigned int *)t24) = (t26 | t20);
    xsi_driver_vfirst_trans(t14, 0, 0);
    t27 = (t0 + 6536);
    *((int *)t27) = 1;

LAB1:    return;
}

static void Cont_1974_5(char *t0)
{
    char t3[8];
    char *t1;
    char *t2;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    unsigned int t13;
    char *t14;
    char *t15;
    char *t16;
    char *t17;
    char *t18;
    unsigned int t19;
    unsigned int t20;
    char *t21;
    unsigned int t22;
    unsigned int t23;
    char *t24;
    unsigned int t25;
    unsigned int t26;
    char *t27;

LAB0:    t1 = (t0 + 5656U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(1974, ng0);
    t2 = (t0 + 3344);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    memset(t3, 0, 8);
    t6 = (t3 + 4);
    t7 = (t5 + 4);
    t8 = *((unsigned int *)t5);
    t9 = (t8 >> 0);
    *((unsigned int *)t3) = t9;
    t10 = *((unsigned int *)t7);
    t11 = (t10 >> 0);
    *((unsigned int *)t6) = t11;
    t12 = *((unsigned int *)t3);
    *((unsigned int *)t3) = (t12 & 1U);
    t13 = *((unsigned int *)t6);
    *((unsigned int *)t6) = (t13 & 1U);
    t14 = (t0 + 6856);
    t15 = (t14 + 56U);
    t16 = *((char **)t15);
    t17 = (t16 + 56U);
    t18 = *((char **)t17);
    memset(t18, 0, 8);
    t19 = 1U;
    t20 = t19;
    t21 = (t3 + 4);
    t22 = *((unsigned int *)t3);
    t19 = (t19 & t22);
    t23 = *((unsigned int *)t21);
    t20 = (t20 & t23);
    t24 = (t18 + 4);
    t25 = *((unsigned int *)t18);
    *((unsigned int *)t18) = (t25 | t19);
    t26 = *((unsigned int *)t24);
    *((unsigned int *)t24) = (t26 | t20);
    xsi_driver_vfirst_trans(t14, 0, 0);
    t27 = (t0 + 6552);
    *((int *)t27) = 1;

LAB1:    return;
}

static void Cont_1976_6(char *t0)
{
    char t5[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t6;
    char *t7;
    char *t8;
    char *t9;
    char *t10;
    char *t11;
    char *t12;
    char *t13;
    char *t14;
    char *t15;
    char *t16;
    char *t17;
    unsigned int t18;
    unsigned int t19;
    char *t20;
    unsigned int t21;
    unsigned int t22;
    char *t23;
    unsigned int t24;
    unsigned int t25;
    char *t26;

LAB0:    t1 = (t0 + 5904U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(1976, ng0);
    t2 = (t0 + 3024);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t6 = (t0 + 3024);
    t7 = (t6 + 72U);
    t8 = *((char **)t7);
    t9 = (t0 + 3024);
    t10 = (t9 + 64U);
    t11 = *((char **)t10);
    t12 = (t0 + 2624U);
    t13 = *((char **)t12);
    xsi_vlog_generic_get_array_select_value(t5, 3, t4, t8, t11, 2, 1, t13, 1, 2);
    t12 = (t0 + 6920);
    t14 = (t12 + 56U);
    t15 = *((char **)t14);
    t16 = (t15 + 56U);
    t17 = *((char **)t16);
    memset(t17, 0, 8);
    t18 = 7U;
    t19 = t18;
    t20 = (t5 + 4);
    t21 = *((unsigned int *)t5);
    t18 = (t18 & t21);
    t22 = *((unsigned int *)t20);
    t19 = (t19 & t22);
    t23 = (t17 + 4);
    t24 = *((unsigned int *)t17);
    *((unsigned int *)t17) = (t24 | t18);
    t25 = *((unsigned int *)t23);
    *((unsigned int *)t23) = (t25 | t19);
    xsi_driver_vfirst_trans(t12, 0, 2);
    t26 = (t0 + 6568);
    *((int *)t26) = 1;

LAB1:    return;
}

static void Always_1980_7(char *t0)
{
    char t4[8];
    char t21[8];
    char t22[8];
    char t54[8];
    char t85[8];
    char t86[8];
    char *t1;
    char *t2;
    char *t3;
    char *t5;
    char *t6;
    unsigned int t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    char *t12;
    char *t13;
    unsigned int t14;
    unsigned int t15;
    unsigned int t16;
    unsigned int t17;
    unsigned int t18;
    char *t19;
    char *t20;
    char *t23;
    char *t24;
    char *t25;
    char *t26;
    char *t27;
    char *t28;
    char *t29;
    char *t30;
    char *t31;
    int t32;
    char *t33;
    int t34;
    int t35;
    int t36;
    int t37;
    unsigned int t38;
    unsigned int t39;
    unsigned int t40;
    unsigned int t41;
    unsigned int t42;
    unsigned int t43;
    unsigned int t44;
    unsigned int t45;
    unsigned int t46;
    unsigned int t47;
    unsigned int t48;
    unsigned int t49;
    unsigned int t50;
    unsigned int t51;
    unsigned int t52;
    unsigned int t53;
    unsigned int t55;
    unsigned int t56;
    unsigned int t57;
    unsigned int t58;
    unsigned int t59;
    unsigned int t60;
    unsigned int t61;
    unsigned int t62;
    unsigned int t63;
    unsigned int t64;
    unsigned int t65;
    unsigned int t66;
    unsigned int t67;
    unsigned int t68;
    unsigned int t69;
    unsigned int t70;
    unsigned int t71;
    unsigned int t72;
    unsigned int t73;
    unsigned int t74;
    unsigned int t75;
    unsigned int t76;
    unsigned int t77;
    unsigned int t78;
    unsigned int t79;
    unsigned int t80;
    unsigned int t81;
    unsigned int t82;
    unsigned int t83;
    char *t84;
    char *t87;
    char *t88;
    char *t89;
    char *t90;
    char *t91;
    char *t92;
    char *t93;
    char *t94;
    unsigned int t95;
    char *t96;
    unsigned int t97;
    unsigned int t98;
    unsigned int t99;
    int t100;
    int t101;

LAB0:    t1 = (t0 + 6152U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(1980, ng0);
    t2 = (t0 + 6584);
    *((int *)t2) = 1;
    t3 = (t0 + 6184);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(1980, ng0);

LAB5:    xsi_set_current_line(1981, ng0);
    t5 = (t0 + 1344U);
    t6 = *((char **)t5);
    memset(t4, 0, 8);
    t5 = (t6 + 4);
    t7 = *((unsigned int *)t5);
    t8 = (~(t7));
    t9 = *((unsigned int *)t6);
    t10 = (t9 & t8);
    t11 = (t10 & 1U);
    if (t11 != 0)
        goto LAB9;

LAB7:    if (*((unsigned int *)t5) == 0)
        goto LAB6;

LAB8:    t12 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t12) = 1;

LAB9:    t13 = (t4 + 4);
    t14 = *((unsigned int *)t13);
    t15 = (~(t14));
    t16 = *((unsigned int *)t4);
    t17 = (t16 & t15);
    t18 = (t17 != 0);
    if (t18 > 0)
        goto LAB10;

LAB11:    xsi_set_current_line(1984, ng0);
    t2 = (t0 + 1824U);
    t3 = *((char **)t2);
    memset(t4, 0, 8);
    t2 = (t3 + 4);
    t7 = *((unsigned int *)t2);
    t8 = (~(t7));
    t9 = *((unsigned int *)t3);
    t10 = (t9 & t8);
    t11 = (t10 & 1U);
    if (t11 != 0)
        goto LAB18;

LAB19:    if (*((unsigned int *)t2) != 0)
        goto LAB20;

LAB21:    t6 = (t4 + 4);
    t14 = *((unsigned int *)t4);
    t15 = *((unsigned int *)t6);
    t16 = (t14 || t15);
    if (t16 > 0)
        goto LAB22;

LAB23:    memcpy(t54, t4, 8);

LAB24:    t31 = (t54 + 4);
    t79 = *((unsigned int *)t31);
    t80 = (~(t79));
    t81 = *((unsigned int *)t54);
    t82 = (t81 & t80);
    t83 = (t82 != 0);
    if (t83 > 0)
        goto LAB38;

LAB39:
LAB40:
LAB12:    goto LAB2;

LAB6:    *((unsigned int *)t4) = 1;
    goto LAB9;

LAB10:    xsi_set_current_line(1982, ng0);
    xsi_set_current_line(1982, ng0);
    t19 = ((char*)((ng3)));
    t20 = (t0 + 3504);
    xsi_vlogvar_assign_value(t20, t19, 0, 0, 32);

LAB13:    t2 = (t0 + 3504);
    t3 = (t2 + 56U);
    t5 = *((char **)t3);
    t6 = ((char*)((ng4)));
    memset(t4, 0, 8);
    xsi_vlog_signed_less(t4, 32, t5, 32, t6, 32);
    t12 = (t4 + 4);
    t7 = *((unsigned int *)t12);
    t8 = (~(t7));
    t9 = *((unsigned int *)t4);
    t10 = (t9 & t8);
    t11 = (t10 != 0);
    if (t11 > 0)
        goto LAB14;

LAB15:    goto LAB12;

LAB14:    xsi_set_current_line(1983, ng0);
    t13 = ((char*)((ng1)));
    t19 = (t0 + 3024);
    t20 = (t0 + 3024);
    t23 = (t20 + 72U);
    t24 = *((char **)t23);
    t25 = (t0 + 3024);
    t26 = (t25 + 64U);
    t27 = *((char **)t26);
    t28 = (t0 + 3504);
    t29 = (t28 + 56U);
    t30 = *((char **)t29);
    xsi_vlog_generic_convert_array_indices(t21, t22, t24, t27, 2, 1, t30, 32, 1);
    t31 = (t21 + 4);
    t14 = *((unsigned int *)t31);
    t32 = (!(t14));
    t33 = (t22 + 4);
    t15 = *((unsigned int *)t33);
    t34 = (!(t15));
    t35 = (t32 && t34);
    if (t35 == 1)
        goto LAB16;

LAB17:    xsi_set_current_line(1982, ng0);
    t2 = (t0 + 3504);
    t3 = (t2 + 56U);
    t5 = *((char **)t3);
    t6 = ((char*)((ng5)));
    memset(t4, 0, 8);
    xsi_vlog_signed_add(t4, 32, t5, 32, t6, 32);
    t12 = (t0 + 3504);
    xsi_vlogvar_assign_value(t12, t4, 0, 0, 32);
    goto LAB13;

LAB16:    t16 = *((unsigned int *)t21);
    t17 = *((unsigned int *)t22);
    t36 = (t16 - t17);
    t37 = (t36 + 1);
    xsi_vlogvar_wait_assign_value(t19, t13, 0, *((unsigned int *)t22), t37, 0LL);
    goto LAB17;

LAB18:    *((unsigned int *)t4) = 1;
    goto LAB21;

LAB20:    t5 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t5) = 1;
    goto LAB21;

LAB22:    t12 = (t0 + 1664U);
    t13 = *((char **)t12);
    memset(t21, 0, 8);
    t12 = (t13 + 4);
    t17 = *((unsigned int *)t12);
    t18 = (~(t17));
    t38 = *((unsigned int *)t13);
    t39 = (t38 & t18);
    t40 = (t39 & 1U);
    if (t40 != 0)
        goto LAB28;

LAB26:    if (*((unsigned int *)t12) == 0)
        goto LAB25;

LAB27:    t19 = (t21 + 4);
    *((unsigned int *)t21) = 1;
    *((unsigned int *)t19) = 1;

LAB28:    t20 = (t21 + 4);
    t23 = (t13 + 4);
    t41 = *((unsigned int *)t13);
    t42 = (~(t41));
    *((unsigned int *)t21) = t42;
    *((unsigned int *)t20) = 0;
    if (*((unsigned int *)t23) != 0)
        goto LAB30;

LAB29:    t47 = *((unsigned int *)t21);
    *((unsigned int *)t21) = (t47 & 1U);
    t48 = *((unsigned int *)t20);
    *((unsigned int *)t20) = (t48 & 1U);
    memset(t22, 0, 8);
    t24 = (t21 + 4);
    t49 = *((unsigned int *)t24);
    t50 = (~(t49));
    t51 = *((unsigned int *)t21);
    t52 = (t51 & t50);
    t53 = (t52 & 1U);
    if (t53 != 0)
        goto LAB31;

LAB32:    if (*((unsigned int *)t24) != 0)
        goto LAB33;

LAB34:    t55 = *((unsigned int *)t4);
    t56 = *((unsigned int *)t22);
    t57 = (t55 & t56);
    *((unsigned int *)t54) = t57;
    t26 = (t4 + 4);
    t27 = (t22 + 4);
    t28 = (t54 + 4);
    t58 = *((unsigned int *)t26);
    t59 = *((unsigned int *)t27);
    t60 = (t58 | t59);
    *((unsigned int *)t28) = t60;
    t61 = *((unsigned int *)t28);
    t62 = (t61 != 0);
    if (t62 == 1)
        goto LAB35;

LAB36:
LAB37:    goto LAB24;

LAB25:    *((unsigned int *)t21) = 1;
    goto LAB28;

LAB30:    t43 = *((unsigned int *)t21);
    t44 = *((unsigned int *)t23);
    *((unsigned int *)t21) = (t43 | t44);
    t45 = *((unsigned int *)t20);
    t46 = *((unsigned int *)t23);
    *((unsigned int *)t20) = (t45 | t46);
    goto LAB29;

LAB31:    *((unsigned int *)t22) = 1;
    goto LAB34;

LAB33:    t25 = (t22 + 4);
    *((unsigned int *)t22) = 1;
    *((unsigned int *)t25) = 1;
    goto LAB34;

LAB35:    t63 = *((unsigned int *)t54);
    t64 = *((unsigned int *)t28);
    *((unsigned int *)t54) = (t63 | t64);
    t29 = (t4 + 4);
    t30 = (t22 + 4);
    t65 = *((unsigned int *)t4);
    t66 = (~(t65));
    t67 = *((unsigned int *)t29);
    t68 = (~(t67));
    t69 = *((unsigned int *)t22);
    t70 = (~(t69));
    t71 = *((unsigned int *)t30);
    t72 = (~(t71));
    t32 = (t66 & t68);
    t34 = (t70 & t72);
    t73 = (~(t32));
    t74 = (~(t34));
    t75 = *((unsigned int *)t28);
    *((unsigned int *)t28) = (t75 & t73);
    t76 = *((unsigned int *)t28);
    *((unsigned int *)t28) = (t76 & t74);
    t77 = *((unsigned int *)t54);
    *((unsigned int *)t54) = (t77 & t73);
    t78 = *((unsigned int *)t54);
    *((unsigned int *)t54) = (t78 & t74);
    goto LAB37;

LAB38:    xsi_set_current_line(1985, ng0);
    t33 = (t0 + 1984U);
    t84 = *((char **)t33);
    t33 = (t0 + 3024);
    t87 = (t0 + 3024);
    t88 = (t87 + 72U);
    t89 = *((char **)t88);
    t90 = (t0 + 3024);
    t91 = (t90 + 64U);
    t92 = *((char **)t91);
    t93 = (t0 + 2464U);
    t94 = *((char **)t93);
    xsi_vlog_generic_convert_array_indices(t85, t86, t89, t92, 2, 1, t94, 1, 2);
    t93 = (t85 + 4);
    t95 = *((unsigned int *)t93);
    t35 = (!(t95));
    t96 = (t86 + 4);
    t97 = *((unsigned int *)t96);
    t36 = (!(t97));
    t37 = (t35 && t36);
    if (t37 == 1)
        goto LAB41;

LAB42:    goto LAB40;

LAB41:    t98 = *((unsigned int *)t85);
    t99 = *((unsigned int *)t86);
    t100 = (t98 - t99);
    t101 = (t100 + 1);
    xsi_vlogvar_wait_assign_value(t33, t84, 0, *((unsigned int *)t86), t101, 0LL);
    goto LAB42;

}


extern void work_m_06133083722522111560_1561687685_init()
{
	static char *pe[] = {(void *)Always_1956_0,(void *)Always_1963_1,(void *)Cont_1970_2,(void *)Cont_1971_3,(void *)Cont_1973_4,(void *)Cont_1974_5,(void *)Cont_1976_6,(void *)Always_1980_7};
	xsi_register_didat("work_m_06133083722522111560_1561687685", "isim/godson_system_isim_beh.exe.sim/work/m_06133083722522111560_1561687685.didat");
	xsi_register_executes(pe);
}
