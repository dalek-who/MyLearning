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

#include "xsi.h"

struct XSI_INFO xsi_info;



int main(int argc, char **argv)
{
    xsi_init_design(argc, argv);
    xsi_register_info(&xsi_info);

    xsi_register_min_prec_unit(-12);
    work_m_06842555750040026683_0665948728_init();
    work_m_02143227632935048185_2254830173_init();
    work_m_02672789926979074723_3887227907_init();
    work_m_02672789926979074723_1628674717_init();
    work_m_16096243677323079411_3084355262_init();
    work_m_15884042791194558190_4170573237_init();
    work_m_13809713708083004854_4234605723_init();
    work_m_01205504959372241360_1912645699_init();
    work_m_01205504959372241360_0203252145_init();
    work_m_17718732068231413060_2022223078_init();
    work_m_03687503264717331371_0327939278_init();
    work_m_02454618349311972712_0711788638_init();
    work_m_06433168239672479302_3043265852_init();
    work_m_10552451782256175338_1313653667_init();
    work_m_09425209536556143076_2104339246_init();
    work_m_06133083722522111560_1561687685_init();
    work_m_13550519477550117374_3850160569_init();
    work_m_04701056300534676226_0574448557_init();
    work_m_10056388006021355773_4126959076_init();
    work_m_16775656459221331237_4252231333_init();
    work_m_07496485832509889747_1664210878_init();
    xilinxcorelib_ver_m_04284627112054182733_3031158655_init();
    xilinxcorelib_ver_m_18166792875774041790_2239079712_init();
    xilinxcorelib_ver_m_17738287534884592592_3654217355_init();
    xilinxcorelib_ver_m_06058912016591365051_3398800325_init();
    work_m_14056882636803624207_4192283001_init();
    work_m_02777253650226011439_1191488480_init();
    work_m_16541823861846354283_2073120511_init();


    xsi_register_tops("work_m_02777253650226011439_1191488480");
    xsi_register_tops("work_m_16541823861846354283_2073120511");


    return xsi_run_simulation(argc, argv);

}
