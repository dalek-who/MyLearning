/*
 * Functional Description:
 * 1. generate PC of the instruction to be fetched and send this PC to memory;
 * 2. wait instruction result back;
 * 3. latch the fetched instruction or exception signal to IR.
 *
 */
`include "ls132r_define.h"
module ls132r_fetch_stage(
  clock,
  reset,

  cpu_status_i,
  exbus_i,
  brbus_i,
  exe_status_i,
  dec_status_i,
  irbus_o,

  ifc_inst_i,
  inst_ifc_o 
);
input                       clock;
input                       reset;

input  [`Lcpustbus-1:0]     cpu_status_i;
input  [`Lexbus-1:0]        exbus_i;
input  [`Lbrbus-1:0]        brbus_i;
input  [`Lexestbus-1:0]     exe_status_i;
input  [`Ldecstbus-1:0]     dec_status_i;
output [`Lirbus-1:0]        irbus_o;
       
input  [`Lfromifcbus-1:0]   ifc_inst_i;
output [`Ltoifcbus-1:0]     inst_ifc_o;

wire        kernel_mode      = cpu_status_i[ 0: 0];
wire        super_mode       = cpu_status_i[ 1: 1];
wire        user_mode        = cpu_status_i[ 2: 2];
wire        cause_iv         = cpu_status_i[ 3: 3];
wire        status_bev       = cpu_status_i[ 4: 4];
wire        status_erl       = cpu_status_i[ 5: 5];
wire [ 2:0] config_cu        = cpu_status_i[ 8: 6];
wire [ 3:0] HWREna           = cpu_status_i[12: 9];
wire        debug_mode       = cpu_status_i[13:13];
wire 		dss_enable       = cpu_status_i[14:14];
wire        nodcr            = cpu_status_i[15:15];
wire        dint             = cpu_status_i[16:16];
wire        lsnm             = cpu_status_i[17:17];
wire [ 7:0] int_vec          = cpu_status_i[25:18];

wire        ex_valid         = exbus_i[ 0: 0];
wire        ex_delay1        = exbus_i[ 1: 1];
wire [ 5:0] excode_delay1    = exbus_i[ 7: 2];
wire [ 5:0] ex_excode        = exbus_i[13: 8];

wire        br_cancel        = brbus_i[ 0: 0]; 
wire        br_not_taken     = brbus_i[ 1: 1];
wire        br_likely        = brbus_i[ 2: 2];
wire [31:0] br_base          = brbus_i[34: 3];
wire [31:0] br_offset        = brbus_i[66:35];

wire        rs_allowin       = exe_status_i[ 0: 0];
wire        ctrl_stall_in_rs = exe_status_i[ 1: 1];
wire        idle_in_rs       = exe_status_i[ 2: 2];
wire        deret_complete   = exe_status_i[ 3: 3];

wire        ctrl_stall_in_ir = dec_status_i[ 0: 0];
wire        br_in_ir         = dec_status_i[ 1: 1];
wire        wait_sleep       = dec_status_i[ 2: 2];
wire        bd_in_ir         = dec_status_i[ 3: 3];
wire [31:0] bd_pc            = dec_status_i[35: 4];
wire        idle_in_ir       = dec_status_i[36:36];

wire        ir_valid  ;
wire [31:0] ir_pc     ;
wire [31:0] ir_inst   ;
wire        ir_bd     ;
wire        ir_ex_adel;
wire        ir_ex_dib ;

assign irbus_o[ 0: 0] = ir_valid  ;
assign irbus_o[32: 1] = ir_pc     ;
assign irbus_o[64:33] = ir_inst   ;
assign irbus_o[65:65] = ir_bd     ;
assign irbus_o[66:66] = ir_ex_adel;
assign irbus_o[67:67] = ir_ex_dib ;

wire        inst_ifc_ack    = ifc_inst_i[ 0: 0];
wire        inst_ifc_rrdy   = ifc_inst_i[ 1: 1];
wire [31:0] inst_ifc_rdata  = ifc_inst_i[33: 2];

wire        inst_ifc_valid;
wire [ 3:0] inst_ifc_width;
wire [ 3:0] inst_ifc_ben  ;
wire        inst_ifc_wr   ;
wire [31:0] inst_ifc_addr ;
wire [31:0] inst_ifc_wdata;

assign inst_ifc_o[ 0: 0] = inst_ifc_valid;
assign inst_ifc_o[ 4: 1] = inst_ifc_width;
assign inst_ifc_o[ 8: 5] = inst_ifc_ben  ;
assign inst_ifc_o[ 9: 9] = inst_ifc_wr   ;
assign inst_ifc_o[41:10] = inst_ifc_addr ;
assign inst_ifc_o[73:42] = inst_ifc_wdata;


/*
 *  Internal Signals and Registers
 */

// PC
wire        pipe_ctrl_stall;
wire        inst_rrdy_no_bus;
wire        pc_out_valid;
wire [31:0] pc_adder_a;
wire [31:0] pc_adder_b;
wire [31:0] pc_adder_res;
wire        ex_ejtag;
wire [31:0] int_entry_bev0;
wire [31:0] int_entry_bev1;
wire [31:0] ex_entry;
wire [31:0] pc_out;
wire        pc_kseg3;
wire        pc_kseg2;
wire        pc_kseg1;
wire        pc_kseg0;
wire        pc_useg;
wire        pc_ex_adel;


// FETCH
parameter EMPTY        = 3'b000;
parameter FETCH        = 3'b001;
parameter STALL        = 3'b010;
parameter FULL         = 3'b011;
parameter STALL_CANCEL = 3'b100;

wire        inst_empty;
wire        inst_fetch;
wire        inst_stall;
wire        inst_full;
wire        inst_stall_cancel;

wire        ex_req;
wire        br_req;
wire        br_stall;
wire        jump_req;

wire        empty_to_fetch;
wire        empty_to_stall;
wire        fetch_to_empty;
wire        fetch_to_full;
wire        fetch_to_fetch;
wire        fetch_to_stall;
wire        fetch_to_stall_cancel;
wire        stall_to_fetch;
wire        stall_to_stall;
wire        full_to_empty;
wire        full_to_fetch;
wire        full_to_stall;
wire        stall_cancel_to_stall;
wire        stall_cancel_to_new_stall;
wire        stall_cancel_to_stall_cancel;
wire        stall_cancel_to_fetch;
wire        fsm_to_empty;
wire        fsm_to_fetch;
wire        fsm_to_stall;
wire        fsm_to_full;
wire        fsm_to_stall_cancel;
wire        change_inst_code;
wire        change_inst_info;
wire        change_inst_pc;


reg  [ 2:0] inst_fsm_r;
reg         inst_ex_adel_r;
reg  [31:0] inst_pc_r;
reg  [31:0] inst_code_r;


// IR
reg         ir_valid_r;
reg  [31:0] ir_pc_r;
reg  [31:0] ir_inst_r;
reg         ir_bd_r;
reg         ir_ex_adel_r;

wire        ir_allowin;
wire        ir_cango;
wire        ir_cancel;
wire        ir_brlky_cancel;

wire        new_inst_in;
wire [31:0] new_inst_code;


// MEM
wire [31:0] pc_paddr; 
wire        pc_dmseg;

wire        mem_ack;
wire        mem_rrdy;
wire [31:0] mem_rdata;

wire        pc_ack;
wire        inst_rrdy;

/*
 *  Internal Logic
 */

// PC
assign pipe_ctrl_stall  = wait_sleep       || 
                          ctrl_stall_in_ir || ctrl_stall_in_rs;

assign inst_rrdy_no_bus = inst_ex_adel_r;

assign pc_out_valid = inst_ifc_rrdy && 
                        (!pipe_ctrl_stall && !reset &&
                            (!inst_ex_adel_r && (inst_fetch && (ir_allowin || jump_req) || inst_stall_cancel)
                            )
                        )
                   || !pipe_ctrl_stall && !reset &&
                        (inst_rrdy_no_bus && (inst_fetch && (ir_allowin || jump_req) || inst_stall_cancel) ||
                         inst_empty ||
                         inst_stall ||
                         inst_full && (ir_allowin || jump_req)
                        );
// EXPLANATION:
// !reset &&  (
//      inst_empty && !pipe_ctrl_stall
//   || inst_fetch && inst_rrdy && (ir_allowin || jump_req) && !pipe_ctrl_stall
//   || inst_stall && !pipe_ctrl_stall
//   || inst_full  && (ir_allowin || jump_req) && !pipe_ctrl_stall
//   || inst_stall_cancel && inst_rrdy && !pipe_ctrl_stall
// )

assign pc_adder_a   = br_cancel ? br_base   : inst_pc_r;

assign pc_adder_b   = br_cancel ? br_offset : 32'h4;

assign pc_adder_res = pc_adder_a + pc_adder_b;

assign int_entry_bev0 = int_vec[7] ? `LS132R_INT7_ENTRY_BEV0 :
                        int_vec[6] ? `LS132R_INT6_ENTRY_BEV0 :
                        int_vec[5] ? `LS132R_INT5_ENTRY_BEV0 :
                        int_vec[4] ? `LS132R_INT4_ENTRY_BEV0 :
                        int_vec[3] ? `LS132R_INT3_ENTRY_BEV0 :
                        int_vec[2] ? `LS132R_INT2_ENTRY_BEV0 :
                        int_vec[1] ? `LS132R_INT1_ENTRY_BEV0 :
                                     `LS132R_INT0_ENTRY_BEV0 ;

assign ex_entry = status_bev ? 32'hbfc0_0380   
                : ((excode_delay1==`LS132R_EX_INT && cause_iv) ? int_entry_bev0 : 32'h8000_0180);

