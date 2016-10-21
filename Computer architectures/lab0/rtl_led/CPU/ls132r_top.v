/*
 * Top of LS132R CPU. 
 *
 * 1. Clock domain of interface and core logic: 
 *      port "aclk" (if AXI bus is used)
 * 2. Clock domain of EJTAG TAP:
 *      port "ejtag_tck" (if EJTAG is implemented)
 * 3. No RAM macro used inside LS132R
 *
 */
`include "ls132r_define.h"
module ls132r_top(
  int_n_i,
  sleeping_o,

`ifdef LS132R_AXI_IF
  aclk,
  areset_n,

  arid,
  araddr,
  arlen,
  arsize,
  arburst,
  arlock,
  arcache,
  arprot,
  arvalid,
  arready,

  rid,
  rdata,
  rresp,
  rlast,
  rvalid,
  rready,

  awid,
  awaddr,
  awlen,
  awsize,
  awburst,
  awlock,
  awcache,
  awprot,
  awvalid,
  awready,

  wid,
  wdata,
  wstrb,
  wlast,
  wvalid,
  wready,

  bid,
  bresp,
  bvalid,
  bready 
`endif

`ifdef LS132R_INST_SRAM_IFC
 ,inst_sram_cen
 ,inst_sram_wr
 ,inst_sram_addr
 ,inst_sram_wdata
 ,inst_sram_ack
 ,inst_sram_rrdy
 ,inst_sram_rdata
`endif

`ifdef LS132R_DATA_SRAM_IFC
 ,data_sram_cen
 ,data_sram_wr
 ,data_sram_addr
 ,data_sram_wdata
 ,data_sram_ack
 ,data_sram_rrdy
 ,data_sram_rdata
`endif

);

parameter LS132R_SCANBUS_WIDTH=2;

input   [ 5:0]  int_n_i;

output          sleeping_o;

`ifdef LS132R_AXI_IF
input           aclk;
input           areset_n;

//read address channel
input           arready;
output  [3:0]   arid;
output  [31:0]  araddr;
output  [3:0]   arlen;
output  [2:0]   arsize;
output  [1:0]   arburst;
output  [1:0]   arlock;
output  [3:0]   arcache;
output  [2:0]   arprot;
output          arvalid;

//read data channel
input   [3:0]   rid;
`ifdef LS132R_BUS_32BIT 
input   [31:0]  rdata;
`endif
`ifdef LS132R_BUS_64BIT
input   [63:0]  rdata;
`endif
`ifdef LS132R_BUS_128BIT
input   [127:0] rdata;
`endif
input   [1:0]   rresp;
input           rlast;
input           rvalid;
output          rready;

//write address channel
input           awready;
output  [3:0]   awid;
output  [31:0]  awaddr;
output  [3:0]   awlen;
output  [2:0]   awsize;
output  [1:0]   awburst;
output  [1:0]   awlock;
output  [3:0]   awcache;
output  [2:0]   awprot;
output          awvalid;

//write data channel
input           wready;
output  [3:0]   wid;
`ifdef LS132R_BUS_32BIT
output  [31:0]  wdata;
output  [3:0]   wstrb;
`endif
`ifdef LS132R_BUS_64BIT
output  [63:0]  wdata;
output  [7:0]   wstrb;
`endif
`ifdef LS132R_BUS_128BIT
output  [127:0] wdata;
output  [15:0]  wstrb;
`endif
output          wlast;
output          wvalid;

