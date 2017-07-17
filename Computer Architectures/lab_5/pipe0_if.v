module PIPE0( 
	input clk,
	// input reset,
	output [31:0]paddr,
	input [31:0]rom_data,
	// input pipe0_valid_in, 
	// input [XXX:0] pipe0_ctrl_info_in, 
	input [31:0]branch_imm,
	input [25:0]j_imm,
	input [31:0]jr_addr,
	// input nextpc_en,
	input br_taken,
	input j_taken,
	input jr_taken,
	input ex_taken,
	input [31:0]ex_addr,
	
	// input [YYY:0] pipe0_data_info_in,
	output pipe0_valid_out, //PIPE0有有效指令且准备�
	output [32:0] pipe0_ctrl_info_out,
	output [31:0] pipe0_data_info_out,
	input pipe0_allow_out //PIPE0指令允许进入下一流水�	
//	output pipe0_allow_in //PIPE 0 允许下一条指令进入本流水�
);
	//pipe0_valid
	// wire pipe0_valid;
	// assign pipe0_valid = pipe0_valid_in; 

	
	//流水线控制信�	
	reg [31:0]if_pc;
	wire [31:0]next_pc;
	wire [31:0]serial_pc_add_imm;
	wire [31:0]serial_and_branch_imm;
	wire [31:0]serial_and_branch;
	wire [31:0]j_addr;
	wire [31:0]serial_and_branch_and_j;
	assign nextpc_en = pipe0_allow_out && pipe0_rdy_go && ~if_adel;

	assign serial_pc_add_imm = (nextpc_en)?32'd4:32'd0;
	assign serial_and_branch_imm =(br_taken)?branch_imm:serial_pc_add_imm ;
	assign serial_and_branch = if_pc + serial_and_branch_imm;
	assign j_addr = {if_pc[31:28],j_imm,2'd0};
	assign serial_and_branch_and_j = (j_taken)?j_addr:serial_and_branch;
	
	// exl_addr_get EXL_ADDR_get(status_exl,cause_type,reset,cp0_epc,exl_addr,ex_taken);

	assign next_pc = (ex_taken)?ex_addr:
	(jr_taken)?jr_addr:serial_and_branch_and_j;	

	chg_vaddr CHG_VADDR(next_pc,paddr);

	wire if_adel;
	assign if_adel = if_pc[0] | if_pc[1];
	
	always @(posedge clk) begin
			if_pc<=next_pc;
	end
	//PIPE 0 模块,基本全组合逻辑
	wire pipe0_rdy_go; //PIPE 0 准备�	
	assign pipe0_rdy_go = 1;//由本级控制信号产�
	assign pipe0_valid_out = pipe0_rdy_go; 
	assign pipe0_ctrl_info_out = {if_adel,if_pc}; //由本级控制信号产�	
	assign pipe0_data_info_out = {rom_data};//由本级控制信号和数据产生
	// assign pipe0_allow_in = !pipe0_valid || pipe0_valid_out && pipe0_allow_out; 
endmodule
