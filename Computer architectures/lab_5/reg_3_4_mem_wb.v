module Reg_3_4(
	input clk,
	input reset, //高电平有�//寄存器组 Reg_3_4 �D 端输�
	input pipe3_valid_out, 
	input [60:0] pipe3_ctrl_info_out, 
	input [31:0] pipe3_data_info_out,
//寄存器组 Reg_3_4 �Q 端输�	
	output pipe4_valid_in, //PIPE3有有效指令且准备�
	output [60:0] pipe4_ctrl_info_in,
	output [31:0] pipe4_data_info_in,
	//流水线控制信�
	output pipe3_allow_out, 
	input pipe4_allow_in
);
	//寄存器组 Reg_3_4 �D �	
	wire Reg_3_4_D_valid; 
	wire [60:0] Reg_3_4_D_ctrl_info; 
	wire [31:0] Reg_3_4_D_data_info; //寄存器组 Reg_3_4 �Q �	
	reg Reg_3_4_Q_valid; 
	reg [60:0] Reg_3_4_Q_ctrl_info; 
	reg [31:0] Reg_3_4_Q_data_info;
	// Reg_3_4 �D 端输�来自 PIPE3
	assign Reg_3_4_D_valid = pipe3_valid_out; 
	assign Reg_3_4_D_ctrl_info = pipe3_ctrl_info_out; 
	assign Reg_3_4_D_data_info = pipe3_data_info_out;				   
		   // Reg_3_4 �Q 端输�去往 PIPE4
	assign pipe4_valid_in = Reg_3_4_Q_valid; 
	assign pipe4_ctrl_info_in = Reg_3_4_Q_ctrl_info; 
	assign pipe4_data_info_in = Reg_3_4_Q_data_info;
	//Reg_3_4
	always @(posedge clk) begin
		if (reset) begin
			Reg_3_4_Q_valid <= 1'b0; 
		end
		else if (pipe4_allow_in) begin
		Reg_3_4_Q_valid <= Reg_3_4_D_valid; 
		end
	end
	always @(posedge clk) begin
		if (reset) begin
			Reg_3_4_Q_ctrl_info <= 61'b0; 
			Reg_3_4_Q_data_info <= 32'b0;
		end
		else if (pipe4_allow_in && Reg_3_4_D_valid) begin
			Reg_3_4_Q_ctrl_info <= Reg_3_4_D_ctrl_info; 
			Reg_3_4_Q_data_info <= Reg_3_4_D_data_info;
		end 
	end
	// pipe3_allow_out
	assign pipe3_allow_out = pipe4_allow_in;
endmodule