module asmux(b_out,b_in,sub_op);
	input	[31:0]b_in;
	input	sub_op;

	output	[31:0]b_out;

	assign b_out = b_in^{32{sub_op}};

endmodule

module add(less,overflow,sum,unsigned_op,a,b,cin);
  input		[31:0]a,b;
  input 	cin;
  input		unsigned_op;

  output 	[31:0]sum;
  output 	overflow;
  output	less;

  wire		[31:0]c;
  wire 		[7:0]D,T;
  wire 		addof;

  c16 C1(.C({c[31],c[27],c[23],c[19]}),.D(D[7:4]),.T(T[7:4]),.c(c[15]));
  c16 C2(.C({c[15],c[11],c[7],c[3]}),.D(D[3:0]),.T(T[3:0]),.c(cin));
  c4 c1(.D(D[7]),.T(T[7]),.C(c[30:28]),.a(a[31:28]),.b(b[31:28]),.c(c[27]));
  c4 c2(.D(D[6]),.T(T[6]),.C(c[26:24]),.a(a[27:24]),.b(b[27:24]),.c(c[23]));
  c4 c3(.D(D[5]),.T(T[5]),.C(c[22:20]),.a(a[23:20]),.b(b[23:20]),.c(c[19]));
  c4 c4(.D(D[4]),.T(T[4]),.C(c[18:16]),.a(a[19:16]),.b(b[19:16]),.c(c[15]));
  c4 c5(.D(D[3]),.T(T[3]),.C(c[14:12]),.a(a[15:12]),.b(b[15:12]),.c(c[11]));
  c4 c6(.D(D[2]),.T(T[2]),.C(c[10:8]),.a(a[11:8]),.b(b[11:8]),.c(c[7]));
  c4 c7(.D(D[1]),.T(T[1]),.C(c[6:4]),.a(a[7:4]),.b(b[7:4]),.c(c[3]));
  c4 c8(.D(D[0]),.T(T[0]),.C(c[2:0]),.a(a[3:0]),.b(b[3:0]),.c(cin));

  assign 	sum=a^b^{c[30:0],cin};

  assign 	addof= c[31]^c[30];

  assign 	overflow = ~unsigned_op & addof;

  assign    less = (unsigned_op)? ~c[31]:addof^sum[31];

endmodule

 
module c16(C,D,T,c);
  input [3:0]D,T;
  input c;
  output[3:0]C;

  assign C[0]=D[0]|(T[0]&c);
  assign C[1]=D[1]|(T[1]&D[0])|(T[1]&T[0]&c);
  assign C[2]=D[2]|(T[2]&D[1])|(T[2]&T[1]&D[0])|(T[2]&T[1]&T[0]&c);
  assign C[3]=D[3]|(T[3]&D[2])|(T[3]&T[2]&D[1])|(T[3]&T[2]&T[1]&D[0])|(T[3]&T[2]&T[1]&T[0]&c);

endmodule
 
module c4(D,T,C,a,b,c);
  input [3:0]a,b;
  input c;
  output [2:0]C;
  output D,T;

  wire [3:0]d,t;

  assign d=a&b;
  assign t=a|b;

  assign C[0]=d[0]|(t[0]&c);
  assign C[1]=d[1]|(t[1]&d[0])|(t[1]&t[0]&c);
  assign C[2]=d[2]|(t[2]&d[1])|(t[2]&t[1]&d[0])|(t[2]&t[1]&t[0]&c);
  assign T=t[3]&t[2]&t[1]&t[0];
  assign D=d[3]|(t[3]&d[2])|(t[3]&t[2]&d[1])|(t[3]&t[2]&t[1]&d[0]);

endmodule

module addr_we_din(addr_out,we_out,din_out,store_op_in,wmask_in,wdata_in,paddr_in,valid_in);
	input	store_op_in;
	input 	valid_in;
	input	[3:0]wmask_in;
	input	[31:0]wdata_in;
	input	[31:0]paddr_in;

	output	we_out;
	output	din_out;
	output	[29:0]addr_out;

	assign 	din_out = wdata_in;
	assign  we_out 	= {4{store_op_in&valid_in}}&wmask_in;
	assign  paddr_in = paddr_in[31:2];

endmodule

