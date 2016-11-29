module Reg_1_2(
	input clk,
	input reset, //高电平有�//寄存器组 Reg_1_2 �D 端输�	
	input pipe1_valid_out, 
	input [81:0] pipe1_ctrl_info_out, 
// eret 81,int 80,syscall 79,break 78,id_ri_ex 77,if_adel 76,pc 75:44,dest 43:39,(|branch_type) 38,bypass_op 37 ,logic_type 36:32,shift_type 31:29,imm_op 28,unsigned_op 27,sub_op 26,link_op 25,store_type 24:22 ,store_op 21,alu_res_sel 20:19,load_type 18:15,load_op 14,hi_we 13,lo_we 12,cp0_write 11,cs 10:6,sel [2:0] 5:3,wb_mux 2:1,reg_we 0
	input [79:0] pipe1_data_info_out,
// vsrc1 79:48 vsrc2 47:16 imm 15:0


//寄存器组 Reg_1_2 �Q 端输�	
	output pipe2_valid_in, //PIPE1有有效指令且准备�
	output [81:0] pipe2_ctrl_info_in,
	output [79:0] pipe2_data_info_in,
	//流水线控制信�	
	output pipe1_allow_out, 
	input pipe2_allow_in
);
	//寄存器组 Reg_1_2 �D �	
	wire Reg_1_2_D_valid; 
	wire [81:0] Reg_1_2_D_ctrl_info; 
	wire [79:0] Reg_1_2_D_data_info; //寄存器组 Reg_1_2 �Q �	
	reg Reg_1_2_Q_valid; 
	reg [81:0] Reg_1_2_Q_ctrl_info; 
	reg [79:0] Reg_1_2_Q_data_info;
	// Reg_1_2 �D 端输�来自 PIPE1
	assign Reg_1_2_D_valid = pipe1_valid_out; 
	assign Reg_1_2_D_ctrl_info = pipe1_ctrl_info_out; 
	assign Reg_1_2_D_data_info = pipe1_data_info_out;				   
		   // Reg_1_2 �Q 端输�去往 PIPE2
	assign pipe2_valid_in = Reg_1_2_Q_valid; 
	assign pipe2_ctrl_info_in = Reg_1_2_Q_ctrl_info; 
	assign pipe2_data_info_in = Reg_1_2_Q_data_info;
	//Reg_1_2
	always @(posedge clk) begin
		if (reset) begin
			Reg_1_2_Q_valid <= 1'b0; 
		end
		else if (pipe2_allow_in) begin
		Reg_1_2_Q_valid <= Reg_1_2_D_valid; 
		end
	end
	always @(posedge clk) begin
		if (reset) begin
			Reg_1_2_Q_ctrl_info <= 82'b0; 
			Reg_1_2_Q_data_info <= 80'b0;
		end
		else if (pipe2_allow_in && Reg_1_2_D_valid) begin
			Reg_1_2_Q_ctrl_info <= Reg_1_2_D_ctrl_info; 
			Reg_1_2_Q_data_info <= Reg_1_2_D_data_info;
		end 
	end
	// pipe1_allow_out
	assign pipe1_allow_out = pipe2_allow_in; 
endmodule