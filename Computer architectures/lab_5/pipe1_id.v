module PIPE1(

	input [31:0]rdata1,
	input [31:0]rdata2,
	output [31:0]branch_imm,
	output [25:0]j_imm,
	output [31:0]jr_addr,
	output br_taken,
	output j_taken,
	output jr_taken,
	input [4:0]wb_dest,
	input  wb_dest_rdy,
	input [4:0]mem_dest,
	input mem_dest_rdy,
	input [4:0]ex_dest,
	input ex_dest_rdy,

	input [31:0]wb_res,
	input [31:0]mem_res,
	input [31:0]ex_res,

	input inta,

	input pipe1_valid_in, 
	output pipe1_valid_out,
	input [32:0] pipe1_ctrl_info_in, 
	input [31:0] pipe1_data_info_in,
	output [81:0] pipe1_ctrl_info_out, 
	output [79:0] pipe1_data_info_out,
	input pipe1_allow_out, //PIPE1指令允许进入下一流水�	
	output pipe1_allow_in //PIPE 1 允许下一条指令进入本流水�
);
//pipe1_valid
	wire pipe1_valid;
	assign pipe1_valid = pipe1_valid_in;

	assign branch_imm = {{14{pipe1_data_info_in[15]}},pipe1_data_info_in[15:0],2'd0};
	assign j_imm = pipe1_data_info_in[25:0];
	assign jr_addr = vsrc1;
/*
branch_type:
rev: 0      1
5:  beq -- bne
4:  blt -- bge
3:  ble -- bgt
2:  rev
1:  j
0:  jr
*/
	
	wire [5:0]op,func;
	wire [4:0]rs,rt,rd,sa;
	
	assign op = pipe1_data_info_in[31:26];
	assign rs = pipe1_data_info_in[25:21];
	assign rt = pipe1_data_info_in[20:16];
	assign rd = pipe1_data_info_in[15:11];
	assign sa = pipe1_data_info_in[10:6];
	assign func = pipe1_data_info_in[5:0];


	wire inst_add;
	assign inst_add		= (op == 6'b000000) & (sa == 5'b00000) 					  & (func == 6'b100000);
	wire inst_addi;
	assign inst_addi 	= (op == 6'b001000);
	wire inst_addiu;
	assign inst_addiu 	= (op == 6'b001001);
	wire inst_addu;
	assign inst_addu	= (op == 6'b000000) & (sa == 5'b00000) 					  & (func == 6'b100001);
	wire inst_and;
	assign inst_and		= (op == 6'b000000) & (sa == 5'b00000) 					  & (func == 6'b100100);
	wire inst_andi;
	assign inst_andi	= (op == 6'b001100);
	wire inst_beq;
	assign inst_beq 	= (op == 6'b000100);
	wire inst_bgez;
	assign inst_bgez	= (op == 6'b000001) & (rt == 5'b00001);
	wire inst_bgezal;
	assign inst_bgezal 	= (op == 6'b000001) & (rt == 5'b10001);
	wire inst_bgtz;
	assign inst_bgtz	= (op == 6'b000111) & (rt == 5'b00000);
	wire inst_blez;
	assign inst_blez 	= (op == 6'b000110) & (rt == 5'b00000);
	wire inst_bltz;
	assign inst_bltz 	= (op == 6'b000001) & (rt == 5'b00000);
	wire inst_bltzal;
	assign inst_bltzal 	= (op == 6'b000001) & (rt == 5'b10000);
	wire inst_bne;
	assign inst_bne 	= (op == 6'b000101);
	wire inst_break;
	assign inst_break 	= (op == 6'b000000)										  & (func == 6'b001101);
	wire inst_div;
	assign inst_div		= (op == 6'b000000) & (rd == 5'b00000) & (sa == 5'b00000) & (func == 6'b011010);
	wire inst_divu;
	assign inst_divu 	= (op == 6'b000000) & (rd == 5'b00000) & (sa == 5'b00000) & (func == 6'b011011);
	wire inst_eret;
	assign inst_eret 	= ({op,rs,rt,rd,sa,func} == 32'b010000_1000_0000_0000_0000_0000_011000);
	wire inst_j;
	assign inst_j 		= (op == 6'b000010);
	wire inst_jal;
	assign inst_jal 	= (op == 6'b000011);
	wire inst_jalr;
	assign inst_jalr 	= (op == 6'b000000) & (rt == 5'b00000) & (sa == 5'b00000) & (func == 6'b001001);
	wire inst_jr;
	assign inst_jr 		= (op == 6'b000000) & ({rt,rd,sa} == 15'b000000000000000) & (func == 6'b001000); 
	wire inst_lb;
	assign inst_lb 		= (op == 6'b100000);
	wire inst_lbu;
	assign inst_lbu 	= (op == 6'b100100);
	wire inst_lh;
	assign inst_lh 		= (op == 6'b100001);
	wire inst_lhu;
	assign inst_lhu 	= (op == 6'b100101);
	wire inst_lui;
	assign inst_lui 	= (op == 6'b001111) & (rs == 5'b00000);
	wire inst_lw;
	assign inst_lw 		= (op == 6'b100011);
	wire inst_lwl;
	assign inst_lwl 	= (op == 6'b100010);
	wire inst_lwr;
	assign inst_lwr 	= (op == 6'b100110);
	wire inst_mfc0;
	assign inst_mfc0 	= (op == 6'b010000) & (rs == 5'b00000) & (sa == 5'b00000) & (func[5:3] == 3'b000);
	wire inst_mfhi;
	assign inst_mfhi 	= (op == 6'b000000) & ({rs,rt,sa} == 15'b000000000000000) & (func == 6'b010000);
	wire inst_mflo;
	assign inst_mflo 	= (op == 6'b000000) & ({rs,rt,sa} == 15'b000000000000000) & (func == 6'b010010);
	wire inst_mtc0;
	assign inst_mtc0 	= (op == 6'b010000) & (rs == 5'b00100) & (sa == 5'b00000) & (func[5:3] == 3'b000);
	wire inst_mthi;
	assign inst_mthi 	= (op == 6'b000000) & ({rt,rd,sa} == 15'b000000000000000) & (func == 6'b010001);
	wire inst_mtlo;
	assign inst_mtlo 	= (op == 6'b000000) & ({rt,rd,sa} == 15'b000000000000000) & (func == 6'b010011);
	wire inst_mult;
	assign inst_mult 	= (op == 6'b000000) & (rd == 5'b00000) & (sa == 5'b00000) & (func == 6'b011000);
	wire inst_multu;
	assign inst_multu 	= (op == 6'b000000) & (rd == 5'b00000) & (sa == 5'b00000) & (func == 6'b011001);
	wire inst_nor;
	assign inst_nor 	= (op == 6'b000000)	& (sa == 5'b00000)				      & (func == 6'b100111);
	wire inst_or;
	assign inst_or 		= (op == 6'b000000)	& (sa == 5'b00000)				      & (func == 6'b100101);
	wire inst_ori;
	assign inst_ori 	= (op == 6'b001101);
	wire inst_sb;
	assign inst_sb 		= (op == 6'b101000);
	wire inst_sh;
	assign inst_sh 		= (op == 6'b101001);
	wire inst_sll;
	assign inst_sll		= (op == 6'b000000) & (rs == 5'b00000)					  & (func == 6'b000000);
	wire inst_sllv;
	assign inst_sllv	= (op == 6'b000000) & (sa == 5'b00000)					  & (func == 6'b000100);
	wire inst_slt;
	assign inst_slt		= (op == 6'b000000) & (sa == 5'b00000)					  & (func == 6'b101010);
	wire inst_slti;
	assign inst_slti 	= (op == 6'b001010);
	wire inst_sltiu;
	assign inst_sltiu 	= (op == 6'b001011);
	wire inst_sltu;
	assign inst_sltu 	= (op == 6'b000000) & (sa == 5'b00000)					  & (func == 6'b101011);
	wire inst_sra;
	assign inst_sra 	= (op == 6'b000000) & (rs == 5'b00000)					  & (func == 6'b000011);
	wire inst_srav;
	assign inst_srav 	= (op == 6'b000000) & (sa == 5'b00000)					  & (func == 6'b000111);
	wire inst_srl;
	assign inst_srl 	= (op == 6'b000000) & (rs == 5'b00000)					  & (func == 6'b000010);
	wire inst_srlv;
	assign inst_srlv 	= (op == 6'b000000) & (sa == 5'b00000)					  & (func == 6'b000110); 
	wire inst_sub;
	assign inst_sub 	= (op == 6'b000000) & (sa == 5'b00000)					  & (func == 6'b100010);
	wire inst_subu;
	assign inst_subu 	= (op == 6'b000000) & (sa == 5'b00000)					  & (func == 6'b100011);
	wire inst_sw;
	assign inst_sw 		= (op == 6'b101011);
	wire inst_swl;
	assign inst_swl 	= (op == 6'b101010);
	wire inst_swr;
	assign inst_swr		= (op == 6'b101110);
	wire inst_syscall;
	assign inst_syscall = (op == 6'b000000) 									  & (func == 6'b001100);
	wire inst_xor;
	assign inst_xor 	= (op == 6'b000000) & (sa == 5'b00000)					  & (func == 6'b100110);
	wire inst_xori;
	assign inst_xori 	= (op == 6'b001110);


	wire id_ri_ex;
	assign id_ri_ex = ~(inst_add | inst_addi | inst_addiu | inst_addu | inst_and | inst_andi | inst_beq | inst_bgez | inst_bgezal | inst_bgtz | inst_blez | inst_bltz | inst_bltzal | inst_bne | inst_break | inst_eret | inst_j | inst_jal | inst_jalr | inst_jr | inst_lb | inst_lbu | inst_lh | inst_lhu | inst_lui | inst_lw | inst_mfc0 | inst_mfhi | inst_mflo | inst_mtc0 | inst_mthi | inst_mtlo | inst_nor | inst_or | inst_ori | inst_sb | inst_sh | inst_sll | inst_sllv | inst_slt | inst_slti | inst_sltiu | inst_sltu | inst_sra | inst_srav | inst_srl | inst_srlv | inst_sub | inst_subu | inst_sw | inst_syscall | inst_xor | inst_xori);


	wire [31:0]vsrc1,vsrc2;
	wire [5:0]branch_type;
	branch_check BR_CHECK(branch_type,vsrc1,vsrc2, br_taken, j_taken, jr_taken);

	wire [1:0]vsrc1_sel,vsrc2_sel;
	wire hazard_free;
	wire rs_need;
	wire rt_need;
	wire rt_write;
	wire rd_write;
	wire [4:0]dest;
	
	assign dest = (rd_write)?rd:
					(rt_write)?rt:
					(inst_bgezal|inst_bltzal|inst_jal)?5'd31:5'd0;
	

	hazard_check HZD_CHECK(wb_dest, wb_dest_rdy, mem_dest, mem_dest_rdy, ex_dest, ex_dest_rdy, 
	pipe1_data_info_in[25:21], rs_need, pipe1_data_info_in[20:16], rt_need, 
	hazard_free,
	vsrc1_sel, vsrc2_sel);

	mux_4 VSRC1(rdata1,ex_res,mem_res,wb_res,vsrc1,vsrc1_sel);
	mux_4 VSRC2(rdata2,ex_res,mem_res,wb_res,vsrc2,vsrc2_sel);


	wire bypass_op;
	wire [4:0]logic_type;
	wire [2:0]shift_type;	
	wire imm_op;	
	wire unsigned_op;	
	wire sub_op;
	wire link_op;
	wire [2:0]store_type;
	wire store_op;
	wire [1:0]alu_res_sel;
	wire [3:0]load_type;
	wire load_op;
	wire hi_we;
	wire lo_we;
	wire cp0_write;
	wire [1:0]wb_mux;
	wire reg_we;
	assign reg_we = |dest;

	wire [15:0]imm;
	assign imm = (link_op)?16'd8:pipe1_data_info_in[15:0];

	// assign branch_type[5] = (op[5:1]==5'b00010);
	// assign branch_type[4] = (op[5:0]==6'b000001);
	// assign branch_type[3] = (op[5:1]==5'b00011);
	// assign branch_type[2] = branch_type[5]&op[0] | branch_type[4]&rt[0] | branch_type[3]&op[0];
	// assign branch_type[1] = (op[5:1]==5'b00001);
	// assign branch_type[0] = (op[5:0]=6'b0) & (func[5:1]==6'b00100);

	// assign link_op = branch_type[4]&rt[4] | branch_type[1]&op[0]| branch_type[0]& func[0];

	assign wb_mux[0] = inst_mfc0 | inst_mfhi;
	assign wb_mux[1] = inst_mfhi | inst_mflo;
	assign cp0_write = inst_mtc0;
	assign lo_we = inst_mtlo;
	assign hi_we = inst_mthi;
	assign load_op = inst_lb | inst_lbu | inst_lh | inst_lhu | inst_lw;
	assign load_type[0] = inst_lb | inst_lbu;
	assign load_type[1] = inst_lh|inst_lhu;
	assign load_type[2] = inst_lw;
	assign load_type[3] = inst_lbu|inst_lhu;

	assign alu_res_sel[0] = inst_and | inst_andi | inst_lui | inst_nor|inst_or|inst_slt|inst_slti|inst_sltiu|inst_sltu|inst_xor|inst_xori |inst_mtc0|inst_mfc0;
	assign alu_res_sel[1] = inst_and|inst_andi|inst_lui|inst_nor|inst_or|inst_sll|inst_sllv|inst_sra|inst_srav|inst_srl|inst_srlv|inst_xor|inst_xori |inst_mtc0|inst_mfc0;

	assign store_op = inst_sb|inst_sh|inst_sw;
	assign store_type[0] = inst_sb;
	assign store_type[1] = inst_sh;
	assign store_type[2] = inst_sw;

	assign branch_type[5] = inst_beq | inst_bne;
	assign branch_type[4] = inst_bgez | inst_bgezal | inst_bltz | inst_bltzal;
	assign branch_type[3] = inst_bgtz | inst_blez;
	assign branch_type[2] = inst_bgez | inst_bgezal | inst_bgtz | inst_bne;
	assign branch_type[1] = inst_j | inst_jal;
	assign branch_type[0] = inst_jalr | inst_jr;
	assign rs_need = inst_add | inst_addi | inst_addiu | inst_addu | inst_and | inst_addi | inst_beq | inst_bgez | inst_bgezal | inst_bgtz| inst_blez | inst_bltz | inst_bltzal | inst_bne | inst_jalr | inst_jr | inst_lb | inst_lbu | inst_lh | inst_lhu | inst_lw | inst_nor | inst_or | inst_ori | inst_sb | inst_sh | inst_sllv | inst_slt | inst_slti | inst_sltiu | inst_sltu | inst_srav | inst_srlv | inst_sw | inst_xor | inst_xori;
	assign rt_need = inst_add | inst_addu | inst_and | inst_beq | inst_bne | inst_mtc0 | inst_mthi | inst_mtlo | inst_nor | inst_or | inst_sll | inst_sllv | inst_slt | inst_sltu | inst_sra | inst_srav | inst_srl | inst_srlv | inst_xor;
	assign rt_write = inst_addi | inst_addiu | inst_andi | inst_lb | inst_lbu | inst_lh | inst_lhu | inst_lui | inst_lw | inst_mfc0 | inst_mfhi | inst_mflo | inst_ori | inst_sb | inst_sh | inst_slti | inst_sltiu | inst_sw | inst_xori;
	assign rd_write = inst_add | inst_addu | inst_and | inst_jalr | inst_nor | inst_or | inst_sll | inst_sllv | inst_slt | inst_sltu | inst_sra | inst_srav | inst_srl | inst_srlv | inst_xor;
	assign bypass_op = inst_mtc0|inst_mfc0;
	assign logic_type[4] = inst_and | inst_andi;
	assign logic_type[3] = inst_or | inst_ori;
	assign logic_type[2] = inst_xor | inst_xori;
	assign logic_type[1] = inst_nor;
	assign logic_type[0] = inst_lui;
	assign shift_type[2] = inst_sll | inst_sllv;
	assign shift_type[1] = inst_srl | inst_srlv;
	assign shift_type[0] = inst_sra | inst_srav;
	assign imm_op = inst_addi | inst_addiu | inst_andi | inst_lb | inst_lbu | inst_lh | inst_lhu | inst_lui | inst_lw |inst_ori | inst_sb | inst_sh | inst_sll | inst_slti | inst_sltiu | inst_sra | inst_srl | inst_sw | inst_xori;
	assign unsigned_op = ~(inst_add | inst_addi | inst_slt | inst_slti | inst_sub);
	assign sub_op = inst_slt | inst_slti | inst_sltiu | inst_sltu;
	assign link_op = inst_bgezal | inst_bltzal | inst_jal | inst_jalr;

	wire pipe1_rdy_go; //PIPE 1 准备�	
	assign pipe1_rdy_go = hazard_free; //由本级控制信号产�	
	assign pipe1_valid_out = pipe1_valid && pipe1_rdy_go; 
	assign pipe1_ctrl_info_out = {inst_eret,inta,inst_syscall,inst_break,id_ri_ex,pipe1_ctrl_info_in,dest,(|branch_type),bypass_op,logic_type,shift_type,imm_op,unsigned_op,sub_op,link_op,store_type,store_op,alu_res_sel,load_type,load_op,hi_we,lo_we,cp0_write,rd,func[2:0],wb_mux,reg_we};//由本级控制信号产�
	assign pipe1_data_info_out = {vsrc1,vsrc2,imm};//由本级控制信号和数据产生
	assign pipe1_allow_in = (~|pipe1_ctrl_info_out[81:76])&(!pipe1_valid || pipe1_valid_out && pipe1_allow_out);
endmodule