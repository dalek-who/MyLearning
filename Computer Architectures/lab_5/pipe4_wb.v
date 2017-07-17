/*module PIPE4(
	.clk(),
	.rst(),
	.pipe4_valid_in(), 
	.pipe4_ctrl_info_in(), 
	.pipe4_data_info_in(),
	.pipe4_ctrl_info_out(), 
	.pipe4_data_info_out(),
	.pipe4_allow_out(), //PIPE4指令允许进入下一流水�
	.pipe4_allow_in() //PIPE 4 允许下一条指令进入本流水�
);*/
module PIPE4(
	input clk,
	input FPGA_rst,
	output rst,
	input pipe4_valid_in,
	input [60:0] pipe4_ctrl_info_in,
	input [31:0] pipe4_data_info_in,
	// output [XXX:0] pipe4_ctrl_info_out, 
	// output [YYY:0] pipe4_data_info_out,
	output [31:0]wdata,
	output we,
	output [4:0]waddr,
	output [4:0]e_cause,
	output is_exl,
	output [31:0]e_pc,
	output eret,
	output pipe4_allow_in,

	output pipe4_valid_out,
	output [31:0]wb_pc
);
//pipe4_valid
	wire pipe4_valid;
	assign pipe4_valid = pipe4_valid_in;

	reg reset1,reset2;
	always @(posedge clk) begin
		reset2 <= reset1;
		reset1 <= FPGA_rst;
	end
	assign rst = reset2 & ~reset1;

	wire [1:0]option;
	assign option = pipe4_ctrl_info_in[13:12];
	reg [31:0]HI,LO;
	always @(posedge clk or posedge rst) begin
		if (rst) begin
			HI <= 32'b0;
			LO <= 32'b0;
		end
		else if (option[1]) begin
			HI <= pipe4_data_info_in;
		end
		else if (option[0]) begin
			LO <= pipe4_data_info_in;
		end
	end

	wire [31:0]PC_in;
	assign PC_in = pipe4_ctrl_info_in[51:20];
	wire [31:0]PC_out;
	assign PC_out = (is_bd_out) ? PC_in - 4: PC_in;
	wire is_bd_in;
	assign is_bd_in = pipe4_ctrl_info_in[14];
	wire is_bd_out;
	wire [2:0]sel;
	assign sel = pipe4_ctrl_info_in[5:3];
	wire [4:0]cscd;
	assign cscd = pipe4_ctrl_info_in[10:6];
	assign eret = pipe4_ctrl_info_in[57];
	wire [7:0]cp0_e_op;
	assign cp0_e_op = {pipe4_ctrl_info_in[60:58],pipe4_ctrl_info_in[56:52]};
	wire cp0_write;
	assign cp0_write = pipe4_ctrl_info_in[11];
	wire [31:0]data_in;
	assign data_in = (is_exl) ? PC_out : pipe4_data_info_in;
	wire [37:0]cp0_e_out;
	wire [31:0]data_out;
	cp0_reg aaa(
		.clk		(clk),
		.rst		(rst),
		.data_out 	(data_out),
		.data_in 	(data_in),
		.cscd		(cscd),//MTC0,MFC0
		.sel		(sel),//MTC0,MFC0,no use
		.write		(cp0_write),//MTC0
		.e_op		(cp0_e_op),//ADEL,RI,BREAK,SYSCALL,INT,OV,ADEL,ADES
		.e_in		(PC_out),
		.e_out		(cp0_e_out),//e_out = {cp0_12_status[1],cp0_13_cause[6:2],cp0_14_epc};
		.is_bd_in	(is_bd_in),
		.is_bd_out	(is_bd_out),
		.eret 		(eret));//ERET

	wire [1:0]wb_mux;
	assign wb_mux = pipe4_ctrl_info_in[2:1];
	assign wdata =  {32{wb_mux == 2'b00}} & pipe4_data_info_in 	|
					{32{wb_mux == 2'b01}} & data_out			|
					{32{wb_mux == 2'b10}} & LO					|
					{32{wb_mux == 2'b11}} & HI					;

	assign we = pipe4_ctrl_info_in[0] & pipe4_valid &(~is_exl);
	assign waddr = pipe4_ctrl_info_in[19:15];

	assign is_exl = |pipe4_ctrl_info_in[60:52];
	
	assign e_cause = cp0_e_out[36:32];
	assign e_pc = cp0_e_out[31:0];


	wire pipe4_rdy_go;
	assign pipe4_rdy_go = 1; 
	assign pipe4_valid_out = pipe4_valid && pipe4_rdy_go; 
	assign pipe4_allow_in = !pipe4_valid || pipe4_valid_out;
	assign wb_pc = PC_in;

endmodule

module cp0_reg(clk,rst,data_out,data_in,cscd,sel,write,e_op,e_in,e_out,is_bd_in,is_bd_out,eret);
	input clk;
	input rst;
	output [31:0]data_out;	
	input  [31:0]data_in;
	input  [ 4:0]cscd;
	input  [ 2:0]sel;
	input write;
	input [7:0]e_op;	
	input [31:0]e_in;
	output [37:0]e_out;
	input is_bd_in;
	output reg is_bd_out;
	input eret;

	reg [31:0]cp0_9_count;
	reg [31:0]cp0_12_status;
	reg [31:0]cp0_13_cause;
	reg [31:0]cp0_14_epc;
	reg [31:0]cp0_8_badvaddr;
	reg count;

	always @(posedge clk or posedge rst) begin
		if (rst) begin
			cp0_9_count 	<= 32'b0;
			cp0_12_status 	<= 32'b0;
			cp0_13_cause 	<= 32'b0;
			cp0_14_epc 		<= 32'b0;
			cp0_8_badvaddr 	<= 32'b0;
			count 			<= 1'b0;
		end
		else begin
			if(write && cscd == 5'b01001)
				{cp0_9_count,count} <= {data_in,1'b0};
			else
				{cp0_9_count,count} <= {cp0_9_count,count} + 1;
			if((|e_op) | eret) begin
				cp0_13_cause[31]	<= (|e_op) ? is_bd_out : cp0_13_cause[31];
				cp0_14_epc 			<= (|e_op) ? e_in : cp0_14_epc;
				cp0_12_status[1]	<= (|e_op) ? 1'b1 : (eret) ? 1'b0 :cp0_12_status[1];
				cp0_13_cause[6:2]	<= (|e_op) ?
									({5{e_op[0]}} & 5'b00100) |//4
									({5{e_op[1]}} & 5'b01010) |//10
									({5{e_op[2]}} & 5'b01001) |//9
									({5{e_op[3]}} & 5'b01000) |//8
									({5{e_op[4]}} & 5'b00000) |//0
									({5{e_op[5]}} & 5'b01100) |//12
									({5{e_op[6]}} & 5'b00100) |//4
									({5{e_op[7]}} & 5'b00101) : cp0_13_cause[6:2];
			end
			else if(write) begin
				case(cscd)
					5'b01000:cp0_8_badvaddr 	<= data_in;
					5'b01100:cp0_12_status[1] 	<= data_in[1];
					//5'b01101:{cp0_13_cause[30:7],cp0_13_cause[1:0]}	<= {data_in[30:7],data_in[1:0]};
					5'b01110:cp0_14_epc			<= data_in;
				endcase
			end
		end
	end
	
	always @(posedge clk or posedge rst) begin
		if (rst) begin
			is_bd_out <= 1'b0;
		end
		else begin
			is_bd_out <= is_bd_in;
		end
	end
	
	assign data_out = {32{sel == 3'b000}} & {
					{{32{cscd == 5'b01000}} & cp0_8_badvaddr 	} |
					{{32{cscd == 5'b01001}} & cp0_9_count		} |
					{{32{cscd == 5'b01100}} & cp0_12_status		} |
					{{32{cscd == 5'b01101}} & cp0_13_cause		} |
					{{32{cscd == 5'b01110}} & cp0_14_epc		} };
	assign e_out = {cp0_12_status[1],cp0_13_cause[6:2],cp0_14_epc};
endmodule
