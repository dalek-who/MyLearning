//pipe3_ctrl_info_in ...
//[aa:bb]ex
//[cc]load_op
//[dd:ff]load_type
module PIPE3(
	input [31:0]dout,//we do
	input pipe3_valid_in, 
	input [65:0] pipe3_ctrl_info_in,
	//exc-type65-57,pc56-25,dest24-20,btype19,load_type18-15,load_op14,hiwe13，lowe12，cp0we11,cp0cs10-6,cp0sel5-3，wbmux2-1，regwe0 
	input [33:0] pipe3_data_info_in,
	output pipe3_valid_out,
	output [60:0] pipe3_ctrl_info_out, 
	//exop（含eret�0-52，pc51-20，dest19-15，btype14，hiwe13，lowe12，cp0we11,cp0cs10-6,cp0sel5-3，wbmux2-1，regwe0  
	output [31:0] pipe3_data_info_out,
	input pipe3_allow_out, //PIPE3指令允许进入下一流水�
	output pipe3_allow_in, //PIPE 3 允许下一条指令进入本流水�

	output mem_dest_rdy//前递使�
);
//pipe3_valid
	wire pipe3_valid;
	assign pipe3_valid = pipe3_valid_in;

	assign mem_dest_rdy = (pipe3_ctrl_info_in[2:1]==2'b0);//此处不能是cp0,hi,lo相关

	wire [31:0]process_result;
	load_data_process ld(
	.dout 			(dout),
	.alu_result		(pipe3_data_info_in[33: 2]),
	.load_type		(pipe3_ctrl_info_in[18:15]),
	.offset			(pipe3_data_info_in[ 1: 0]),
	.process_result	(process_result)
	);
	assign pipe3_data_info_out = (~(pipe3_ctrl_info_in[64] | pipe3_ctrl_info_in[63]) & pipe3_ctrl_info_in[14]) ?process_result :pipe3_data_info_in[33:2] ;
	assign pipe3_ctrl_info_out = {pipe3_ctrl_info_in[65:19],pipe3_ctrl_info_in[13:0]};
	//流水线控制信�
	wire pipe3_rdy_go; //PIPE 3 准备�
	assign pipe3_rdy_go = 1; //由本级控制信号产�
	assign pipe3_valid_out = pipe3_valid && pipe3_rdy_go; 
	//assign pipe3_ctrl_out = ... //由本级控制信号产�
	//assign pipe3_data_out = ... //由本级控制信号和数据产生
	assign pipe3_allow_in = (~|pipe3_ctrl_info_out[60:52])&(!pipe3_valid || pipe3_valid_out && pipe3_allow_out);
endmodule

//load_type
//U,W,H,B
module load_data_process(dout,alu_result,load_type,offset,process_result);
	input [31:0]dout;
	input [31:0]alu_result;
	input [3:0]load_type;
	input [1:0]offset;
	output [31:0]process_result;

	assign process_result = 
			{32{load_type[0]}} & {32{offset[1:0] == 2'b00}} & {{24{~load_type[3] & dout[ 7]}}, dout[ 7: 0]} |
			{32{load_type[0]}} & {32{offset[1:0] == 2'b01}} & {{24{~load_type[3] & dout[15]}}, dout[15: 8]} |
			{32{load_type[0]}} & {32{offset[1:0] == 2'b10}} & {{24{~load_type[3] & dout[23]}}, dout[23:16]} |
			{32{load_type[0]}} & {32{offset[1:0] == 2'b11}} & {{24{~load_type[3] & dout[31]}}, dout[31:24]} |
			{32{load_type[1]}} & {32{~offset[1]}} & {{16{~load_type[3] & dout[15]}}, dout[15: 0]} |
			{32{load_type[1]}} & {32{ offset[1]}} & {{16{~load_type[3] & dout[31]}}, dout[31:16]} |
			{32{load_type[2]}} & dout[31: 0];

endmodule
