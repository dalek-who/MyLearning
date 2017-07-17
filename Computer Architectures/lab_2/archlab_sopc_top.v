`include "config.h"

//`define HAS_DDR3

module archlab_sopc_top(
    input         resetn, 
    input         clk,

    //------LED------
    output [15:0] LED,
    output [7 :0] NUM_CSn,
    output [7 :0] NUM_A_G,
    input  [4:0] KEY_in,//接线用

    //-------open this when add DDR3 module
    /*//------DDR3 interface------
    inout  [15:0] mcb1_dram_dq,
    output [12:0] mcb1_dram_a,
    output [2 :0] mcb1_dram_ba,
    output        mcb1_dram_ras_n,
    output        mcb1_dram_cas_n,
    output        mcb1_dram_we_n,
    output        mcb1_dram_odt,
    output        mcb1_dram_reset_n,
    output        mcb1_dram_cke,
    output        mcb1_dram_dm,
    inout         mcb1_dram_udqs,
    inout         mcb1_dram_udqs_n,
    inout         mcb1_rzq,
    inout         mcb1_zio,
    output        mcb1_dram_udm,
    inout         mcb1_dram_dqs,
    inout         mcb1_dram_dqs_n,
    output        mcb1_dram_ck,
    output        mcb1_dram_ck_n,
    */

    //-------open this when add MAC module
    /*//------mac interface-------
    output        phy_resetn,
    // Tx
    input         mtxclk_0,  // Transmit clock (from PHY)
    output [3 :0] mtxd_0,    // Transmit nibble (to PHY)
    output        mtxen_0,   // Transmit enable (to PHY)
    output        mtxerr_0,  // Transmit error (to PHY)
    // Rx
    input         mrxclk_0,  // Receive clock (from PHY)
    input  [3 :0] mrxd_0,    // Receive nibble (from PHY)
    input         mrxdv_0,   // Receive data valid (from PHY)
    input         mrxerr_0,  // Receive data error (from PHY)
    // Common Tx and Rx
    input         mcoll_0,   // Collision (from PHY)
    input         mcrs_0,    // Carrier sense (from PHY)
    // MII Management interface
    output        mdc_0,     // MII Management data clock (to PHY)
    inout         mdio_0,    // MII data i/o
    */

    //------uart interface------
	
    //------spi interface------
    output         SPI_CLK,
    output         SPI_CS,
    inout          SPI_MISO,
    inout          SPI_MOSI
);
wire        aclk;
reg         aresetn;

//CPU(master) AXI interface 
wire [`LID         -1 :0] m0_awid;
wire [`Lawaddr     -1 :0] m0_awaddr;
wire [`Lawlen      -1 :0] m0_awlen;
wire [`Lawsize     -1 :0] m0_awsize;
wire [`Lawburst    -1 :0] m0_awburst;
wire [`Lawlock     -1 :0] m0_awlock;
wire [`Lawcache    -1 :0] m0_awcache;
wire [`Lawprot     -1 :0] m0_awprot;
wire                      m0_awvalid;
wire                      m0_awready;
wire [`LID         -1 :0] m0_wid;
wire [`Lwdata      -1 :0] m0_wdata;
wire [`Lwstrb      -1 :0] m0_wstrb;
wire                      m0_wlast;
wire                      m0_wvalid;
wire                      m0_wready;
wire [`LID         -1 :0] m0_bid;
wire [`Lbresp      -1 :0] m0_bresp;
wire                      m0_bvalid;
wire                      m0_bready;
wire [`LID         -1 :0] m0_arid;
wire [`Laraddr     -1 :0] m0_araddr;
wire [`Larlen      -1 :0] m0_arlen;
wire [`Larsize     -1 :0] m0_arsize;
wire [`Larburst    -1 :0] m0_arburst;
wire [`Larlock     -1 :0] m0_arlock;
wire [`Larcache    -1 :0] m0_arcache;
wire [`Larprot     -1 :0] m0_arprot;
wire                      m0_arvalid;
wire                      m0_arready;
wire [`LID         -1 :0] m0_rid;
wire [`Lrdata      -1 :0] m0_rdata;
wire [`Lrresp      -1 :0] m0_rresp;
wire                      m0_rlast;
wire                      m0_rvalid;
wire                      m0_rready;

