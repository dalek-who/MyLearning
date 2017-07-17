`include "config.h"

`define HAS_DDR3 1

module archlab_sopc_top(
    input         resetn, 
    input         clk,

    //------LED and NUM------
    output [15:0] LED,
    output [7 :0] NUM_CSn,
    output [7 :0] NUM_A_G,

    //------DDR3 interface------
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

    //------mac interface-------
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
    

    //------uart interface------
    inout         UART_RX,
    inout         UART_TX,

    //------spi interface------
    output        SPI_CLK,
    output        SPI_CS,
    inout         SPI_MISO,
    inout         SPI_MOSI
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

//DDR controller
wire [`LID         -1 :0] ddr_s_awid;
wire [`Lawaddr     -1 :0] ddr_s_awaddr;
wire [`Lawlen      -1 :0] ddr_s_awlen;
wire [`Lawsize     -1 :0] ddr_s_awsize;
wire [`Lawburst    -1 :0] ddr_s_awburst;
wire [`Lawlock     -1 :0] ddr_s_awlock;
wire [`Lawcache    -1 :0] ddr_s_awcache;
wire [`Lawprot     -1 :0] ddr_s_awprot;
wire                      ddr_s_awvalid;
wire                      ddr_s_awready;
wire [`LID         -1 :0] ddr_s_wid;
wire [`Lwdata      -1 :0] ddr_s_wdata;
wire [`Lwstrb      -1 :0] ddr_s_wstrb;
wire                      ddr_s_wlast;
wire                      ddr_s_wvalid;
wire                      ddr_s_wready;
wire [`LID         -1 :0] ddr_s_bid;
wire [`Lbresp      -1 :0] ddr_s_bresp;
wire                      ddr_s_bvalid;
wire                      ddr_s_bready;
wire [`LID         -1 :0] ddr_s_arid;
wire [`Laraddr     -1 :0] ddr_s_araddr;
wire [`Larlen      -1 :0] ddr_s_arlen;
wire [`Larsize     -1 :0] ddr_s_arsize;
wire [`Larburst    -1 :0] ddr_s_arburst;
wire [`Larlock     -1 :0] ddr_s_arlock;
wire [`Larcache    -1 :0] ddr_s_arcache;
wire [`Larprot     -1 :0] ddr_s_arprot;
wire                      ddr_s_arvalid;
wire                      ddr_s_arready;
wire [`LID         -1 :0] ddr_s_rid;
wire [`Lrdata      -1 :0] ddr_s_rdata;
wire [`Lrresp      -1 :0] ddr_s_rresp;
wire                      ddr_s_rlast;
wire                      ddr_s_rvalid;
wire                      ddr_s_rready;

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

//axi2apb slave
wire [`LID         -1 :0] axi2_s_awid;
wire [`Lawaddr     -1 :0] axi2_s_awaddr;
wire [`Lawlen      -1 :0] axi2_s_awlen;
wire [`Lawsize     -1 :0] axi2_s_awsize;
wire [`Lawburst    -1 :0] axi2_s_awburst;
wire [`Lawlock     -1 :0] axi2_s_awlock;
wire [`Lawcache    -1 :0] axi2_s_awcache;
wire [`Lawprot     -1 :0] axi2_s_awprot;
wire                      axi2_s_awvalid;
wire                      axi2_s_awready;
wire [`LID         -1 :0] axi2_s_wid;
wire [`Lwdata      -1 :0] axi2_s_wdata;
wire [`Lwstrb      -1 :0] axi2_s_wstrb;
wire                      axi2_s_wlast;
wire                      axi2_s_wvalid;
wire                      axi2_s_wready;
wire [`LID         -1 :0] axi2_s_bid;
wire [`Lbresp      -1 :0] axi2_s_bresp;
wire                      axi2_s_bvalid;
wire                      axi2_s_bready;
wire [`LID         -1 :0] axi2_s_arid;
wire [`Laraddr     -1 :0] axi2_s_araddr;
wire [`Larlen      -1 :0] axi2_s_arlen;
wire [`Larsize     -1 :0] axi2_s_arsize;
wire [`Larburst    -1 :0] axi2_s_arburst;
wire [`Larlock     -1 :0] axi2_s_arlock;
wire [`Larcache    -1 :0] axi2_s_arcache;
wire [`Larprot     -1 :0] axi2_s_arprot;
wire                      axi2_s_arvalid;
wire                      axi2_s_arready;
wire [`LID         -1 :0] axi2_s_rid;
wire [`Lrdata      -1 :0] axi2_s_rdata;
wire [`Lrresp      -1 :0] axi2_s_rresp;
wire                      axi2_s_rlast;
wire                      axi2_s_rvalid;
wire                      axi2_s_rready;

//uart slave
wire        PCLK;
wire        PRST_;
wire        PSEL;
wire        PENABLE;
wire        PWRITE;
wire  [7:0] PADDR;
wire  [7:0] PWDATA;
wire  [7:0] URT_PRDATA;

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

//mac slave
wire [`LID         -1 :0] mac_s_awid;
wire [`Lawaddr     -1 :0] mac_s_awaddr;
wire [`Lawlen      -1 :0] mac_s_awlen;
wire [`Lawsize     -1 :0] mac_s_awsize;
wire [`Lawburst    -1 :0] mac_s_awburst;
wire [`Lawlock     -1 :0] mac_s_awlock;
wire [`Lawcache    -1 :0] mac_s_awcache;
wire [`Lawprot     -1 :0] mac_s_awprot;
wire                      mac_s_awvalid;
wire                      mac_s_awready;
wire [`LID         -1 :0] mac_s_wid;
wire [`Lwdata      -1 :0] mac_s_wdata;
wire [`Lwstrb      -1 :0] mac_s_wstrb;
wire                      mac_s_wlast;
wire                      mac_s_wvalid;
wire                      mac_s_wready;
wire [`LID         -1 :0] mac_s_bid;
wire [`Lbresp      -1 :0] mac_s_bresp;
wire                      mac_s_bvalid;
wire                      mac_s_bready;
wire [`LID         -1 :0] mac_s_arid;
wire [`Laraddr     -1 :0] mac_s_araddr;
wire [`Larlen      -1 :0] mac_s_arlen;
wire [`Larsize     -1 :0] mac_s_arsize;
wire [`Larburst    -1 :0] mac_s_arburst;
wire [`Larlock     -1 :0] mac_s_arlock;
wire [`Larcache    -1 :0] mac_s_arcache;
wire [`Larprot     -1 :0] mac_s_arprot;
wire                      mac_s_arvalid;
wire                      mac_s_arready;
wire [`LID         -1 :0] mac_s_rid;
wire [`Lrdata      -1 :0] mac_s_rdata;
wire [`Lrresp      -1 :0] mac_s_rresp;
wire                      mac_s_rlast;
wire                      mac_s_rvalid;
wire                      mac_s_rready;

//mac master - ddr slave
wire [`LID         -1 :0] mac_m_ddr_s_awid;
wire [`Lawaddr     -1 :0] mac_m_ddr_s_awaddr;
wire [`Lawlen      -1 :0] mac_m_ddr_s_awlen;
wire [`Lawsize     -1 :0] mac_m_ddr_s_awsize;
wire [`Lawburst    -1 :0] mac_m_ddr_s_awburst;
wire [`Lawlock     -1 :0] mac_m_ddr_s_awlock;
wire [`Lawcache    -1 :0] mac_m_ddr_s_awcache;
wire [`Lawprot     -1 :0] mac_m_ddr_s_awprot;
wire                      mac_m_ddr_s_awvalid;
wire                      mac_m_ddr_s_awready;
wire [`LID         -1 :0] mac_m_ddr_s_wid;
wire [`Lwdata      -1 :0] mac_m_ddr_s_wdata;
wire [`Lwstrb      -1 :0] mac_m_ddr_s_wstrb;
wire                      mac_m_ddr_s_wlast;
wire                      mac_m_ddr_s_wvalid;
wire                      mac_m_ddr_s_wready;
wire [`LID         -1 :0] mac_m_ddr_s_bid;
wire [`Lbresp      -1 :0] mac_m_ddr_s_bresp;
wire                      mac_m_ddr_s_bvalid;
wire                      mac_m_ddr_s_bready;
wire [`LID         -1 :0] mac_m_ddr_s_arid;
wire [`Laraddr     -1 :0] mac_m_ddr_s_araddr;
wire [`Larlen      -1 :0] mac_m_ddr_s_arlen;
wire [`Larsize     -1 :0] mac_m_ddr_s_arsize;
wire [`Larburst    -1 :0] mac_m_ddr_s_arburst;
wire [`Larlock     -1 :0] mac_m_ddr_s_arlock;
wire [`Larcache    -1 :0] mac_m_ddr_s_arcache;
wire [`Larprot     -1 :0] mac_m_ddr_s_arprot;
wire                      mac_m_ddr_s_arvalid;
wire                      mac_m_ddr_s_arready;
wire [`LID         -1 :0] mac_m_ddr_s_rid;
wire [`Lrdata      -1 :0] mac_m_ddr_s_rdata;
wire [`Lrresp      -1 :0] mac_m_ddr_s_rresp;
wire                      mac_m_ddr_s_rlast;
wire                      mac_m_ddr_s_rvalid;
wire                      mac_m_ddr_s_rready;

//INST SRAM: 0x0000_0000 ~ 0x0000_ffff
wire [3 :0] inst_sram_cen;
wire        inst_sram_wr;
wire [31:0] inst_sram_addr;
wire [31:0] inst_sram_wdata;
wire        inst_sram_ack  = 1'b1;
wire        inst_sram_rrdy =1'b1;
wire [31:0] inst_sram_rdata;

//DATA SRAM: 0x0800_0000 ~ 0x0800_ffff
wire [3 :0] data_sram_cen;
wire        data_sram_wr;
wire [31:0] data_sram_addr;
wire [31:0] data_sram_wdata;
wire        data_sram_ack  = 1'b1;
wire        data_sram_rrdy = 1'b1;
wire [31:0] data_sram_rdata;

//interrupt
wire uart_int;
wire mac_int;
wire [5:0] int_out = {3'b0,spi_inta_o,uart_int,mac_int};
wire [5:0] int_n_i = ~int_out;

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
    .axi_s_aclk        (aclk           ),
    .axi_s_aresetn     (aresetn        ),

    //m0: CPU IP
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
    
    //s0: DDR controller
    //TODO 1: complete
    .s0_awid           (ddr_s_awid        ),
    .s0_awaddr         (ddr_s_awaddr      ),
    .s0_awlen          (ddr_s_awlen       ),
    .s0_awsize         (ddr_s_awsize      ),
    .s0_awburst        (ddr_s_awburst     ),
    .s0_awlock         (ddr_s_awlock      ),
    .s0_awcache        (ddr_s_awcache     ),
    .s0_awprot         (ddr_s_awprot      ),
    .s0_awvalid        (ddr_s_awvalid     ),
    .s0_awready        (ddr_s_awready     ),
    .s0_wid            (ddr_s_wid         ),
    .s0_wdata          (ddr_s_wdata       ),
    .s0_wstrb          (ddr_s_wstrb       ),
    .s0_wlast          (ddr_s_wlast       ),
    .s0_wvalid         (ddr_s_wvalid      ),
    .s0_wready         (ddr_s_wready      ),
    .s0_bid            (ddr_s_bid         ),
    .s0_bresp          (ddr_s_bresp       ),
    .s0_bvalid         (ddr_s_bvalid      ),
    .s0_bready         (ddr_s_bready      ),
    .s0_arid           (ddr_s_arid        ),
    .s0_araddr         (ddr_s_araddr      ),
    .s0_arlen          (ddr_s_arlen       ),
    .s0_arsize         (ddr_s_arsize      ),
    .s0_arburst        (ddr_s_arburst     ),
    .s0_arlock         (ddr_s_arlock      ),
    .s0_arcache        (ddr_s_arcache     ),
    .s0_arprot         (ddr_s_arprot      ),
    .s0_arvalid        (ddr_s_arvalid     ),
    .s0_arready        (ddr_s_arready     ),
    .s0_rid            (ddr_s_rid         ),
    .s0_rdata          (ddr_s_rdata       ),
    .s0_rresp          (ddr_s_rresp       ),
    .s0_rlast          (ddr_s_rlast       ),
    .s0_rvalid         (ddr_s_rvalid      ),
    .s0_rready         (ddr_s_rready      ),
    
    //s1: SPI flash
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
    
    //s2: axi2apb bridge
    //TODO 2: complete
    .s2_awid           (axi2_s_awid          ),
    .s2_awaddr         (axi2_s_awaddr        ),
    .s2_awlen          (axi2_s_awlen         ),
    .s2_awsize         (axi2_s_awsize        ),
    .s2_awburst        (axi2_s_awburst       ),
    .s2_awlock         (axi2_s_awlock        ),
    .s2_awcache        (axi2_s_awcache       ),
    .s2_awprot         (axi2_s_awprot        ),
    .s2_awvalid        (axi2_s_awvalid       ),
    .s2_awready        (axi2_s_awready       ),
    .s2_wid            (axi2_s_wid           ),
    .s2_wdata          (axi2_s_wdata         ),
    .s2_wstrb          (axi2_s_wstrb         ),
    .s2_wlast          (axi2_s_wlast         ),
    .s2_wvalid         (axi2_s_wvalid        ),
    .s2_wready         (axi2_s_wready        ),
    .s2_bid            (axi2_s_bid           ),
    .s2_bresp          (axi2_s_bresp         ),
    .s2_bvalid         (axi2_s_bvalid        ),
    .s2_bready         (axi2_s_bready        ),
    .s2_arid           (axi2_s_arid          ),
    .s2_araddr         (axi2_s_araddr        ),
    .s2_arlen          (axi2_s_arlen         ),
    .s2_arsize         (axi2_s_arsize        ),
    .s2_arburst        (axi2_s_arburst       ),
    .s2_arlock         (axi2_s_arlock        ),
    .s2_arcache        (axi2_s_arcache       ),
    .s2_arprot         (axi2_s_arprot        ),
    .s2_arvalid        (axi2_s_arvalid       ),
    .s2_arready        (axi2_s_arready       ),
    .s2_rid            (axi2_s_rid           ),
    .s2_rdata          (axi2_s_rdata         ),
    .s2_rresp          (axi2_s_rresp         ),
    .s2_rlast          (axi2_s_rlast         ),
    .s2_rvalid         (axi2_s_rvalid        ),
    .s2_rready         (axi2_s_rready        ),

    //s3: confreg
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
    
    //s4: mac
    //TODO 3: complete
    .s4_awid           (mac_s_awid         ),
    .s4_awaddr         (mac_s_awaddr       ),
    .s4_awlen          (mac_s_awlen        ),
    .s4_awsize         (mac_s_awsize       ),
    .s4_awburst        (mac_s_awburst      ),
    .s4_awlock         (mac_s_awlock       ),
    .s4_awcache        (mac_s_awcache      ),
    .s4_awprot         (mac_s_awprot       ),
    .s4_awvalid        (mac_s_awvalid      ),
    .s4_awready        (mac_s_awready      ),
    .s4_wid            (mac_s_wid          ),
    .s4_wdata          (mac_s_wdata        ),
    .s4_wstrb          (mac_s_wstrb        ),
    .s4_wlast          (mac_s_wlast        ),
    .s4_wvalid         (mac_s_wvalid       ),
    .s4_wready         (mac_s_wready       ),
    .s4_bid            (mac_s_bid          ),
    .s4_bresp          (mac_s_bresp        ),
    .s4_bvalid         (mac_s_bvalid       ),
    .s4_bready         (mac_s_bready       ),
    .s4_arid           (mac_s_arid         ),
    .s4_araddr         (mac_s_araddr       ),
    .s4_arlen          (mac_s_arlen        ),
    .s4_arsize         (mac_s_arsize       ),
    .s4_arburst        (mac_s_arburst      ),
    .s4_arlock         (mac_s_arlock       ),
    .s4_arcache        (mac_s_arcache      ),
    .s4_arprot         (mac_s_arprot       ),
    .s4_arvalid        (mac_s_arvalid      ),
    .s4_arready        (mac_s_arready      ),
    .s4_rid            (mac_s_rid          ),
    .s4_rdata          (mac_s_rdata        ),
    .s4_rresp          (mac_s_rresp        ),
    .s4_rlast          (mac_s_rlast        ),
    .s4_rvalid         (mac_s_rvalid       ),
    .s4_rready         (mac_s_rready       )

);

// confreg 
wire [31:0] cr00,cr01,cr02,cr03,cr04,cr05,cr06,cr07;
assign LED     = cr00[15:0];
assign NUM_CSn = cr01[7 :0];
assign NUM_A_G = cr02[7 :0];

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
    .cr07          (cr07          )
);