//write response channel
input   [3:0]   bid;
input   [1:0]   bresp;
input           bvalid;
output          bready;
`endif

`ifdef LS132R_INST_SRAM_IFC
`ifdef LS132R_INST_SRAM_32BIT
output  [ 3:0]  inst_sram_cen;
output  [31:0]  inst_sram_wdata;
input   [31:0]  inst_sram_rdata;
`endif
output          inst_sram_wr;
output  [31:0]  inst_sram_addr;
input           inst_sram_ack;
input           inst_sram_rrdy;
`endif

`ifdef LS132R_DATA_SRAM_IFC
`ifdef LS132R_DATA_SRAM_32BIT
output  [ 3:0]  data_sram_cen;
output  [31:0]  data_sram_wdata;
input   [31:0]  data_sram_rdata;
`endif
output          data_sram_wr;
output  [31:0]  data_sram_addr;
input           data_sram_ack;
input           data_sram_rrdy;
`endif

wire                        clock;
wire                        reset;
wire [               5:0]   hw_int;
wire [    `Ltoifcbus-1:0]   inst_ifc_bus;
wire [  `Lfromifcbus-1:0]   ifc_inst_bus;
wire [    `Ltoifcbus-1:0]   data_ifc_bus;
wire [  `Lfromifcbus-1:0]   ifc_data_bus;
wire [    `Lcpustbus-1:0]   cpu_status;
wire [       `Lexbus-1:0]   exbus;
wire [       `Lbrbus-1:0]   brbus;
wire [    `Lexestbus-1:0]   exe_status;
wire [    `Ldecstbus-1:0]   dec_status;
wire [       `Lirbus-1:0]   irbus;
wire                        ex_int;
wire [       `Lwbbus-1:0]   wbbus;
wire [    `Lissuebus-1:0]   issuebus;

wire                        wait_sleep;
wire                        idle_in_ir;
wire                        idle_in_rs;
wire                        idle_in_ifc;


assign wait_sleep   = dec_status[2];
assign idle_in_ir   = dec_status[36];
assign idle_in_rs   = exe_status[2];

assign sleeping_o   = wait_sleep && idle_in_ir && idle_in_rs && idle_in_ifc;



ls132r_interface
    u_interface(
      .test_mode    (1'b0       ),
      .int_n_i      (int_n_i    ),
    
    `ifdef LS132R_AXI_IF
      .aclk         (aclk       ),
      .areset_n     (areset_n   ),
    
      .arid         (arid       ),
      .araddr       (araddr     ),
      .arlen        (arlen      ),
      .arsize       (arsize     ),
      .arburst      (arburst    ),
      .arlock       (arlock     ),
      .arcache      (arcache    ),
      .arprot       (arprot     ),
      .arvalid      (arvalid    ),
      .arready      (arready    ),
    
      .rid          (rid        ),
      .rdata        (rdata      ),
      .rresp        (rresp      ),
      .rlast        (rlast      ),
      .rvalid       (rvalid     ),
      .rready       (rready     ),
    
      .awid         (awid       ),
      .awaddr       (awaddr     ),
      .awlen        (awlen      ),
      .awsize       (awsize     ),
      .awburst      (awburst    ),
      .awlock       (awlock     ),
      .awcache      (awcache    ),
      .awprot       (awprot     ),
      .awvalid      (awvalid    ),
      .awready      (awready    ),
    
      .wid          (wid        ),
      .wdata        (wdata      ),
      .wstrb        (wstrb      ),
      .wlast        (wlast      ),
      .wvalid       (wvalid     ),
      .wready       (wready     ),
    
      .bid          (bid        ),
      .bresp        (bresp      ),
      .bvalid       (bvalid     ),
      .bready       (bready     ),
    `endif
    
    `ifdef LS132R_INST_SRAM_IFC
      .inst_sram_cen    (inst_sram_cen  ),
      .inst_sram_wr     (inst_sram_wr   ),
      .inst_sram_addr   (inst_sram_addr ),
      .inst_sram_wdata  (inst_sram_wdata),
      .inst_sram_ack    (inst_sram_ack  ),
      .inst_sram_rrdy   (inst_sram_rrdy ),
      .inst_sram_rdata  (inst_sram_rdata),
    `endif
    
    `ifdef LS132R_DATA_SRAM_IFC
      .data_sram_cen    (data_sram_cen  ),
      .data_sram_wr     (data_sram_wr   ),
      .data_sram_addr   (data_sram_addr ),
      .data_sram_wdata  (data_sram_wdata),
      .data_sram_ack    (data_sram_ack  ),
      .data_sram_rrdy   (data_sram_rrdy ),
      .data_sram_rdata  (data_sram_rdata),
    `endif
    
      .clock_o      (clock          ),
      .reset_o      (reset          ),
      .hw_int_o     (hw_int         ),
    
      .idle_in_ifc_o(idle_in_ifc    ),

      .inst_ifc_i   (inst_ifc_bus   ),
      .ifc_inst_o   (ifc_inst_bus   ),

      .data_ifc_i   (data_ifc_bus   ),
      .ifc_data_o   (ifc_data_bus   )
    );



ls132r_fetch_stage
    u_fetch(
      .clock          (clock         ),
      .reset          (reset         ),
    
      .cpu_status_i   (cpu_status    ),
      .exbus_i        (exbus         ),
      .brbus_i        (brbus         ),
      .exe_status_i   (exe_status    ),
      .dec_status_i   (dec_status    ),
      .irbus_o        (irbus         ),
    
      .ifc_inst_i     (ifc_inst_bus  ),
      .inst_ifc_o     (inst_ifc_bus  ) 
    );



ls132r_decode_stage
    u_decode(
      .clock           (clock      ),
      .reset           (reset      ),
      .cpu_status_i    (cpu_status ),
      .exbus_i         (exbus      ),
      .brbus_i         (brbus      ),
      .ex_int_i        (ex_int     ),
      .irbus_i         (irbus      ),
      .wbbus_i         (wbbus      ),
      .issuebus_o      (issuebus   ),
      .dec_status_o    (dec_status ) 
    );



ls132r_execute_stage
    u_execute(
      .clock           (clock         ),
      .reset           (reset         ),
      .issuebus_i      (issuebus      ),
      .dec_status_i    (dec_status    ),
      .hw_int_i        (hw_int        ),
      .cpu_status_o    (cpu_status    ),
      .exbus_o         (exbus         ),
      .brbus_o         (brbus         ),
      .ex_int_o        (ex_int        ),
      .wbbus_o         (wbbus         ),
      .exe_status_o    (exe_status    ),
    
      .ifc_data_i      (ifc_data_bus  ),
      .data_ifc_o      (data_ifc_bus  )
    );


endmodule //ls132r_top