//SPI(slave) AXI interface 
wire [`LID         -1 :0] spi_s_awid;
wire [`Lawaddr     -1 :0] spi_s_awaddr;
wire [`Lawlen      -1 :0] spi_s_awlen;
wire [`Lawsize     -1 :0] spi_s_awsize;
wire [`Lawburst    -1 :0] spi_s_awburst;
wire [`Lawlock     -1 :0] spi_s_awlock;
wire [`Lawcache    -1 :0] spi_s_awcache;
wire [`Lawprot     -1 :0] spi_s_awprot;
wire                      spi_s_awvalid;
wire                      spi_s_awready;
wire [`LID         -1 :0] spi_s_wid;
wire [`Lwdata      -1 :0] spi_s_wdata;
wire [`Lwstrb      -1 :0] spi_s_wstrb;
wire                      spi_s_wlast;
wire                      spi_s_wvalid;
wire                      spi_s_wready;
wire [`LID         -1 :0] spi_s_bid;
wire [`Lbresp      -1 :0] spi_s_bresp;
wire                      spi_s_bvalid;
wire                      spi_s_bready;
wire [`LID         -1 :0] spi_s_arid;
wire [`Laraddr     -1 :0] spi_s_araddr;
wire [`Larlen      -1 :0] spi_s_arlen;
wire [`Larsize     -1 :0] spi_s_arsize;
wire [`Larburst    -1 :0] spi_s_arburst;
wire [`Larlock     -1 :0] spi_s_arlock;
wire [`Larcache    -1 :0] spi_s_arcache;
wire [`Larprot     -1 :0] spi_s_arprot;
wire                      spi_s_arvalid;
wire                      spi_s_arready;
wire [`LID         -1 :0] spi_s_rid;
wire [`Lrdata      -1 :0] spi_s_rdata;
wire [`Lrresp      -1 :0] spi_s_rresp;
wire                      spi_s_rlast;
wire                      spi_s_rvalid;
wire                      spi_s_rready;

//conf(slave) AXI interface 
wire [`LID         -1 :0] conf_s_awid;
wire [`Lawaddr     -1 :0] conf_s_awaddr;
wire [`Lawlen      -1 :0] conf_s_awlen;
wire [`Lawsize     -1 :0] conf_s_awsize;
wire [`Lawburst    -1 :0] conf_s_awburst;
wire [`Lawlock     -1 :0] conf_s_awlock;
wire [`Lawcache    -1 :0] conf_s_awcache;
wire [`Lawprot     -1 :0] conf_s_awprot;
wire                      conf_s_awvalid;
wire                      conf_s_awready;
wire [`LID         -1 :0] conf_s_wid;
wire [`Lwdata      -1 :0] conf_s_wdata;
wire [`Lwstrb      -1 :0] conf_s_wstrb;
wire                      conf_s_wlast;
wire                      conf_s_wvalid;
wire                      conf_s_wready;
wire [`LID         -1 :0] conf_s_bid;
wire [`Lbresp      -1 :0] conf_s_bresp;
wire                      conf_s_bvalid;
wire                      conf_s_bready;
wire [`LID         -1 :0] conf_s_arid;
wire [`Laraddr     -1 :0] conf_s_araddr;
wire [`Larlen      -1 :0] conf_s_arlen;
wire [`Larsize     -1 :0] conf_s_arsize;
wire [`Larburst    -1 :0] conf_s_arburst;
wire [`Larlock     -1 :0] conf_s_arlock;
wire [`Larcache    -1 :0] conf_s_arcache;
wire [`Larprot     -1 :0] conf_s_arprot;
wire                      conf_s_arvalid;
wire                      conf_s_arready;
wire [`LID         -1 :0] conf_s_rid;
wire [`Lrdata      -1 :0] conf_s_rdata;
wire [`Lrresp      -1 :0] conf_s_rresp;
wire                      conf_s_rlast;
wire                      conf_s_rvalid;
wire                      conf_s_rready;