// SPI implementation
wire [3:0]spi_csn_o; 
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
    .aclk          (aclk                ),       
    .aresetn       (aresetn             ),       
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
    

    assign c1_sys_clk        = clk;
    assign c1_sys_rst_i      = ~resetn;
    assign aclk              = c1_clk0;
    // Reset to the AXI shim
    always @(posedge c1_clk0)
    begin
        aresetn <= ~c1_rst0 && c1_calib_done;
    end
`else
    assign aclk    = clk;
    always @(posedge clk)
    begin
        aresetn = resetn;
    end
`endif

// DDR3 slave module
mig_axi_32 mig_axi (
    //TODO 4: complete
    .mcb1_dram_dq       (mcb1_dram_dq       ),
    .mcb1_dram_a        (mcb1_dram_a        ),
    .mcb1_dram_ba       (mcb1_dram_ba       ),
    .mcb1_dram_ras_n    (mcb1_dram_ras_n    ),
    .mcb1_dram_cas_n    (mcb1_dram_cas_n    ),
    .mcb1_dram_we_n     (mcb1_dram_we_n     ),
    .mcb1_dram_odt      (mcb1_dram_odt      ),
    .mcb1_dram_reset_n  (mcb1_dram_reset_n  ),
    .mcb1_dram_cke      (mcb1_dram_cke      ),
    .mcb1_dram_dm       (mcb1_dram_dm       ),
    .mcb1_dram_udqs     (mcb1_dram_udqs     ),
    .mcb1_dram_udqs_n   (mcb1_dram_udqs_n   ),
    .mcb1_rzq           (mcb1_rzq           ),
    .mcb1_zio           (mcb1_zio           ),
    .mcb1_dram_udm      (mcb1_dram_udm      ),
    .mcb1_dram_dqs      (mcb1_dram_dqs      ),
    .mcb1_dram_dqs_n    (mcb1_dram_dqs_n    ),
    .mcb1_dram_ck       (mcb1_dram_ck       ),
    .mcb1_dram_ck_n     (mcb1_dram_ck_n     ),

    .c1_sys_clk         (c1_sys_clk         ),
    .c1_sys_rst_i       (c1_sys_rst_i       ),
    .c1_calib_done      (c1_calib_done      ),
    .c1_clk0            (c1_clk0            ),
    .c1_rst0            (c1_rst0            ),

    .c1_s0_axi_aclk     (aclk               ),
    .c1_s0_axi_aresetn  (aresetn            ),

    .c1_s0_axi_awid     (ddr_s_awid         ),
    .c1_s0_axi_awaddr   (ddr_s_awaddr       ),
    .c1_s0_axi_awlen    (ddr_s_awlen        ),
    .c1_s0_axi_awsize   (ddr_s_awsize       ),
    .c1_s0_axi_awburst  (ddr_s_awburst      ),
    .c1_s0_axi_awlock   (ddr_s_awlock       ),
    .c1_s0_axi_awcache  (ddr_s_awcache      ),
    .c1_s0_axi_awprot   (ddr_s_awprot       ),
    .c1_s0_axi_awvalid  (ddr_s_awvalid      ),
    .c1_s0_axi_awready  (ddr_s_awready      ),
    .c1_s0_axi_wdata    (ddr_s_wdata        ),
    .c1_s0_axi_wstrb    (ddr_s_wstrb        ),
    .c1_s0_axi_wlast    (ddr_s_wlast        ),
    .c1_s0_axi_wvalid   (ddr_s_wvalid       ),
    .c1_s0_axi_wready   (ddr_s_wready       ),
    .c1_s0_axi_bid      (ddr_s_bid          ),
    .c1_s0_axi_wid      (ddr_s_wid          ),
    .c1_s0_axi_bresp    (ddr_s_bresp        ),
    .c1_s0_axi_bvalid   (ddr_s_bvalid       ),
    .c1_s0_axi_bready   (ddr_s_bready       ),
    .c1_s0_axi_arid     (ddr_s_arid         ),
    .c1_s0_axi_araddr   (ddr_s_araddr       ),
    .c1_s0_axi_arlen    (ddr_s_arlen        ),
    .c1_s0_axi_arsize   (ddr_s_arsize       ),
    .c1_s0_axi_arburst  (ddr_s_arburst      ),
    .c1_s0_axi_arlock   (ddr_s_arlock       ),
    .c1_s0_axi_arcache  (ddr_s_arcache      ),
    .c1_s0_axi_arprot   (ddr_s_arprot       ),
    .c1_s0_axi_arvalid  (ddr_s_arvalid      ),
    .c1_s0_axi_arready  (ddr_s_arready      ),
    .c1_s0_axi_rid      (ddr_s_rid          ),
    .c1_s0_axi_rdata    (ddr_s_rdata        ),
    .c1_s0_axi_rresp    (ddr_s_rresp        ),
    .c1_s0_axi_rlast    (ddr_s_rlast        ),
    .c1_s0_axi_rvalid   (ddr_s_rvalid       ),
    .c1_s0_axi_rready   (ddr_s_rready       ),
    .c1_s1_axi_aclk     (aclk                   ),
    .c1_s1_axi_aresetn  (aresetn                ),
    .c1_s1_axi_awid     (mac_m_ddr_s_awid       ),
    .c1_s1_axi_awaddr   (mac_m_ddr_s_awaddr     ),
    .c1_s1_axi_awlen    (mac_m_ddr_s_awlen      ),
    .c1_s1_axi_awsize   (mac_m_ddr_s_awsize     ),
    .c1_s1_axi_awburst  (mac_m_ddr_s_awburst    ),
    .c1_s1_axi_awlock   (mac_m_ddr_s_awlock     ),
    .c1_s1_axi_awcache  (mac_m_ddr_s_awcache    ),
    .c1_s1_axi_awprot   (mac_m_ddr_s_awprot     ),
    .c1_s1_axi_awvalid  (mac_m_ddr_s_awvalid    ),
    .c1_s1_axi_awready  (mac_m_ddr_s_awready    ),
    .c1_s1_axi_wdata    (mac_m_ddr_s_wdata      ),
    .c1_s1_axi_wstrb    (mac_m_ddr_s_wstrb      ),
    .c1_s1_axi_wlast    (mac_m_ddr_s_wlast      ),
    .c1_s1_axi_wvalid   (mac_m_ddr_s_wvalid     ),
    .c1_s1_axi_wready   (mac_m_ddr_s_wready     ),
    .c1_s1_axi_bid      (mac_m_ddr_s_bid        ),
    .c1_s1_axi_wid      (mac_m_ddr_s_wid        ),
    .c1_s1_axi_bresp    (mac_m_ddr_s_bresp      ),
    .c1_s1_axi_bvalid   (mac_m_ddr_s_bvalid     ),
    .c1_s1_axi_bready   (mac_m_ddr_s_bready     ),
    .c1_s1_axi_arid     (mac_m_ddr_s_arid       ),
    .c1_s1_axi_araddr   (mac_m_ddr_s_araddr     ),
    .c1_s1_axi_arlen    (mac_m_ddr_s_arlen      ),
    .c1_s1_axi_arsize   (mac_m_ddr_s_arsize     ),
    .c1_s1_axi_arburst  (mac_m_ddr_s_arburst    ),
    .c1_s1_axi_arlock   (mac_m_ddr_s_arlock     ),
    .c1_s1_axi_arcache  (mac_m_ddr_s_arcache    ),
    .c1_s1_axi_arprot   (mac_m_ddr_s_arprot     ),
    .c1_s1_axi_arvalid  (mac_m_ddr_s_arvalid    ),
    .c1_s1_axi_arready  (mac_m_ddr_s_arready    ),
    .c1_s1_axi_rid      (mac_m_ddr_s_rid        ),
    .c1_s1_axi_rdata    (mac_m_ddr_s_rdata      ),
    .c1_s1_axi_rresp    (mac_m_ddr_s_rresp      ),
    .c1_s1_axi_rlast    (mac_m_ddr_s_rlast      ),
    .c1_s1_axi_rvalid   (mac_m_ddr_s_rvalid     ),
    .c1_s1_axi_rready   (mac_m_ddr_s_rready     )
);