assign pc_out   = ex_delay1          ? ex_entry     :
                  br_cancel          ? pc_adder_res :
   (inst_stall || inst_stall_cancel) ? inst_pc_r    :
                                       pc_adder_res; //next pc

assign pc_useg    = pc_out[31   ]==1'b0;
assign pc_kseg0   = pc_out[31:29]==3'b100;
assign pc_kseg1   = pc_out[31:29]==3'b101;
assign pc_kseg2   = pc_out[31:29]==3'b110;
assign pc_kseg3   = pc_out[31:29]==3'b111;
assign pc_ex_adel = (|pc_out[1:0]) || 
                    user_mode && !pc_useg  ||
                    super_mode && (pc_kseg0 || pc_kseg1 || pc_kseg3);


// FETCH
assign inst_empty        = inst_fsm_r==EMPTY;
assign inst_fetch        = inst_fsm_r==FETCH;
assign inst_stall        = inst_fsm_r==STALL;
assign inst_full         = inst_fsm_r==FULL;
assign inst_stall_cancel = inst_fsm_r==STALL_CANCEL;


assign ex_req           = ex_delay1;
assign br_req           = br_cancel && !pipe_ctrl_stall;
assign br_stall         = br_cancel &&  pipe_ctrl_stall; 
assign jump_req         = ex_req || br_cancel;