//INST SRAM: 0xbfff_8000 ~ 0xbfff_ffff
wire [3 :0] inst_sram_cen;
wire        inst_sram_wr;
wire [31:0] inst_sram_addr;
wire [31:0] inst_sram_wdata;
wire        inst_sram_ack  = 1'b1;
wire        inst_sram_rrdy =1'b1;
wire [31:0] inst_sram_rdata;

//DATA SRAM: 0xbfff_0000 ~ 0xbfff_7fff
wire [3 :0] data_sram_cen;
wire        data_sram_wr;
wire [31:0] data_sram_addr;
wire [31:0] data_sram_wdata;
wire        data_sram_ack  = 1'b1;
wire        data_sram_rrdy = 1'b1;
wire [31:0] data_sram_rdata;
// CPU implementation  no EJTAG
//interrupt
wire int_key=cr05[4]|cr05[3]|cr05[2]|cr05[0] ;
wire [5:0]int_out = {3'b0,spi_inta_o,1'b0,int_key};
wire [5:0]int_n_i = ~int_out;

// CPU IP
ls132r_top ls132r(
    .int_n_i          (int_n_i     ),
    .sleeping_o       (            ),
    .aclk             (aclk        ),
    .areset_n         (aresetn     ),
    .arid             (m0_arid[3:0]),
    .araddr           (m0_araddr   ),
    .arlen            (m0_arlen    ),
    .arsize           (m0_arsize   ),
    .arburst          (m0_arburst  ),
    .arlock           (m0_arlock   ),
    .arcache          (m0_arcache  ),
    .arprot           (m0_arprot   ),
    .arvalid          (m0_arvalid  ),
    .arready          (m0_arready  ),
    .rid              (m0_rid[3:0] ),
    .rdata            (m0_rdata    ),
    .rresp            (m0_rresp    ),
    .rlast            (m0_rlast    ),
    .rvalid           (m0_rvalid   ),
    .rready           (m0_rready   ),
    .awid             (m0_awid[3:0]),
    .awaddr           (m0_awaddr   ),
    .awlen            (m0_awlen    ),
    .awsize           (m0_awsize   ),
    .awburst          (m0_awburst  ),
    .awlock           (m0_awlock   ),
    .awcache          (m0_awcache  ),
    .awprot           (m0_awprot   ),
    .awvalid          (m0_awvalid  ),
    .awready          (m0_awready  ),
    .wid              (m0_wid[3:0] ),
    .wdata            (m0_wdata    ),
    .wstrb            (m0_wstrb    ),
    .wlast            (m0_wlast    ),
    .wvalid           (m0_wvalid   ),
    .wready           (m0_wready   ),
    .bid              (m0_bid[3:0] ),
    .bresp            (m0_bresp    ),
    .bvalid           (m0_bvalid   ),
    .bready           (m0_bready   ), 

    .inst_sram_cen    (inst_sram_cen  ),
    .inst_sram_wr     (inst_sram_wr   ),
    .inst_sram_addr   (inst_sram_addr ),
    .inst_sram_wdata  (inst_sram_wdata),
    .inst_sram_ack    (inst_sram_ack  ),
    .inst_sram_rrdy   (inst_sram_rrdy ),
    .inst_sram_rdata  (inst_sram_rdata),
    
    .data_sram_cen    (data_sram_cen  ),
    .data_sram_wr     (data_sram_wr   ),
    .data_sram_addr   (data_sram_addr ),
    .data_sram_wdata  (data_sram_wdata),
    .data_sram_ack    (data_sram_ack  ),
    .data_sram_rrdy   (data_sram_rrdy ),
    .data_sram_rdata  (data_sram_rdata)
);