//-----------------mac slave----------------//
//phy reset
assign    phy_resetn = aresetn;
//mac mdio
wire md_i_0;
wire md_o_0;
wire md_oe_0;
assign mdio_0 = md_oe_0 ? md_o_0 : 1'bz;
assign md_i_0 = mdio_0;

ethernet_top mac_slave(
    //TODO 5: complete
    .aclk               (aclk           ),
    .aresetn            (aresetn        ),       
    //axi master
    .mawid_o            (mac_m_ddr_s_awid       ),
    .mawaddr_o          (mac_m_ddr_s_awaddr     ),
    .mawlen_o           (mac_m_ddr_s_awlen      ),
    .mawsize_o          (mac_m_ddr_s_awsize     ),
    .mawburst_o         (mac_m_ddr_s_awburst    ),
    .mawlock_o          (mac_m_ddr_s_awlock     ),
    .mawcache_o         (mac_m_ddr_s_awcache    ),
    .mawprot_o          (mac_m_ddr_s_awprot     ),
    .mawvalid_o         (mac_m_ddr_s_awvalid    ),
    .mawready_i         (mac_m_ddr_s_awready    ),
    .mwid_o             (mac_m_ddr_s_wid        ),
    .mwdata_o           (mac_m_ddr_s_wdata      ),
    .mwstrb_o           (mac_m_ddr_s_wstrb      ),
    .mwlast_o           (mac_m_ddr_s_wlast      ),
    .mwvalid_o          (mac_m_ddr_s_wvalid     ),
    .mwready_i          (mac_m_ddr_s_wready     ),
    .mbid_i             (mac_m_ddr_s_bid        ),
    .mbresp_i           (mac_m_ddr_s_bresp      ),
    .mbvalid_i          (mac_m_ddr_s_bvalid     ),
    .mbready_o          (mac_m_ddr_s_bready     ),
    .marid_o            (mac_m_ddr_s_arid       ),
    .maraddr_o          (mac_m_ddr_s_araddr     ),
    .marlen_o           (mac_m_ddr_s_arlen      ),
    .marsize_o          (mac_m_ddr_s_arsize     ),
    .marburst_o         (mac_m_ddr_s_arburst    ),
    .marlock_o          (mac_m_ddr_s_arlock     ),
    .marcache_o         (mac_m_ddr_s_arcache    ),
    .marprot_o          (mac_m_ddr_s_arprot     ),
    .marvalid_o         (mac_m_ddr_s_arvalid    ),
    .marready_i         (mac_m_ddr_s_arready    ),
    .mrid_i             (mac_m_ddr_s_rid        ),
    .mrdata_i           (mac_m_ddr_s_rdata      ),
    .mrresp_i           (mac_m_ddr_s_rresp      ),
    .mrlast_i           (mac_m_ddr_s_rlast      ),
    .mrvalid_i          (mac_m_ddr_s_rvalid     ),
    .mrready_o          (mac_m_ddr_s_rready     ),
    //axi slaver
    .sawid_i            (mac_s_awid     ),
    .sawaddr_i          (mac_s_awaddr   ),
    .sawlen_i           (mac_s_awlen    ),
    .sawsize_i          (mac_s_awsize   ),
    .sawburst_i         (mac_s_awburst  ),
    .sawlock_i          (mac_s_awlock   ),
    .sawcache_i         (mac_s_awcache  ),
    .sawprot_i          (mac_s_awprot   ),
    .sawvalid_i         (mac_s_awvalid  ),
    .sawready_o         (mac_s_awready  ),
    .swid_i             (mac_s_wid      ),
    .swdata_i           (mac_s_wdata    ),
    .swstrb_i           (mac_s_wstrb    ),
    .swlast_i           (mac_s_wlast    ),
    .swvalid_i          (mac_s_wvalid   ),
    .swready_o          (mac_s_wready   ),
    .sbid_o             (mac_s_bid      ),
    .sbresp_o           (mac_s_bresp    ),
    .sbvalid_o          (mac_s_bvalid   ),
    .sbready_i          (mac_s_bready   ),
    .sarid_i            (mac_s_arid     ),
    .saraddr_i          (mac_s_araddr   ),
    .sarlen_i           (mac_s_arlen    ),
    .sarsize_i          (mac_s_arsize   ),
    .sarburst_i         (mac_s_arburst  ),
    .sarlock_i          (mac_s_arlock   ),
    .sarcache_i         (mac_s_arcache  ),
    .sarprot_i          (mac_s_arprot   ),
    .sarvalid_i         (mac_s_arvalid  ),
    .sarready_o         (mac_s_arready  ),
    .srid_o             (mac_s_rid      ),
    .srdata_o           (mac_s_rdata    ),
    .srresp_o           (mac_s_rresp    ),
    .srlast_o           (mac_s_rlast    ),
    .srvalid_o          (mac_s_rvalid   ),
    .srready_i          (mac_s_rready   ),           

    .interrupt_0        (mac_int        ),
 
    // I/O pad interface signals
    //TX
    .mtxclk_0           (mtxclk_0       ),     
    .mtxen_0            (mtxen_0        ),      
    .mtxd_0             (mtxd_0         ),       
    .mtxerr_0           (mtxerr_0       ),
    //RX
    .mrxclk_0           (mrxclk_0       ),      
    .mrxdv_0            (mrxdv_0        ),     
    .mrxd_0             (mrxd_0         ),        
    .mrxerr_0           (mrxerr_0       ),
    .mcoll_0            (mcoll_0        ),
    .mcrs_0             (mcrs_0         ),
    // MIIM
    .mdc_0              (mdc_0          ),
    .md_i_0             (md_i_0         ),
    .md_o_0             (md_o_0         ),
    .md_oe_0            (md_oe_0        )
);




