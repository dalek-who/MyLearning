`timescale 1ns/10ps

`define XILINX


/*Initial encoding*/
`define Lgid  8  //
`define Lnid  5  //Maximum node supported: 2**Lnid, 12 bit id=3(intra-node id)+4(intra-ip id)+5(inter-node id)
`define Lgpio 16  //Number of GPIOs

`define Lconfbus      10
`define Lconfret       9
`define Lconfbusreg   64
`define Lconfbusaddr  16

`define INIT_PAD1V8_CTRL 32'H00000f80
`define INIT_PAD2V5_CTRL 32'H00000780
`define INIT_PAD3V3_CTRL 32'H00000780
`define INIT_CORE_CTRL   64'H00000007fffff617

//NORMAL CONFIG
`define CBUS_CONFSIGNAL         16'h0400
`define CBUS_SDCTRL0            16'h0410
`define CBUS_SDCTRL1            16'h0414
`define SHUT_CTRL               16'h0420
`define MISC_ADDR               16'h0424

//IPI 
`define CBUS_CORE0_IPISR        16'h1000
`define CBUS_CORE0_IPIEN        16'h1004
`define CBUS_CORE0_IPISET       16'h1008
`define CBUS_CORE0_IPICLR       16'h100c
`define CBUS_CORE0_BUF0         16'h1020
`define CBUS_CORE0_BUF1         16'h1028
`define CBUS_CORE0_BUF2         16'h1030
`define CBUS_CORE0_BUF3         16'h1038

`define CBUS_INTISR0            16'h1040
`define CBUS_INTIEN0            16'h1044
`define CBUS_INTSET0            16'h1048
`define CBUS_INTCLR0            16'h104c
`define CBUS_INTPOL0            16'h1050
`define CBUS_INTEDGE0           16'h1054

`define CBUS_INTISR1            16'h1058
`define CBUS_INTIEN1            16'h105c
`define CBUS_INTSET1            16'h1060
`define CBUS_INTCLR1            16'h1064
`define CBUS_INTPOL1            16'h1068
`define CBUS_INTEDGE1           16'h106c

`define CBUS_INTISR2            16'h1070
`define CBUS_INTIEN2            16'h1074
`define CBUS_INTSET2            16'h1078
`define CBUS_INTCLR2            16'h107c
`define CBUS_INTPOL2            16'h1080
`define CBUS_INTEDGE2           16'h1084

`define CBUS_INTISR3            16'h1088
`define CBUS_INTIEN3            16'h108c
`define CBUS_INTSET3            16'h1090
`define CBUS_INTCLR3            16'h1094
`define CBUS_INTPOL3            16'h1098
`define CBUS_INTEDGE3           16'h109c

`define CBUS_INTISR4            16'h10a0
`define CBUS_INTIEN4            16'h10a4
`define CBUS_INTSET4            16'h10a8
`define CBUS_INTCLR4            16'h10ac
`define CBUS_INTPOL4            16'h10b0
`define CBUS_INTEDGE4           16'h10b4

`define CBUS_GPIOCFG0           16'h10c0
`define CBUS_GPIOCFG1           16'h10c4
`define CBUS_GPIOCFG2           16'h10c8
`define CBUS_GPIOCFG3           16'h10cc

`define CBUS_GPIOOE0            16'h10d0
`define CBUS_GPIOOE1            16'h10d4
`define CBUS_GPIOOE2            16'h10d8
`define CBUS_GPIOOE3            16'h10dc

`define CBUS_GPIOIN0            16'h10e0
`define CBUS_GPIOIN1            16'h10e4
`define CBUS_GPIOIN2            16'h10e8
`define CBUS_GPIOIN3            16'h10ec

`define CBUS_GPIOOUT0           16'h10f0
`define CBUS_GPIOOUT1           16'h10f4
`define CBUS_GPIOOUT2           16'h10f8
`define CBUS_GPIOOUT3           16'h10fc

