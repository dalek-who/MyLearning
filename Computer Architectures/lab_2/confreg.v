/**********************************
*
*   confreg module  <liusu-cpu@ict.ac.cn>
*   32 bit AXI port/ 8*32bit confreg
*
**********************************/
`include "../TOP/config.h"
module confreg(
    aclk,
    aresetn,

    s_awid,
    s_awaddr,
    s_awlen,
    s_awsize,
    s_awburst,
    s_awlock,
    s_awcache,
    s_awprot,
    s_awvalid,
    s_awready,
    s_wid,
    s_wdata,
    s_wstrb,
    s_wlast,
    s_wvalid,
    s_wready,
    s_bid,
    s_bresp,
    s_bvalid,
    s_bready,
    s_arid,
    s_araddr,
    s_arlen,
    s_arsize,
    s_arburst,
    s_arlock,
    s_arcache,
    s_arprot,
    s_arvalid,
    s_arready,
    s_rid,
    s_rdata,
    s_rresp,
    s_rlast,
    s_rvalid,
    s_rready,
    
    cr00,
    cr01,
    cr02,
    cr03,
    cr04,
    cr05,
    cr06,
    cr07,

    cr00_in,
    cr01_in,
    cr02_in,
    cr03_in,
    cr04_in,
    cr05_in,
    cr06_in,
    cr07_in
);
    input           aclk;
    input           aresetn;

    input  [`LID         -1 :0] s_awid;
    input  [`Lawaddr     -1 :0] s_awaddr;
    input  [`Lawlen      -1 :0] s_awlen;
    input  [`Lawsize     -1 :0] s_awsize;
    input  [`Lawburst    -1 :0] s_awburst;
    input  [`Lawlock     -1 :0] s_awlock;
    input  [`Lawcache    -1 :0] s_awcache;
    input  [`Lawprot     -1 :0] s_awprot;
    input                       s_awvalid;
    output                      s_awready;
    input  [`LID         -1 :0] s_wid;
    input  [`Lwdata      -1 :0] s_wdata;
    input  [`Lwstrb      -1 :0] s_wstrb;
    input                       s_wlast;
    input                       s_wvalid;
    output                      s_wready;
    output [`LID         -1 :0] s_bid;
    output [`Lbresp      -1 :0] s_bresp;
    output                      s_bvalid;
    input                       s_bready;
    input  [`LID         -1 :0] s_arid;
    input  [`Laraddr     -1 :0] s_araddr;
    input  [`Larlen      -1 :0] s_arlen;
    input  [`Larsize     -1 :0] s_arsize;
    input  [`Larburst    -1 :0] s_arburst;
    input  [`Larlock     -1 :0] s_arlock;
    input  [`Larcache    -1 :0] s_arcache;
    input  [`Larprot     -1 :0] s_arprot;
    input                       s_arvalid;
    output                      s_arready;
    output [`LID         -1 :0] s_rid;
    output [`Lrdata      -1 :0] s_rdata;
    output [`Lrresp      -1 :0] s_rresp;
    output                      s_rlast;
    output                      s_rvalid;
    input                       s_rready;
    
    output [31:0]    cr00;
    output [31:0]    cr01;
    output [31:0]    cr02;
    output [31:0]    cr03;
    output [31:0]    cr04;
    output [31:0]    cr05;
    output [31:0]    cr06;
    output [31:0]    cr07;

    input [31:0]    cr00_in;
    input [31:0]    cr01_in;
    input [31:0]    cr02_in;
    input [31:0]    cr03_in;
    input [31:0]    cr04_in;
    input [31:0]    cr05_in;
    input [31:0]    cr06_in;
    input [31:0]    cr07_in;

// 
reg [31:0] cr00,cr01,cr02,cr03,cr04,cr05,cr06,cr07;
reg busy,write,R_or_W;
reg s_wready;

wire ar_enter = s_arvalid & s_arready;
wire r_retire = s_rvalid & s_rready & s_rlast;
wire aw_enter = s_awvalid & s_awready;
wire w_enter  = s_wvalid & s_wready & s_wlast;
wire b_retire = s_bvalid & s_bready;

wire s_arready = ~busy & (!R_or_W| !s_awvalid);
wire s_awready = ~busy & ( R_or_W| !s_arvalid);

always@(posedge aclk)
    if(~aresetn) busy <= 1'b0;
    else if(ar_enter|aw_enter) busy <= 1'b1;
    else if(r_retire|b_retire) busy <= 1'b0;

reg [`LID         -1 :0] buf_id;
reg [`Lawaddr     -1 :0] buf_addr;
reg [`Lawlen      -1 :0] buf_len;
reg [`Lawsize     -1 :0] buf_size;
reg [`Lawburst    -1 :0] buf_burst;
reg [`Lawlock     -1 :0] buf_lock;
reg [`Lawcache    -1 :0] buf_cache;
reg [`Lawprot     -1 :0] buf_prot;

always@(posedge aclk)
    if(~aresetn) begin
        R_or_W      <= 1'b0;
        buf_id      <= 'b0;
        buf_addr    <= 'b0;
        buf_len     <= 'b0;
        buf_size    <= 'b0;
        buf_burst   <= 'b0;
        buf_lock    <= 'b0;
        buf_cache   <= 'b0;
        buf_prot    <= 'b0;
    end
    else
    if(ar_enter | aw_enter) begin
        R_or_W      <= ar_enter;
        buf_id      <= ar_enter ? s_arid   : s_awid   ;
        buf_addr    <= ar_enter ? s_araddr : s_awaddr ;
        buf_len     <= ar_enter ? s_arlen  : s_awlen  ;
        buf_size    <= ar_enter ? s_arsize : s_awsize ;
        buf_burst   <= ar_enter ? s_arburst: s_awburst;
        buf_lock    <= ar_enter ? s_arlock : s_awlock ;
        buf_cache   <= ar_enter ? s_arcache: s_awcache;
        buf_prot    <= ar_enter ? s_arprot : s_awprot ;
    end

always@(posedge aclk)
    if(~aresetn) write <= 1'b0;
    else if(aw_enter) write <= 1'b1;
    else if(ar_enter)  write <= 1'b0;

always@(posedge aclk)
    if(~aresetn) s_wready <= 1'b0;
    else if(aw_enter) s_wready <= 1'b1;
    else if(w_enter & s_wlast) s_wready <= 1'b0;



assign key_on = |cr06[4:0];
reg software_change;
reg [31:0] count;
reg [4:0]tempkey;
reg [4:0]tempkey1;
wire [4:0]key_diff;
always @(posedge aclk or negedge aresetn) begin
    if (~aresetn) begin
        // reset
        tempkey<='b0;
    end
    else begin
        tempkey<=cr06_in[4:0];
    end
end
always @(posedge aclk or negedge aresetn) begin
    if (~aresetn) begin
        // reset
        tempkey1<='b0;
    end
    else begin
        tempkey1<=tempkey;
    end
end
assign key_diff = tempkey ^ tempkey1;

always @(posedge aclk or negedge aresetn) begin
    if (~aresetn) begin
        // reset
        cr06<='d0;
		   count<='d0;
    end
	else if (key_diff) begin
        count<='d0;
    end
	else if (count==32'hA1220) begin
        // for test
        // if(count==32'h19c8)begin
        count<='d0;
        cr06 <= cr06_in;
    end
	 else begin
		count<=count + 1;
	 end
end

always @(posedge cr06[1] or negedge aresetn) begin
    if (~aresetn) begin
        cr04 <= 'b0;
    end
    else begin
        cr04[0] <= ~cr04[0];
    end
end


always@(posedge aclk)
    if(~aresetn) begin
        cr00 <= 'b0;  // sd_config_low
        cr01 <= 'b0;  // sd_config_high
        cr02 <= 'b0;  // sram_ctrl
        cr03 <= 'b0;
      //  cr04 <= 'b0;
        cr05 <= 'b0;
        //cr06 <= 'b0;
        cr07 <= 'b0;
        software_change<=0;
        //count<=0;
    end
    else begin 
        if(w_enter) begin
            case (buf_addr[4:2])
                3'd0: cr00 <= s_wdata;
                3'd1: cr01 <= s_wdata;
                3'd2: cr02 <= s_wdata;
                3'd3: cr03 <= s_wdata;
                // 3'd4: cr04 <= s_wdata;
                3'd5:begin
                    cr05 <= cr05^s_wdata;
                    software_change<=1;
                end 
                // 3'd6: cr06 <= s_wdata;
                // 3'd7: cr07 <= s_wdata;
            endcase
        end
        else begin 
            if(~key_on)
                software_change<=0;
            if(~software_change)
                cr05<= cr06;
        end
    end


// assign key_on = |cr06[4:0];

// reg software_change;
// reg [31:0] count;

// always @(posedge cr06[1] or negedge aresetn) begin
//     if (~aresetn) begin
//         cr04 <= 'b0;
//     end
//     else begin
//         cr04[0] <= ~cr04[0];
//     end
// end
// always@(posedge aclk)
//     if(~aresetn) begin
//         cr00 <= 'b0;  // sd_config_low
//         cr01 <= 'b0;  // sd_config_high
//         cr02 <= 'b0;  // sram_ctrl
//         cr03 <= 'b0;
//         cr04 <= 'b0;
//         cr05 <= 'b0;
//         cr06 <= 'b0;
//         cr07 <= 'b0;
//         software_change<=0;
//         count<=0;
//     end
//     else begin 
//         if(w_enter) begin
//             case (buf_addr[4:2])
//                 3'd0: cr00 <= s_wdata;
//                 3'd1: cr01 <= s_wdata;
//                 3'd2: cr02 <= s_wdata;
//                 3'd3: cr03 <= s_wdata;
//                 // 3'd4: cr04 <= s_wdata;
//                 3'd5:begin
//                     cr05 <= cr05^s_wdata;
//                     software_change<=1;
//                 end 
//                 // 3'd6: cr06 <= s_wdata;
//                 // 3'd7: cr07 <= s_wdata;
//             endcase
//         end
//         else begin 
//             if(~key_on)
//                 software_change<=0;
//             if(~software_change)
//                 cr05<= cr06;
//         end

//         if (count==32'hA1220) begin
//         // for test
//         // if(count==32'h19c8)begin
//             count<=0;
//             cr06 <= cr06_in;
//         end
//         else begin
//             count<=count+1;
//         end

//     end

reg [`Lrdata-1:0] s_rdata;
reg s_rvalid,s_rlast;
wire [`Lrdata-1:0] rdata_d = buf_addr[4:2] == 3'd0 ? cr00 :
                      buf_addr[4:2] == 3'd1 ? cr01 :
                      buf_addr[4:2] == 3'd2 ? cr02 :
                      buf_addr[4:2] == 3'd3 ? cr03 :
                      buf_addr[4:2] == 3'd4 ? cr04 :
                      buf_addr[4:2] == 3'd5 ? cr05 :
                      buf_addr[4:2] == 3'd6 ? cr06 : cr07;
                      

always@(posedge aclk)
    if(~aresetn) begin
        s_rdata  <= 'b0;
        s_rvalid <= 1'b0;
        s_rlast  <= 1'b0;
    end
    else if(busy & !write & !r_retire)
    begin
        s_rdata <= rdata_d;
        s_rvalid <= 1'b1;
        s_rlast <= 1'b1; 
    end
    else if(r_retire)
    begin
        s_rvalid <= 1'b0;
    end

reg s_bvalid;
always@(posedge aclk)   
    if(~aresetn) s_bvalid <= 1'b0;
    else if(w_enter) s_bvalid <= 1'b1;
    else if(b_retire) s_bvalid <= 1'b0;

assign s_rid = buf_id;
assign s_bid = buf_id;
assign s_bresp = 2'b0;
assign s_rresp = 2'b0;

endmodule
