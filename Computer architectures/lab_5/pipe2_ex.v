module PIPE2
(
	input pipe2_valid_in,
	input [81:0] pipe2_ctrl_info_in, 
	// eret 81,int 80,syscall 79,break 78,id_ri_ex 77,if_adel 76
	//pc 75:44,dest 43:39,(|branch_type) 38,bypass_op 37 ,logic_type 36:32
	//shift_type 31:29,imm_op 28,unsigned_op 27,sub_op 26,link_op 25,store_type 24:22 ,store_op 21
	//alu_res_sel 20:19,load_type 18:15,load_op 14,hi_we 13,lo_we 12,cp0_write 11
	//cs 10:6,sel [2:0] 5:3,wb_mux 2:1,reg_we 0
	input [79:0] pipe2_data_info_in,
	// vsrc1 79:48 vsrc2 47:16 imm 15:0
	output pipe2_valid_out,
	output [65:0] pipe2_ctrl_info_out, 
	// 缺！！！！！！！�/不缺�	
	output [33:0] pipe2_data_info_out,
	// memvalue 33:2  offset 1:0
	input pipe2_allow_out, //PIPE2指令允许进入下一流水�	
	output pipe2_allow_in,//PIPE 2 允许下一条指令进入本流水�
	output [31:0]addr_out,
	output [3:0]we_out,
	output [31:0]din_out,

	output [31:0]alu_result,
	output ex_dest_rdy //前递添�	//我看到前递好像有条线 先写在这 你不用就不要实例化这个接口了
	//134行有一个相关的赋�
);
	//pipe2_valid
	wire pipe2_valid;
	assign pipe2_valid = pipe2_valid_in;

	assign ex_dest_rdy = (pipe2_ctrl_info_in[14]==1'b0) &(pipe2_ctrl_info_in[2:1]==2'b0);//前递添�此处不能是load，不能是cp0,hi,lo相关
	
	//流水线控制信�	
	wire pipe2_rdy_go; //PIPE 2 准备�	
	assign pipe2_rdy_go = 1; //由本级控制信号产�
	assign pipe2_valid_out = pipe2_valid && pipe2_rdy_go; 
	assign pipe2_ctrl_info_out = {ex_ades,ex_adel,ex_ov,pipe2_ctrl_info_in[81:38],pipe2_ctrl_info_in[18:0]}; //由本级控制信号产�	
	assign pipe2_data_info_out = {memvalue,offset};
	assign pipe2_allow_in = (~|pipe2_ctrl_info_out[65:57])&(!pipe2_valid || pipe2_valid_out && pipe2_allow_out);

	//例外信号
	wire 	ex_ov;
	wire 	ex_adel;
	wire 	ex_ades;

	wire 	[2:0]	load_type;
	wire 	load_op;

	assign  load_type = pipe2_ctrl_info_in[17:15];
	assign  load_op = pipe2_ctrl_info_in[14];

	
	//data输出信号相关
	wire 	[31:0]	memvalue;
	wire 	[1:0]	offset;

	assign  offset = sum[1:0];

	//data输入信号相关
	wire  	[31:0]	vsrc1;
	wire  	[31:0]	vsrc2;
	wire  	[15:0]	imm;
	assign  vsrc1 = pipe2_data_info_in[79:48];
	assign  vsrc2 = pipe2_data_info_in[47:16];
	assign  imm   = pipe2_data_info_in[15: 0];

	//加法器立即数选择
	wire 	imm_op;
	assign  imm_op = pipe2_ctrl_info_in[28];

	wire 	[31:0]  b_mid;

	umux umux(.b_out(b_mid),.b_unsign_in(imm),.b_sign_in(vsrc2),.imm_op(imm_op));

	//减法操作数选择
	wire  	[31:0]  b;

	wire 	sub_op;
	assign  sub_op = pipe2_ctrl_info_in[26];

	asmux asmux(.b_out(b),.b_in(b_mid),.sub_op(sub_op));

	//加法操作数a选择
	wire 	[31:0] 	a;

	wire 	link_op;
	assign  link_op = pipe2_ctrl_info_in[25];

	wire    [31:0]  pc;
	assign  pc = pipe2_ctrl_info_in[75:44];

	lmux lmux(.a_out(a),.reg_src(vsrc1),.pc_src(pc),.link_op(link_op));

	//加法�	
	wire 	less;
	wire 	overflow;
	wire 	[31:0]	sum;
	wire 	unsigned_op;
	assign  unsigned_op = pipe2_ctrl_info_in[27];

	add add(.less(less),.overflow(overflow),.sum(sum),.unsigned_op(unsigned_op),.a(a),.b(b),.cin(sub_op));

	//移位�
	wire 	[31:0]	x;
	assign  x = vsrc2;
	wire 	[31:0]	y;
	wire 	[4:0] 	shamt0;
	assign  shamt0 = vsrc1[4:0];
	wire 	[4:0]	shamt1;
	assign  shamt1 = imm [10:6];
	wire 	[2:0] 	shift_type;
	assign  shift_type = pipe2_ctrl_info_in[31:29];

	shifter shifter(.y(y),.x(x),.shamt0(shamt0),.shamt1(shamt1),.imm_op(imm_op),.shift_type(shift_type));

	//逻辑运算�	
	wire 	[4:0]	logic_type;
	assign  logic_type = pipe2_ctrl_info_in[36:32];

	wire 	[31:0]	logic_result;

	logic_alu logic_alu(.result(logic_result),.a(vsrc1),.regb(vsrc2),.immb(imm),.logic_type(logic_type),.imm_op(imm_op));

	//逻辑运算器最终结果生�	
	wire 	bypass_op;
	assign  bypass_op = pipe2_ctrl_info_in[37];

	wire 	[31:0]	logic_result_final;

	assign  logic_result_final = bypass_op ? vsrc2 : logic_result ;

	wire 	[31:0]	alu_result_inner;
	assign  alu_result = alu_result_inner;
	assign  memvalue = alu_result;

	wire 	[1:0]	alu_res_sel;
	assign  alu_res_sel = pipe2_ctrl_info_in[20:19];

	//alu结果选择
	alu_result_mux alu_result_mux(.result_out(alu_result_inner),.sum_in(sum),.less_in(less),.shift_in(y),.logic_in(logic_result_final),.alu_res_sel(alu_res_sel));

	//虚实地址转换
	mapping mapping(.addr_out(addr_out),.addr_in(sum));

	//store数据生成
	wire 	[3:0]	wmask;
	wire 	[2:0] 	store_type;
	wire 	store_op;

	assign  store_type = pipe2_ctrl_info_in[24:22];
	assign  store_op = pipe2_ctrl_info_in[21];

	storevalue storevalue(.wmask(wmask),.wdata(din_out),.type(store_type),.value(vsrc2),.offset(sum[1:0]));

	//写使能最终生�	
	assign  we_out = {4{store_op&pipe2_valid_in&(~|pipe2_ctrl_info_out[65:57])}}&wmask;;


	ex_exception ex_exception(.ex_ov(ex_ov),.ex_adel(ex_adel),.ex_ades(ex_ades),.store_op(store_op),.store_type(store_type),.load_op(load_op),.load_type(load_type),.alu_res_sel(alu_res_sel),.overflow(overflow),.offset(sum[1:0]));

endmodule