`define CBUS_FIRST0             16'h11c0
`define CBUS_FIRST1             16'h11c4
`define CBUS_FIRST2             16'h11c8
`define CBUS_FIRST3             16'h11cc

`define CBUS_SECOND0            16'h11d0
`define CBUS_SECOND1            16'h11d4
`define CBUS_SECOND2            16'h11d8
`define CBUS_SECOND3            16'h11dc

`define CBUS_THIRD0             16'h11e0
`define CBUS_THIRD1             16'h11e4
`define CBUS_THIRD2             16'h11e8
`define CBUS_THIRD3             16'h11ec

`define CBUS_FOURTH0            16'h11f0
`define CBUS_FOURTH1            16'h11f4
`define CBUS_FOURTH2            16'h11f8
`define CBUS_FOURTH3            16'h11fc

`define ORDER_REG_ADDR          16'h1160


`define INIT_CONFSIGNAL         64'hffff_fff0
`define INIT_PLLCTRL            64'h8000_0080_0014_38a3
`define INIT_PCI_HIT0_SEL       64'h7fff_ffff_ffe0_0004
`define INIT_PCI_HIT1_SEL       64'hffff_ffff_ff00_0004
`define INIT_PCI_HIT2_SEL       64'hffff_ffff_c000_000c
`define SHUT_INIT               32'h0000_0000
`define MISC_INIT               32'h0000_0004

`define GPIO_CFG0               32'hffe00040 // NAND_D0-D7 sys config
`define GPIO_CFG1               32'hfc003f3f // UART0_RX UART0_TX
//`define GPIO_CFG2               32'h1ffc3fff // SPI0 
`define GPIO_CFG2               32'h1ff03fff // SPI0 
`define GPIO_CFG3               9'h0

`define GPIO_OE0                32'hffe00040
`define GPIO_OE1                32'hfc003f3f
`define GPIO_OE2                32'h1ff03fff
`define GPIO_OE3                9'h0


/*****************end windows config***********************/

`define Lawcmd 4
`define Lawdirqid 4
`define Lawstate 2
`define Lawscseti 2
`define Lawid 8
//`define Lawid 12
`define Lawaddr 32 
`define Lawlen 4
`define Lawsize 3
`define Lawburst 2
`define Lawlock 2
`define Lawcache 4
`define Lawprot 3
`define Lawvalid 1
`define Lawready 1
`define Lwid 8
//`define Lwid 12
`define Lwdata 32 
//`define Lwdata 128
`define Lwstrb 4
//`define Lwstrb 16
`define Lwlast 1
`define Lwvalid 1
`define Lwready 1
`define Lbid 8
//`define Lbid 12
`define Lbresp 2
`define Lbvalid 1
`define Lbready 1
`define Larcmd 4
`define Larcpuno 10
`define Larid 8
//`define Larid 12
`define Laraddr 32
`define Larlen 4
`define Larsize 3
`define Larburst 2
`define Larlock 2
`define Larcache 4
`define Larprot 3
`define Larvalid 1
`define Larready 1
`define Lrstate 2
`define Lrscseti 2
`define Lrid 8
//`define Lrid 12
`define Lrdata 32
//`define Lrdata 128
`define Lrresp 2
`define Lrlast 1
`define Lrvalid 1
`define Lrready 1
`define Lrrequest 1
/*************************/

`define LID 8
`define LADDR 32
`define LLEN 4
`define LSIZE 3
`define LDATA 32
`define LSTRB 4
`define LBURST 2
`define LLOCK 2
`define LCACHE 4
`define LPROT 3
`define LRESP 2
/************************************/
//AXI fields encoding, for PCI_LPC
`define AR_DMAWRITE 4'b1011
`define AW_DMAWRITE 4'b1011

/******** For Test: MKL add *********/
//`define Lscan_axi_left 5
`define Lscan_usb    5
`define Lscan_sata   5
`define Lscan_gmac   5

`define Lscan_cpu    8
`define Lscan_ddr2   6
`define Lscan_pci    6
`define Lscan_xbar   6
`define Lscan_gpudc 12
/***** Test variable define end *****/

