module Reg_0_1(
	input clk,
	input reset, //高电平有�//寄存器组 Reg_0_1 �D 端输�	
	input pipe0_valid_out, 
	input [32:0] pipe0_ctrl_info_out, 
	input [31:0] pipe0_data_info_out,
//寄存器组 Reg_0_1 �Q 端输�	
	output pipe1_valid_in, //PIPE0有有效指令且准备�
	output [32:0] pipe1_ctrl_info_in,
	output [31:0] pipe1_data_info_in,
	//流水线控制信�
	output pipe0_allow_out, 
	input pipe1_allow_in,

//寄存器相关信�	
	// input we,
	// input [4:0]waddr,
	// input [31:0]wdata,
	// output [31:0]rdata1,
	// output [31:0]rdata2
	output [4:0]raddr1,
	output [4:0]raddr2
);
	//寄存器组 Reg_0_1 �D �
	wire Reg_0_1_D_valid; 
	wire [32:0] Reg_0_1_D_ctrl_info; 
	wire [31:0] Reg_0_1_D_data_info; //寄存器组 Reg_0_1 �Q �
	reg Reg_0_1_Q_valid; 
	reg [32:0] Reg_0_1_Q_ctrl_info; 
	reg [31:0] Reg_0_1_Q_data_info;
	// Reg_0_1 �D 端输�来自 PIPE0
	assign Reg_0_1_D_valid = pipe0_valid_out; 
	assign Reg_0_1_D_ctrl_info = pipe0_ctrl_info_out; 
	assign Reg_0_1_D_data_info = pipe0_data_info_out;				   
		   // Reg_0_1 �Q 端输�去往 PIPE1
	assign pipe1_valid_in = Reg_0_1_Q_valid; 
	assign pipe1_ctrl_info_in = Reg_0_1_Q_ctrl_info; 
	assign pipe1_data_info_in = Reg_0_1_Q_data_info;
	//Reg_0_1
	always @(posedge clk) begin
		if (reset) begin
			Reg_0_1_Q_valid <= 1'b0; 
		end
		else if (pipe1_allow_in) begin
		Reg_0_1_Q_valid <= Reg_0_1_D_valid; 
		end
	end
	always @(posedge clk) begin
		if (reset) begin
			Reg_0_1_Q_ctrl_info <= 33'b0; 
			Reg_0_1_Q_data_info <= 32'b0;
		end
		else if (pipe1_allow_in && Reg_0_1_D_valid) begin
			Reg_0_1_Q_ctrl_info <= Reg_0_1_D_ctrl_info; 
			Reg_0_1_Q_data_info <= Reg_0_1_D_data_info;
		end 
	end
	// pipe0_allow_out
	assign pipe0_allow_out = pipe1_allow_in;

	//wire [31:0]raddr1,raddr2;
	assign raddr1 = Reg_0_1_Q_data_info[25:21];
	assign raddr2 = Reg_0_1_Q_data_info[20:16];

endmodule