//-----------------AXI to APB-----------------//
// AXI2APB implementation
axi2apb_bridge axi2apb_bridge_cpu (
//TODO 6: complete
    .clk                (aclk               ),
    .rst_n              (aresetn            ),

    //axi interface
    .axi_s_awid         (axi2_s_awid        ),
    .axi_s_awaddr       (axi2_s_awaddr      ),
    .axi_s_awlen        (axi2_s_awlen       ),
    .axi_s_awsize       (axi2_s_awsize      ),
    .axi_s_awburst      (axi2_s_awburst     ),
    .axi_s_awlock       (axi2_s_awlock      ),
    .axi_s_awcache      (axi2_s_awcache     ),
    .axi_s_awprot       (axi2_s_awprot      ),
    .axi_s_awvalid      (axi2_s_awvalid     ),
    .axi_s_awready      (axi2_s_awready     ),
    .axi_s_wid          (axi2_s_wid         ),
    .axi_s_wdata        (axi2_s_wdata       ),
    .axi_s_wstrb        (axi2_s_wstrb       ),
    .axi_s_wlast        (axi2_s_wlast       ),
    .axi_s_wvalid       (axi2_s_wvalid      ),
    .axi_s_wready       (axi2_s_wready      ),
    .axi_s_bid          (axi2_s_bid         ),
    .axi_s_bresp        (axi2_s_bresp       ),
    .axi_s_bvalid       (axi2_s_bvalid      ),
    .axi_s_bready       (axi2_s_bready      ),
    .axi_s_arid         (axi2_s_arid        ),
    .axi_s_araddr       (axi2_s_araddr      ),
    .axi_s_arlen        (axi2_s_arlen       ),
    .axi_s_arsize       (axi2_s_arsize      ),
    .axi_s_arburst      (axi2_s_arburst     ),
    .axi_s_arlock       (axi2_s_arlock      ),
    .axi_s_arcache      (axi2_s_arcache     ),
    .axi_s_arprot       (axi2_s_arprot      ),
    .axi_s_arvalid      (axi2_s_arvalid     ),
    .axi_s_arready      (axi2_s_arready     ),
    .axi_s_rid          (axi2_s_rid         ),
    .axi_s_rdata        (axi2_s_rdata       ),
    .axi_s_rresp        (axi2_s_rresp       ),
    .axi_s_rlast        (axi2_s_rlast       ),
    .axi_s_rvalid       (axi2_s_rvalid      ),
    .axi_s_rready       (axi2_s_rready      ),
    
    //apb interface
    .apb_clk            (PCLK               ),
    .apb_reset_n        (PRST_              ),
    .reg_psel           (PSEL               ),
    .reg_enable         (PENABLE            ),
    .reg_rw             (PWRITE             ),
    .reg_addr           (PADDR              ),
    .reg_datai          (PWDATA             ),
    .reg_datao          (URT_PRDATA         )
);


//-----------------UART slave----------------//
wire TXD_i;
wire TXD_o;
wire TXD_oe;
assign UART_TX = TXD_oe ? 1'bz : TXD_o ;
assign TXD_i = UART_TX;
wire RXD_i;
wire RXD_o;
wire RXD_oe;
assign UART_RX = RXD_oe ? 1'bz : RXD_o ;
assign RXD_i = UART_RX;
UART_TOP uart0 (
//TODO 7: complete
    //apb interface
    .PCLK               (PCLK               ),
    .PRST_              (PRST_              ),
    .PSEL               (PSEL               ),
    .PENABLE            (PENABLE            ),
    .PADDR              (PADDR              ),
    .PWRITE             (PWRITE             ),
    .PWDATA             (PWDATA             ),
    .URT_PRDATA         (URT_PRDATA         ),

    //interrupt
    .INT                (uart_int           ), 
    
    //TX inout
    .TXD_i              (TXD_i              ), 
    .TXD_o              (TXD_o              ), 
    .TXD_oe             (TXD_oe             ),     
    //RX inout
    .RXD_i              (RXD_i              ), 
    .RXD_o              (RXD_o              ), 
    .RXD_oe             (RXD_oe             )
);

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