assign empty_to_fetch   = inst_empty &&   pc_ack && !pipe_ctrl_stall;
assign empty_to_stall   = inst_empty && (!pc_ack && !pipe_ctrl_stall && jump_req ||
                                          br_stall 
                                        );

assign fetch_to_empty   = inst_fetch && inst_rrdy &&  !pc_ack && !pipe_ctrl_stall &&  ir_allowin && !jump_req;
assign fetch_to_full    = inst_fetch && inst_rrdy             && !pipe_ctrl_stall && !ir_allowin && !jump_req;
assign fetch_to_fetch   = inst_fetch && inst_rrdy &&   pc_ack && !pipe_ctrl_stall && (ir_allowin ||  jump_req);
assign fetch_to_stall   = inst_fetch && inst_rrdy && (!pc_ack && !pipe_ctrl_stall && jump_req ||
                                                      br_stall ||
                                                      pipe_ctrl_stall && !jump_req
                                                     );
assign fetch_to_stall_cancel  
                        = inst_fetch && !inst_rrdy && (jump_req || pipe_ctrl_stall);

assign stall_to_fetch   = inst_stall &&   pc_ack && !pipe_ctrl_stall;
assign stall_to_stall   = inst_stall && (!pc_ack && !pipe_ctrl_stall && jump_req ||
                                         br_stall
                                        );

assign full_to_empty    = inst_full  &&  !pc_ack && !pipe_ctrl_stall &&  ir_allowin && !jump_req;
assign full_to_fetch    = inst_full  &&   pc_ack && !pipe_ctrl_stall && (ir_allowin ||  jump_req);
assign full_to_stall    = inst_full  && (!pc_ack && !pipe_ctrl_stall && jump_req ||
                                         br_stall
                                        );

assign stall_cancel_to_stall
                        = inst_stall_cancel &&  inst_rrdy && (!pc_ack && !pipe_ctrl_stall ||
                                                              br_stall
                                                             );
assign stall_cancel_to_new_stall 
                        = inst_stall_cancel &&  inst_rrdy && (!pc_ack && !pipe_ctrl_stall && jump_req ||
                                                              br_stall
                                                             );

assign stall_cancel_to_fetch
                        = inst_stall_cancel &&  inst_rrdy &&   pc_ack && !pipe_ctrl_stall;

assign stall_cancel_to_stall_cancel
                        = inst_stall_cancel && !inst_rrdy && (!pipe_ctrl_stall && jump_req ||
                                                              br_stall
                                                             );

assign fsm_to_empty         = fetch_to_empty || full_to_empty; 

assign fsm_to_fetch         = empty_to_fetch || stall_to_fetch || full_to_fetch ||
                              stall_cancel_to_fetch;

assign fsm_to_stall         = empty_to_stall || fetch_to_stall || full_to_stall ||
                              stall_cancel_to_stall;

assign fsm_to_full          = fetch_to_full; 

assign fsm_to_stall_cancel  = fetch_to_stall_cancel;

assign change_inst_code     = fetch_to_full;