//INIT BASE ADDRESS
`define CBUS_CPU_WIN0_BASE      16'h0000
`define CBUS_CPU_WIN1_BASE      16'h0008
`define CBUS_CPU_WIN2_BASE      16'h0010
`define CBUS_CPU_WIN3_BASE      16'h0018
`define CBUS_CPU_WIN4_BASE      16'h0020
`define CBUS_CPU_WIN5_BASE      16'h0028
`define CBUS_CPU_WIN6_BASE      16'h0030
`define CBUS_CPU_WIN7_BASE      16'h0038

`define CBUS_CPU_WIN0_MASK      16'h0040
`define CBUS_CPU_WIN1_MASK      16'h0048
`define CBUS_CPU_WIN2_MASK      16'h0050
`define CBUS_CPU_WIN3_MASK      16'h0058
`define CBUS_CPU_WIN4_MASK      16'h0060
`define CBUS_CPU_WIN5_MASK      16'h0068
`define CBUS_CPU_WIN6_MASK      16'h0070
`define CBUS_CPU_WIN7_MASK      16'h0078

`define CBUS_CPU_WIN0_MMAP      16'h0080
`define CBUS_CPU_WIN1_MMAP      16'h0088
`define CBUS_CPU_WIN2_MMAP      16'h0090
`define CBUS_CPU_WIN3_MMAP      16'h0098
`define CBUS_CPU_WIN4_MMAP      16'h00a0
`define CBUS_CPU_WIN5_MMAP      16'h00a8
`define CBUS_CPU_WIN6_MMAP      16'h00b0
`define CBUS_CPU_WIN7_MMAP      16'h00b8

//INIT VALUE
`define INIT_CPU_WIN0_BASE      64'h0000_0000 //sdram  0000_0000 0fff_ffff 256MB
`define INIT_CPU_WIN1_BASE      64'h1fc0_0000 //boot   
`define INIT_CPU_WIN2_BASE      64'h1c30_0000 //dc     1c30_0000 1c3f_ffff 1MB 
`define INIT_CPU_WIN3_BASE      64'h1f00_0000 //AXIMUX 1f00_0000 1fff_ffff 16MB
`define INIT_CPU_WIN4_BASE      64'h1c28_0000 //CAMERA 1c28_0000 1c2f_ffff 512KB
`define INIT_CPU_WIN5_BASE      64'h1d00_0000 //SPI0-M 1d
`define INIT_CPU_WIN6_BASE      64'h1e00_0000 //SPI1-M 1e
`define INIT_CPU_WIN7_BASE      64'h0000_0000 //default sink

`define INIT_CPU_WIN0_MASK      64'hffff_ffff_f000_0000
`define INIT_CPU_WIN1_MASK      64'hffff_ffff_fff0_0000
`define INIT_CPU_WIN2_MASK      64'hffff_ffff_fff0_0000
`define INIT_CPU_WIN3_MASK      64'hffff_ffff_ff00_0000
`define INIT_CPU_WIN4_MASK      64'hffff_ffff_fff8_0000
`define INIT_CPU_WIN5_MASK      64'hffff_ffff_ff00_0000
`define INIT_CPU_WIN6_MASK      64'hffff_ffff_ff00_0000
`define INIT_CPU_WIN7_MASK      64'h0000_0000 // default sink

`define INIT_CPU_WIN0_MMAP      64'h0000_00f0
`define INIT_CPU_WIN1_MMAP      64'h1fc0_00f2
`define INIT_CPU_WIN2_MMAP      64'h1c30_0081
`define INIT_CPU_WIN3_MMAP      64'h1f00_0082
`define INIT_CPU_WIN4_MMAP      64'h1c28_0083
`define INIT_CPU_WIN5_MMAP      64'h1d00_0082
`define INIT_CPU_WIN6_MMAP      64'h1e00_0082
`define INIT_CPU_WIN7_MMAP      64'h0000_00f0

//  test add
`define  Ldc_bist_fail 4