module alu_result_mux(result_out,sum_in,less_in,shift_in,logic_in,alu_res_sel);
	input	[31:0]sum_in;
	input	[31:0]shift_in;
	input	[31:0]logic_in;
	input	less_in;
	input	[1:0]alu_res_sel;

	output	[31:0]result_out;

	assign result_out = alu_res_sel[1]?
							(	alu_res_sel[0]	?	logic_in		:	shift_in):
							(	alu_res_sel[0]	?	{31'b0,less_in}	:	sum_in	);

endmodule

module ex_exception(ex_ov,ex_adel,ex_ades,store_op,store_type,load_op,load_type,alu_res_sel,overflow,offset);
	input	store_op;
	input	[2:0]store_type;
	input	load_op;
	input	[2:0]load_type;
	input	[1:0]alu_res_sel;
	input	overflow;
	input	[1:0]offset;

	output	ex_ov;
	output	ex_adel;
	output	ex_ades;

	assign  ex_ov = alu_res_sel==2'b00 ? overflow : 0 ;

	assign  ex_ades = store_op ?
								(
									  ((store_type[2]) & (offset   !=2'b00))   
									| ((store_type[1]) & (offset[0]!=1'b0 ))
								)
								:0;

	assign  ex_adel = load_op ?
								(
									  ((load_type[2]) & (offset   !=2'b00))   
									| ((load_type[1]) & (offset[0]!=1'b0 ))
								)
								:0;

endmodule

module lmux(a_out,reg_src,pc_src,link_op);
	input	[31:0]reg_src;
	input	[31:0]pc_src;
	input	link_op;

	output	[31:0]a_out;

	assign  a_out = link_op?pc_src:reg_src;

endmodule

module logic_alu(result,a,regb,immb,logic_type,imm_op);
	input	[31:0]a;
	input	[31:0]regb;
	input	[15:0]immb;
	input	[4:0]logic_type;
	input	imm_op;

	output	[31:0]result;

	wire	[31:0]immb_expand;
	wire	[31:0]b;

	assign 	immb_expand = {16'b0,immb};
	assign 	b = imm_op?immb_expand:regb;

	assign  result = logic_type[4] ? a&b   :	
					 logic_type[3] ? a|b   :
					 logic_type[2] ? a^b   :
					 logic_type[1] ? ~(a|b):{b[15:0],16'b0};

endmodule


module mapping(addr_out,addr_in);
	
	input	[31:0]addr_in;
	output	[31:0]addr_out;

	assign addr_out = {3'b0,addr_in[28:0]};

endmodule


module shifter(y,x,shamt0,shamt1,imm_op,shift_type);
	input	[4:0]shamt1;
	input	[4:0]shamt0;
	input	imm_op;
	input	[2:0]shift_type;
	input	[31:0]x;

	output	[31:0]y;

	wire	[4:0]shamt;
	wire	[31:0]y1;
	wire	[31:0]y2;
	wire	[31:0]y3;

	assign 	shamt = imm_op?shamt1:shamt0;

	assign 	y1 = x << shamt;
	assign 	y2 = x >> shamt;
	//assign 	y3 = x >>> shamt;
	wire [31:0]shift_temp1 = {32{shamt[0]}} ? {x[31],x[31:1]}	:{x[31:0]};
	wire [31:0]shift_temp2 = {32{shamt[1]}} ? {{2{shift_temp1[31]}},shift_temp1[31:2]}:{shift_temp1[31:0]};
	wire [31:0]shift_temp3 = {32{shamt[2]}} ? {{4{shift_temp2[31]}},shift_temp2[31:4]}:{shift_temp2[31:0]};
	wire [31:0]shift_temp4 = {32{shamt[3]}} ? {{8{shift_temp3[31]}},shift_temp3[31:8]}:{shift_temp3[31:0]};
	assign y3 = {32{shamt[4]}} ? {{16{shift_temp4[31]}},shift_temp4[31:16]}:{shift_temp4[31:0]};
	assign  y = shift_type[2] ? y1 :
				shift_type[1] ? y2 : y3;

endmodule

module storevalue(wmask,wdata,type,value,offset);
	input	[31:0]value;
	input	[1:0]offset;
	input	[2:0]type;

	output reg	[3:0]wmask;
	output	[31:0]wdata;


	assign 	wdata = {32{type[0]}}&{4{value[7:0]}}
				  |	{32{type[1]}}&{2{value[15:0]}}
				  |	{32{type[2]}}&{{value[31:0]}};

	always @(*)
	begin
		case(type)
			3'b100:
				wmask = 4'b1111;
			3'b010:
				case(offset)
					2'b00:
						wmask = 4'b0011;
					2'b10:
						wmask = 4'b1100;
					default:
						wmask = 4'b0000;
				endcase
			3'b001:
				case(offset)
					2'b00:
						wmask = 4'b0001;
					2'b01:
						wmask = 4'b0010;
					2'b10:
						wmask = 4'b0100;
					2'b11:
						wmask = 4'b1000;
				endcase
			default:
				wmask = 4'b0000;
		endcase
	end

endmodule

module umux(b_out,b_unsign_in,b_sign_in,imm_op);
	input	[15:0]b_unsign_in;
	input	[31:0]b_sign_in;
	input	imm_op;

	output	[31:0]b_out;

	assign b_out = imm_op?{{16{b_unsign_in[15]}},b_unsign_in}:b_sign_in;

endmodule