assign change_inst_info     = empty_to_fetch || fetch_to_fetch || stall_to_fetch ||
                              full_to_fetch  || stall_cancel_to_fetch;

assign change_inst_pc       = (change_inst_info ||
                               empty_to_stall || fetch_to_stall ||
                               stall_to_stall || fetch_to_stall_cancel ||
                               full_to_stall  || stall_cancel_to_new_stall ||
                               stall_cancel_to_stall_cancel) && 
                             !(inst_fetch && !jump_req && pipe_ctrl_stall);

always @(posedge clock)
begin
  if      (reset              ) inst_fsm_r <= STALL;
  else if (fsm_to_empty       ) inst_fsm_r <= EMPTY;
  else if (fsm_to_fetch       ) inst_fsm_r <= FETCH;
  else if (fsm_to_stall       ) inst_fsm_r <= STALL;
  else if (fsm_to_full        ) inst_fsm_r <= FULL;
  else if (fsm_to_stall_cancel) inst_fsm_r <= STALL_CANCEL;

  if (reset)
  begin
    inst_ex_adel_r <= 1'b0;
  end
  else if (change_inst_info)
  begin
    inst_ex_adel_r <= pc_ex_adel;
  end

  if (reset)
    inst_pc_r <= 32'hbfc0_0000;
  else if (change_inst_pc)
    inst_pc_r <= pc_out;


  if (change_inst_code)
    inst_code_r <= mem_rdata;

end



// IR
assign ir_allowin      = !ir_valid_r || ir_cango;
assign ir_cango        = rs_allowin;
assign ir_cancel       = ex_valid;
assign ir_brlky_cancel = br_not_taken && br_likely && ir_bd_r;

assign new_inst_in   = !ex_valid && !jump_req && ir_allowin &&
                      (inst_fetch && inst_rrdy || inst_full);

assign new_inst_code = inst_full ? inst_code_r : mem_rdata;

always @(posedge clock)
begin
  if (reset || ir_valid_r && ir_cancel)
    ir_valid_r  <= 1'b0;
  else if (new_inst_in)
    ir_valid_r  <= 1'b1;
  else if (ir_valid_r && ir_cango)
    ir_valid_r  <= 1'b0;

  if (new_inst_in)
  begin
    ir_pc_r      <= inst_pc_r;
    ir_inst_r    <= new_inst_code;
    ir_ex_adel_r <= inst_ex_adel_r;
  end

  if (reset || ir_valid_r && ir_cancel)
    ir_bd_r <= 1'b0;
  else if (ir_valid_r && ir_cango && br_in_ir)
    ir_bd_r <= 1'b1;
  else if (ir_valid_r && ir_cango && ir_bd_r)
    ir_bd_r <= 1'b0;
end

// MEM 
assign pc_paddr[28: 0] = pc_out[28: 0];
assign pc_paddr[31:29] = 
                     pc_useg  ? {( status_erl && !pc_out[30]) ? 2'b00 :
                                 ( status_erl &&  pc_out[30]) ? 2'b01 :
                                 (!status_erl && !pc_out[30]) ? 2'b01 : 2'b10
                                 , pc_out[29]} :
       (pc_kseg0 || pc_kseg1) ? 3'b000 :
                                pc_out[31:29]; //kseg2 or kseg3
// EXPLANATION:
// assign pc_paddr[31:29] = 
//        d_useg  ? (status_erl ? mem_vaddr[31:29] : mem_vaddr[31:29]+2'b10) :
//        d_kseg0 ? 3'b000 : 
//        d_kseg1 ? 3'b000 : 
//                  mem_vaddr[31:29]; //kseg2 or kseg3

assign mem_ack   = inst_ifc_ack;
assign mem_rrdy  = inst_ifc_rrdy;
assign mem_rdata = inst_ifc_rdata;

assign pc_ack    = mem_ack || pc_ex_adel;
assign inst_rrdy = mem_rrdy || inst_ex_adel_r;

// OUTPUT
// inst_ifc_o
assign inst_ifc_valid = pc_out_valid && !pc_ex_adel;
assign inst_ifc_width = `LS132R_WIDTH_32BIT;
assign inst_ifc_ben   = 4'hf;
assign inst_ifc_wr    = 1'b0;
assign inst_ifc_addr  = pc_paddr[31:0];
assign inst_ifc_wdata = 32'h0;

// irbus_o
assign ir_valid   = ir_valid_r;
assign ir_pc      = ir_pc_r;
assign ir_inst    = ir_inst_r;
assign ir_bd      = ir_bd_r;
assign ir_ex_adel = ir_ex_adel_r;
assign ir_ex_dib  = 1'b0;


endmodule //ls132r_fetch_stage



