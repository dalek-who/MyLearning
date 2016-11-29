module Reg_2_3(
	input clk,
	input reset, //高电平有�//寄存器组 Reg_2_3 �D 端输�	
	input pipe2_valid_out, 
	input [65:0] pipe2_ctrl_info_out, 
// ex_ades 65,ex_adel 64,ov 63,eret 62,int 61,syscall 60,break 59,id_ri_ex 58,if_adel 57,pc 56:25,dest 24:20,(|branch_type) 19,load_type 18:15,load_op 14,hi_we 13,lo_we 12,cp0_write 11,cs 10:6,sel [2:0] 5:3,wb_mux 2:1,reg_we 0
	input [33:0] pipe2_data_info_out,
//寄存器组 Reg_2_3 �Q 端输�	
	output pipe3_valid_in, //PIPE2有有效指令且准备�
	output [65:0] pipe3_ctrl_info_in,
	output [33:0] pipe3_data_info_in,
	//流水线控制信�	
	output pipe2_allow_out, 
	input pipe3_allow_in
);
	//寄存器组 Reg_2_3 �D �	
	wire Reg_2_3_D_valid; 
	wire [65:0] Reg_2_3_D_ctrl_info; 
	wire [33:0] Reg_2_3_D_data_info; //寄存器组 Reg_2_3 �Q �	
	reg Reg_2_3_Q_valid; 
	reg [65:0] Reg_2_3_Q_ctrl_info; 
	reg [33:0] Reg_2_3_Q_data_info;
	// Reg_2_3 �D 端输�来自 PIPE2
	assign Reg_2_3_D_valid = pipe2_valid_out; 
	assign Reg_2_3_D_ctrl_info = pipe2_ctrl_info_out; 
	assign Reg_2_3_D_data_info = pipe2_data_info_out;				   
		   // Reg_2_3 �Q 端输�去往 PIPE3
	assign pipe3_valid_in = Reg_2_3_Q_valid; 
	assign pipe3_ctrl_info_in = Reg_2_3_Q_ctrl_info; 
	assign pipe3_data_info_in = Reg_2_3_Q_data_info;
	//Reg_2_3
	always @(posedge clk) begin
		if (reset) begin
			Reg_2_3_Q_valid <= 1'b0; 
		end
		else if (pipe3_allow_in) begin
		Reg_2_3_Q_valid <= Reg_2_3_D_valid; 
		end
	end
	always @(posedge clk) begin
		if (reset) begin
			Reg_2_3_Q_ctrl_info <= 66'b0; 
			Reg_2_3_Q_data_info <= 34'b0;
		end
		else if (pipe3_allow_in && Reg_2_3_D_valid) begin
			Reg_2_3_Q_ctrl_info <= Reg_2_3_D_ctrl_info; 
			Reg_2_3_Q_data_info <= Reg_2_3_D_data_info;
		end 
	end
	// pipe2_allow_out
	assign pipe2_allow_out = pipe3_allow_in;
endmodule