// AXI_MUX implementation
//m0: CPU IP
//s0: DDR3 slave
//s1: SPI  slave
//s2: axi2apb slave
//s3: confreg slave
//s4: mac slave
axi_slave_mux AA_axi_slave_mux(
    .axi_s_aresetn     (aresetn        ),
    
    .axi_s_awid        (m0_awid        ),
    .axi_s_awaddr      (m0_awaddr      ),
    .axi_s_awlen       (m0_awlen       ),
    .axi_s_awsize      (m0_awsize      ),
    .axi_s_awburst     (m0_awburst     ),
    .axi_s_awlock      (m0_awlock      ),
    .axi_s_awcache     (m0_awcache     ),
    .axi_s_awprot      (m0_awprot      ),
    .axi_s_awvalid     (m0_awvalid     ),
    .axi_s_awready     (m0_awready     ),
    .axi_s_wready      (m0_wready      ),
    .axi_s_wid         (m0_wid         ),
    .axi_s_wdata       (m0_wdata       ),
    .axi_s_wstrb       (m0_wstrb       ),
    .axi_s_wlast       (m0_wlast       ),
    .axi_s_wvalid      (m0_wvalid      ),
    .axi_s_bid         (m0_bid         ),
    .axi_s_bresp       (m0_bresp       ),
    .axi_s_bvalid      (m0_bvalid      ),
    .axi_s_bready      (m0_bready      ),
    .axi_s_arid        (m0_arid        ),
    .axi_s_araddr      (m0_araddr      ),
    .axi_s_arlen       (m0_arlen       ),
    .axi_s_arsize      (m0_arsize      ),
    .axi_s_arburst     (m0_arburst     ),
    .axi_s_arlock      (m0_arlock      ),
    .axi_s_arcache     (m0_arcache     ),
    .axi_s_arprot      (m0_arprot      ),
    .axi_s_arvalid     (m0_arvalid     ),
    .axi_s_arready     (m0_arready     ),
    .axi_s_rready      (m0_rready      ),
    .axi_s_rid         (m0_rid         ),
    .axi_s_rdata       (m0_rdata       ),
    .axi_s_rresp       (m0_rresp       ),
    .axi_s_rlast       (m0_rlast       ),
    .axi_s_rvalid      (m0_rvalid      ),
    
    .s0_awid           (       ),
    .s0_awaddr         (       ),
    .s0_awlen          (       ),
    .s0_awsize         (       ),
    .s0_awburst        (       ),
    .s0_awlock         (       ),
    .s0_awcache        (       ),
    .s0_awprot         (       ),
    .s0_awvalid        (       ),
    .s0_awready        ( 'd1   ),
    .s0_wid            (       ),
    .s0_wdata          (       ),
    .s0_wstrb          (       ),
    .s0_wlast          (       ),
    .s0_wvalid         (       ),
    .s0_wready         ( 'd1   ),
    .s0_bid            ( 'd0   ),
    .s0_bresp          ( 'd0   ),
    .s0_bvalid         ( 'd0   ),
    .s0_bready         (       ),
    .s0_arid           (       ),
    .s0_araddr         (       ),
    .s0_arlen          (       ),
    .s0_arsize         (       ),
    .s0_arburst        (       ),
    .s0_arlock         (       ),
    .s0_arcache        (       ),
    .s0_arprot         (       ),
    .s0_arvalid        (       ),
    .s0_arready        ( 'd1   ),
    .s0_rid            ( 'd0   ),
    .s0_rdata          ( 'd0   ),
    .s0_rresp          ( 'd0   ),
    .s0_rlast          ( 'd1   ),
    .s0_rvalid         ( 'd0   ),
    .s0_rready         (       ),
    
    .s1_awid           (spi_s_awid          ),
    .s1_awaddr         (spi_s_awaddr        ),
    .s1_awlen          (spi_s_awlen         ),
    .s1_awsize         (spi_s_awsize        ),
    .s1_awburst        (spi_s_awburst       ),
    .s1_awlock         (spi_s_awlock        ),
    .s1_awcache        (spi_s_awcache       ),
    .s1_awprot         (spi_s_awprot        ),
    .s1_awvalid        (spi_s_awvalid       ),
    .s1_awready        (spi_s_awready       ),
    .s1_wid            (spi_s_wid           ),
    .s1_wdata          (spi_s_wdata         ),
    .s1_wstrb          (spi_s_wstrb         ),
    .s1_wlast          (spi_s_wlast         ),
    .s1_wvalid         (spi_s_wvalid        ),
    .s1_wready         (spi_s_wready        ),
    .s1_bid            (spi_s_bid           ),
    .s1_bresp          (spi_s_bresp         ),
    .s1_bvalid         (spi_s_bvalid        ),
    .s1_bready         (spi_s_bready        ),
    .s1_arid           (spi_s_arid          ),
    .s1_araddr         (spi_s_araddr        ),
    .s1_arlen          (spi_s_arlen         ),
    .s1_arsize         (spi_s_arsize        ),
    .s1_arburst        (spi_s_arburst       ),
    .s1_arlock         (spi_s_arlock        ),
    .s1_arcache        (spi_s_arcache       ),
    .s1_arprot         (spi_s_arprot        ),
    .s1_arvalid        (spi_s_arvalid       ),
    .s1_arready        (spi_s_arready       ),
    .s1_rid            (spi_s_rid           ),
    .s1_rdata          (spi_s_rdata         ),
    .s1_rresp          (spi_s_rresp         ),
    .s1_rlast          (spi_s_rlast         ),
    .s1_rvalid         (spi_s_rvalid        ),
    .s1_rready         (spi_s_rready        ),
    
    .s2_awid           (     ),
    .s2_awaddr         (     ),
    .s2_awlen          (     ),
    .s2_awsize         (     ),
    .s2_awburst        (     ),
    .s2_awlock         (     ),
    .s2_awcache        (     ),
    .s2_awprot         (     ),
    .s2_awvalid        (     ),
    .s2_awready        ( 'd1 ),
    .s2_wid            (     ),
    .s2_wdata          (     ),
    .s2_wstrb          (     ),
    .s2_wlast          (     ),
    .s2_wvalid         (     ),
    .s2_wready         ( 'd1 ),
    .s2_bid            ( 'd0 ),
    .s2_bresp          ( 'd0 ),
    .s2_bvalid         ( 'd0 ),
    .s2_bready         (     ),
    .s2_arid           (     ),
    .s2_araddr         (     ),
    .s2_arlen          (     ),
    .s2_arsize         (     ),
    .s2_arburst        (     ),
    .s2_arlock         (     ),
    .s2_arcache        (     ),
    .s2_arprot         (     ),
    .s2_arvalid        (     ),
    .s2_arready        ( 'd1 ),
    .s2_rid            ( 'd0 ),
    .s2_rdata          ( 'd0 ),
    .s2_rresp          ( 'd0 ),
    .s2_rlast          ( 'd1 ),
    .s2_rvalid         ( 'd0 ),
    .s2_rready         (     ),
    
    .s3_awid           (conf_s_awid         ),
    .s3_awaddr         (conf_s_awaddr       ),
    .s3_awlen          (conf_s_awlen        ),
    .s3_awsize         (conf_s_awsize       ),
    .s3_awburst        (conf_s_awburst      ),
    .s3_awlock         (conf_s_awlock       ),
    .s3_awcache        (conf_s_awcache      ),
    .s3_awprot         (conf_s_awprot       ),
    .s3_awvalid        (conf_s_awvalid      ),
    .s3_awready        (conf_s_awready      ),
    .s3_wid            (conf_s_wid          ),
    .s3_wdata          (conf_s_wdata        ),
    .s3_wstrb          (conf_s_wstrb        ),
    .s3_wlast          (conf_s_wlast        ),
    .s3_wvalid         (conf_s_wvalid       ),
    .s3_wready         (conf_s_wready       ),
    .s3_bid            (conf_s_bid          ),
    .s3_bresp          (conf_s_bresp        ),
    .s3_bvalid         (conf_s_bvalid       ),
    .s3_bready         (conf_s_bready       ),
    .s3_arid           (conf_s_arid         ),
    .s3_araddr         (conf_s_araddr       ),
    .s3_arlen          (conf_s_arlen        ),
    .s3_arsize         (conf_s_arsize       ),
    .s3_arburst        (conf_s_arburst      ),
    .s3_arlock         (conf_s_arlock       ),
    .s3_arcache        (conf_s_arcache      ),
    .s3_arprot         (conf_s_arprot       ),
    .s3_arvalid        (conf_s_arvalid      ),
    .s3_arready        (conf_s_arready      ),
    .s3_rid            (conf_s_rid          ),
    .s3_rdata          (conf_s_rdata        ),
    .s3_rresp          (conf_s_rresp        ),
    .s3_rlast          (conf_s_rlast        ),
    .s3_rvalid         (conf_s_rvalid       ),
    .s3_rready         (conf_s_rready       ),
    
    .s4_awid           (     ),
    .s4_awaddr         (     ),
    .s4_awlen          (     ),
    .s4_awsize         (     ),
    .s4_awburst        (     ),
    .s4_awlock         (     ),
    .s4_awcache        (     ),
    .s4_awprot         (     ),
    .s4_awvalid        (     ),
    .s4_awready        ( 'd1 ),
    .s4_wid            (     ),
    .s4_wdata          (     ),
    .s4_wstrb          (     ),
    .s4_wlast          (     ),
    .s4_wvalid         (     ),
    .s4_wready         ( 'd1 ),
    .s4_bid            ( 'd0 ),
    .s4_bresp          ( 'd0 ),
    .s4_bvalid         ( 'd0 ),
    .s4_bready         (     ),
    .s4_arid           (     ),
    .s4_araddr         (     ),
    .s4_arlen          (     ),
    .s4_arsize         (     ),
    .s4_arburst        (     ),
    .s4_arlock         (     ),
    .s4_arcache        (     ),
    .s4_arprot         (     ),
    .s4_arvalid        (     ),
    .s4_arready        ( 'd1 ),
    .s4_rid            ( 'd0 ),
    .s4_rdata          ( 'd0 ),
    .s4_rresp          ( 'd0 ),
    .s4_rlast          ( 'd1 ),
    .s4_rvalid         ( 'd0 ),
    .s4_rready         (     ),
    
    .axi_s_aclk        (aclk )
);

// confreg 
wire [31:0] cr00,cr01,cr02,cr03,cr04,cr05,cr06,cr07;
wire [31:0] cr00_in,cr01_in,cr02_in,cr03_in,cr04_in,cr05_in,cr06_in,cr07_in;
  

assign LED     = cr00[15:0];
assign NUM_CSn = cr01[7 :0];
assign NUM_A_G = cr02[7 :0];
assign cr06_in = {27'd0,KEY_in[4:1],~KEY_in[0]};

confreg i_confreg(
    .aclk          (aclk               ),       
    .aresetn       (aresetn            ),       
    .s_awid        (conf_s_awid        ),
    .s_awaddr      (conf_s_awaddr      ),
    .s_awlen       (conf_s_awlen       ),
    .s_awsize      (conf_s_awsize      ),
    .s_awburst     (conf_s_awburst     ),
    .s_awlock      (conf_s_awlock      ),
    .s_awcache     (conf_s_awcache     ),
    .s_awprot      (conf_s_awprot      ),
    .s_awvalid     (conf_s_awvalid     ),
    .s_awready     (conf_s_awready     ),
    .s_wready      (conf_s_wready      ),
    .s_wid         (conf_s_wid         ),
    .s_wdata       (conf_s_wdata       ),
    .s_wstrb       (conf_s_wstrb       ),
    .s_wlast       (conf_s_wlast       ),
    .s_wvalid      (conf_s_wvalid      ),
    .s_bid         (conf_s_bid         ),
    .s_bresp       (conf_s_bresp       ),
    .s_bvalid      (conf_s_bvalid      ),
    .s_bready      (conf_s_bready      ),
    .s_arid        (conf_s_arid        ),
    .s_araddr      (conf_s_araddr      ),
    .s_arlen       (conf_s_arlen       ),
    .s_arsize      (conf_s_arsize      ),
    .s_arburst     (conf_s_arburst     ),
    .s_arlock      (conf_s_arlock      ),
    .s_arcache     (conf_s_arcache     ),
    .s_arprot      (conf_s_arprot      ),
    .s_arvalid     (conf_s_arvalid     ),
    .s_arready     (conf_s_arready     ),
    .s_rready      (conf_s_rready      ),
    .s_rid         (conf_s_rid         ),
    .s_rdata       (conf_s_rdata       ),
    .s_rresp       (conf_s_rresp       ),
    .s_rlast       (conf_s_rlast       ),
    .s_rvalid      (conf_s_rvalid      ),
    
    .cr00          (cr00          ),
    .cr01          (cr01          ),
    .cr02          (cr02          ),
    .cr03          (cr03          ),
    .cr04          (cr04          ),
    .cr05          (cr05          ),
    .cr06          (cr06          ),
    .cr07          (cr07          ),

    .cr00_in          (cr00_in          ),
    .cr01_in          (cr01_in          ),
    .cr02_in          (cr02_in          ),
    .cr03_in          (cr03_in          ),
    .cr04_in          (cr04_in          ),
    .cr05_in          (cr05_in          ),
    .cr06_in          (cr06_in          ),
    .cr07_in          (cr07_in          )
);

// SPI implementation
wire [3:0]spi_csn_o ;
wire [3:0]spi_csn_en;
wire spi_sck_o ;
wire spi_sdo_i ;
wire spi_sdo_o ;
wire spi_sdo_en;
wire spi_sdi_i ;
wire spi_sdi_o ;
wire spi_sdi_en;
wire spi_inta_o;
assign     SPI_CLK = spi_sck_o;
assign     SPI_CS  = ~spi_csn_en[0] & spi_csn_o[0];
assign     SPI_MOSI = spi_sdo_en ? 1'bz : spi_sdo_o ;
assign     SPI_MISO = spi_sdi_en ? 1'bz : spi_sdi_o ;
assign     spi_sdo_i = SPI_MOSI;
assign     spi_sdi_i = SPI_MISO;
spi_flash_ctrl AA_SPI0 (                                         
    .aclk          (aclk),       
    .aresetn       (aresetn            ),       
    .spi_addr      (16'b0001_1111_1110_1000),
    .s_awid        (spi_s_awid        ),
    .s_awaddr      (spi_s_awaddr      ),
    .s_awlen       (spi_s_awlen       ),
    .s_awsize      (spi_s_awsize      ),
    .s_awburst     (spi_s_awburst     ),
    .s_awlock      (spi_s_awlock      ),
    .s_awcache     (spi_s_awcache     ),
    .s_awprot      (spi_s_awprot      ),
    .s_awvalid     (spi_s_awvalid     ),
    .s_awready     (spi_s_awready     ),
    .s_wready      (spi_s_wready      ),
    .s_wid         (spi_s_wid         ),
    .s_wdata       (spi_s_wdata       ),
    .s_wstrb       (spi_s_wstrb       ),
    .s_wlast       (spi_s_wlast       ),
    .s_wvalid      (spi_s_wvalid      ),
    .s_bid         (spi_s_bid         ),
    .s_bresp       (spi_s_bresp       ),
    .s_bvalid      (spi_s_bvalid      ),
    .s_bready      (spi_s_bready      ),
    .s_arid        (spi_s_arid        ),
    .s_araddr      (spi_s_araddr      ),
    .s_arlen       (spi_s_arlen       ),
    .s_arsize      (spi_s_arsize      ),
    .s_arburst     (spi_s_arburst     ),
    .s_arlock      (spi_s_arlock      ),
    .s_arcache     (spi_s_arcache     ),
    .s_arprot      (spi_s_arprot      ),
    .s_arvalid     (spi_s_arvalid     ),
    .s_arready     (spi_s_arready     ),
    .s_rready      (spi_s_rready      ),
    .s_rid         (spi_s_rid         ),
    .s_rdata       (spi_s_rdata       ),
    .s_rresp       (spi_s_rresp       ),
    .s_rlast       (spi_s_rlast       ),
    .s_rvalid      (spi_s_rvalid      ),
    
    .csn_o         (spi_csn_o         ),
    .csn_en        (spi_csn_en        ), // use a gpio pin
    .sck_o         (spi_sck_o         ),
    .sdo_i         (spi_sdo_i         ),
    .sdo_o         (spi_sdo_o         ),
    .sdo_en        (spi_sdo_en        ), // active low
    .sdi_i         (spi_sdi_i         ),
    .sdi_o         (spi_sdi_o         ),
    .sdi_en        (spi_sdi_en        ),
    .inta_o        (spi_inta_o        )
);


//-----------------ddr3 controller----------//
`ifdef HAS_DDR3
    wire   c1_sys_clk;
    wire   c1_sys_rst_i;
    wire   c1_calib_done;
    wire   c1_clk0;
    wire   c1_rst0;
    reg    c1_aresetn;
    

    wire   c1_sys_clk        = clk;
    assign c1_sys_rst_i      = ~resetn;
    assign aclk              = c1_clk0;
    assign aresetn           = c1_aresetn;
    // Reset to the AXI shim
    always @(posedge c1_clk0)
    begin
        c1_aresetn <= ~c1_rst0 && c1_calib_done;
    end
`else
    assign aclk    = clk;
    always @(posedge clk)
    begin
        aresetn = resetn;
    end
`endif

// DDR3 slave module
/*
mig_axi_32 mig_axi (
      );
*/

//-----------------mac slave----------------//
/*
//phy reset
assign    phy_resetn = aresetn;
//mac mdio 
wire            md_i_0;    // MII data input (from I/O cell)
wire            md_o_0;    // MII data output (to I/O cell)
wire            md_oe_0;   // MII data output enable (to I/O cell)
wire md_oe_0_n;
assign md_oe_0_n = ~md_oe_0;
IOBUF mac_mdio(.IO(mdio_0),.I(md_o_0),.T(md_oe_0_n),.O(md_i_0));

ethernet_top mac_slave(
);
*/



//-----------------AXI to APB-----------------//
// AXI2APB implementation
/*
axi2apb_bridge AA_axi2apb_bridge_cpu (
    );
*/

//-----------------UART slave----------------//
/*
UART
*/

//inst sram
ram_16k inst_ram(
    .clka (aclk                             ),
    .wea  (inst_sram_cen & {4{inst_sram_wr}}),
    .addra(inst_sram_addr[15:2]             ),
    .dina (inst_sram_wdata                  ),
    .douta(inst_sram_rdata                  )
);

//data sram
ram_16k data_ram(
    .clka (aclk                             ),
    .wea  (data_sram_cen & {4{data_sram_wr}}),
    .addra(data_sram_addr[15:2]             ),
    .dina (data_sram_wdata                  ),
    .douta(data_sram_rdata                  )
);
endmodule

