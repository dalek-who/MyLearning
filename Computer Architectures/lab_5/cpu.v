module my_cpu(input clk,input resetn,
	output [31:0] rf_0,
    output [31:0] rf_1,
    output [31:0] rf_2,
    output [31:0] rf_3,
    output [31:0] rf_4,
    output [31:0] rf_5,
    output [31:0] rf_6,
    output [31:0] rf_7,
    output [31:0] rf_8,
    output [31:0] rf_9,
    output [31:0] rf_10,
    output [31:0] rf_11,
    output [31:0] rf_12,
    output [31:0] rf_13,
    output [31:0] rf_14,
    output [31:0] rf_15,
    output [31:0] rf_16,
    output [31:0] rf_17,
    output [31:0] rf_18,
    output [31:0] rf_19,
    output [31:0] rf_20,
    output [31:0] rf_21,
    output [31:0] rf_22,
    output [31:0] rf_23,
    output [31:0] rf_24,
    output [31:0] rf_25,
    output [31:0] rf_26,
    output [31:0] rf_27,
    output [31:0] rf_28,
    output [31:0] rf_29,
    output [31:0] rf_30,
    output [31:0] rf_31,

    output [31:0] wb_pc,
    output wb_valid
);

	parameter INST_INIT_FILE = "none";


	wire pipe0_valid_out; 
	wire [32:0] pipe0_ctrl_info_out; 
	wire [31:0] pipe0_data_info_out;
	wire pipe1_valid_in;
	wire [32:0] pipe1_ctrl_info_in;
	wire [31:0] pipe1_data_info_in;
	wire pipe0_allow_out; 
	wire pipe1_allow_in;
	wire reg_we;
	wire [4:0]waddr;
	wire [31:0]wdata;
	wire [31:0]rdata1;
	wire [31:0]rdata2;
	wire [4:0]raddr1;
	wire [4:0]raddr2;

	wire pipe1_valid_out; 
	wire [81:0] pipe1_ctrl_info_out; 
	wire [79:0] pipe1_data_info_out;
	wire pipe2_valid_in;
	wire [81:0] pipe2_ctrl_info_in;
	wire [79:0] pipe2_data_info_in;
	wire pipe1_allow_out; 
	wire pipe2_allow_in;

	wire pipe2_valid_out; 
	wire [65:0] pipe2_ctrl_info_out; 
	wire [33:0] pipe2_data_info_out;
	wire pipe3_valid_in;
	wire [65:0] pipe3_ctrl_info_in;
	wire [33:0] pipe3_data_info_in;
	wire pipe2_allow_out; 
	wire pipe3_allow_in;

	wire pipe3_valid_out; 
	wire [60:0] pipe3_ctrl_info_out; 
	wire [31:0] pipe3_data_info_out;
	wire pipe4_valid_in;
	wire [60:0] pipe4_ctrl_info_in;
	wire [31:0] pipe4_data_info_in;
	wire pipe3_allow_out; 
	wire pipe4_allow_in;

	wire wb_reset;
	wire other_reset;
	wire ex_taken;
	wire [31:0]ex_addr;

	
	wire [31:0]inst_addr;
	wire [29:0]inst_ram_addr;
	wire [31:0]inst_ram_data_out;
	assign inst_ram_addr = inst_addr[31:2];

	inst_ram #(.INST_INIT_FILE(INST_INIT_FILE)) MY_INST(.clka(clk),.wea(4'd0),.addra(inst_ram_addr[13:0]),.dina(0),.douta(inst_ram_data_out));

	wire [31:0]data_addr;
	wire [31:0]data_ram_addr;
	wire [31:0]data_ram_data_in;
	wire [31:0]data_ram_data_out;
	wire [3:0]data_ram_we;
	assign data_ram_addr = data_addr[31:2];

	data_ram MY_DATA(.clka(clk),.wea(data_ram_we),.addra(data_ram_addr[13:0]),.dina(data_ram_data_in),.douta(data_ram_data_out));

	wire [31:0]alu_result;


	wire [31:0]branch_imm;
	wire [25:0]j_imm;
	wire [31:0]jr_addr;

	wire br_taken;
	wire j_taken;
	wire jr_taken;

	wire [4:0]e_cause;
	wire is_exl;
	wire eret;
	wire [31:0]e_pc;

	PIPE0 IF(
		.clk(clk),
		// .reset,
		.paddr(inst_addr),
		.rom_data(inst_ram_data_out),
		// .pipe0_valid_in, 
		// .[XXX:0] pipe0_ctrl_info_in, 
		.branch_imm(branch_imm),
		.j_imm(j_imm),
		.jr_addr(jr_addr),
		// .nextpc_en(),
		.br_taken(br_taken),
		.j_taken(j_taken),
		.jr_taken(jr_taken),
		.ex_taken(ex_taken),
		.ex_addr(ex_addr),
		// .[YYY:0] pipe0_data_info_in(),
		.pipe0_valid_out(pipe0_valid_out), 	
		.pipe0_ctrl_info_out(pipe0_ctrl_info_out),
		.pipe0_data_info_out(pipe0_data_info_out),
		.pipe0_allow_out(pipe0_allow_out)
	);

	Reg_0_1 IF_ID_REG(.clk(clk),
		.reset(other_reset), 
		.pipe0_valid_out(pipe0_valid_out), 
		.pipe0_ctrl_info_out(pipe0_ctrl_info_out), 
		.pipe0_data_info_out(pipe0_data_info_out),
		.pipe1_valid_in(pipe1_valid_in),
		.pipe1_ctrl_info_in(pipe1_ctrl_info_in),
		.pipe1_data_info_in(pipe1_data_info_in),
		.pipe0_allow_out(pipe0_allow_out), 
		.pipe1_allow_in(pipe1_allow_in),
		.raddr1(raddr1),
		.raddr2(raddr2)
		// .we(reg_we),
		// .waddr(waddr),
		// .wdata(wdata),
		// .rdata1(rdata1),
		// .rdata2(rdata2)
	);

	PIPE1 ID(
		.rdata1(rdata1),
		.rdata2(rdata2),
		.branch_imm(branch_imm),
		.j_imm(j_imm),
		.jr_addr(jr_addr),
		.br_taken(br_taken),
		.j_taken(j_taken),
		.jr_taken(jr_taken),
		.wb_dest(pipe4_ctrl_info_in[19:15]&{5{wb_valid}}),
		.wb_dest_rdy(1'd1),	
		.mem_dest(pipe3_ctrl_info_in[24:20]&{5{pipe3_valid_out}}),
		.mem_dest_rdy(mem_dest_rdy),
		.ex_dest(pipe2_ctrl_info_in[43:39]&{5{pipe2_valid_out}}),
		.ex_dest_rdy(ex_dest_rdy),

		.wb_res(wdata),
		.mem_res(pipe3_data_info_out),
		.ex_res(alu_result),

		.inta(0),

		.pipe1_valid_in(pipe1_valid_in), 
		.pipe1_ctrl_info_in(pipe1_ctrl_info_in), 
		.pipe1_data_info_in(pipe1_data_info_in),
		.pipe1_valid_out(pipe1_valid_out), 
		.pipe1_ctrl_info_out(pipe1_ctrl_info_out), 
		.pipe1_data_info_out(pipe1_data_info_out),
		.pipe1_allow_out(pipe1_allow_out), 
		.pipe1_allow_in(pipe1_allow_in)
		);

	Reg_1_2 ID_EX_REG(.clk(clk),
		.reset(other_reset),
		.pipe1_valid_out(pipe1_valid_out), 
		.pipe1_ctrl_info_out(pipe1_ctrl_info_out), 
		.pipe1_data_info_out(pipe1_data_info_out),
		.pipe2_valid_in(pipe2_valid_in),	
		.pipe2_ctrl_info_in(pipe2_ctrl_info_in),
		.pipe2_data_info_in(pipe2_data_info_in),
		.pipe1_allow_out(pipe1_allow_out), 
		.pipe2_allow_in(pipe2_allow_in)
	);

	PIPE2 EX(
		.pipe2_valid_in(pipe2_valid_in),
		.pipe2_ctrl_info_in(pipe2_ctrl_info_in), 
		// eret 81(),int 80(),syscall 79(),break 78(),id_ri_ex 77(),if_adel 76
		//pc 75:44(),dest 43:39(),(|branch_type) 38(),bypass_op 37 (),logic_type 36:32
		//shift_type 31:29(),imm_op 28(),unsigned_op 27(),sub_op 26(),link_op 25(),store_type 24:22 (),store_op 21
		//alu_res_sel 20:19(),load_type 18:15(),load_op 14(),hi_we 13(),lo_we 12(),cp0_write 11
		//cs 10:6(),sel [2:0] 5:3(),wb_mux 2:1(),reg_we 0
		.pipe2_data_info_in(pipe2_data_info_in),
		// vsrc1 79:48 vsrc2 47:16 imm 15:0
		.pipe2_valid_out(pipe2_valid_out), 
		.pipe2_ctrl_info_out(pipe2_ctrl_info_out), 	
		.pipe2_data_info_out(pipe2_data_info_out),
		// memvalue 33:2  offset 1:0
		.pipe2_allow_out(pipe2_allow_out), 
		.pipe2_allow_in(pipe2_allow_in),	
		.addr_out(data_addr),
		.we_out(data_ram_we),
		.din_out(data_ram_data_in),

		.alu_result(alu_result),
		.ex_dest_rdy(ex_dest_rdy)
		);

	Reg_2_3 EX_MEM_REG(.clk(clk),
		.reset(other_reset), 
		.pipe2_valid_out(pipe2_valid_out), 
		.pipe2_ctrl_info_out(pipe2_ctrl_info_out), 
		.pipe2_data_info_out(pipe2_data_info_out),
		.pipe3_valid_in(pipe3_valid_in),
		.pipe3_ctrl_info_in(pipe3_ctrl_info_in),
		.pipe3_data_info_in(pipe3_data_info_in),
		.pipe2_allow_out(pipe2_allow_out), 
		.pipe3_allow_in(pipe3_allow_in)
	);

	PIPE3 MEM(
		.dout(data_ram_data_out),//we do
		.pipe3_valid_in(pipe3_valid_in), 
		.pipe3_ctrl_info_in(pipe3_ctrl_info_in),
		//exc-type65-57(),pc56-25(),dest24-20(),btype19(),load_type18-15(),load_op14(),hiwe13ï¼Œlowe12ï¼Œcp0we11(),cp0cs10-6(),cp0sel5-3ï¼Œwbmux2-1ï¼Œregwe0 
		.pipe3_valid_out(pipe3_valid_out),
		.pipe3_data_info_in(pipe3_data_info_in),
		.pipe3_ctrl_info_out(pipe3_ctrl_info_out), 
	
		.pipe3_data_info_out(pipe3_data_info_out),
		.pipe3_allow_out(pipe3_allow_out), 
		.pipe3_allow_in(pipe3_allow_in),	
		.mem_dest_rdy(mem_dest_rdy)
		);

	Reg_3_4 MEM_WB_REG(.clk(clk),
		.reset(other_reset),	
		.pipe3_valid_out(pipe3_valid_out), 
		.pipe3_ctrl_info_out(pipe3_ctrl_info_out), 
		.pipe3_data_info_out(pipe3_data_info_out),
		.pipe4_valid_in(pipe4_valid_in),	
		.pipe4_ctrl_info_in(pipe4_ctrl_info_in),
		.pipe4_data_info_in(pipe4_data_info_in),
		.pipe3_allow_out(pipe3_allow_out), 
		.pipe4_allow_in(pipe4_allow_in)
	);

	PIPE4 WB(
		.clk(clk),
		.FPGA_rst(~resetn),
		.rst(wb_reset),
		.pipe4_valid_in(pipe4_valid_in),
		.pipe4_ctrl_info_in(pipe4_ctrl_info_in),
		
		.pipe4_data_info_in(pipe4_data_info_in),
		// .[XXX:0] pipe4_ctrl_info_out(), 
		// .[YYY:0] pipe4_data_info_out(),
		.wdata(wdata),
		.we(reg_we),
		.waddr(waddr),
		.e_cause(e_cause),
		.is_exl(is_exl),
		.eret(eret),
		.e_pc(e_pc),
		// .pipe4_allow_out(pipe4_allow_out),	
		.pipe4_allow_in(pipe4_allow_in), 
		.pipe4_valid_out(wb_valid),
		.wb_pc(wb_pc)

	);

	exl_addr_get EXL_ADDR(.is_exl(is_exl),
		.cause_type(e_cause),
		.wb_reset(wb_reset),
		.cp0_epc(e_pc),
		.eret(eret),
		.ex_addr(ex_addr),
		.ex_taken(ex_taken),
		.other_reset(other_reset)
	);

	regfiles MYREG(wdata,raddr1,raddr2,waddr,clk,reg_we,rdata1,rdata2,wb_reset,rf_0,rf_1, rf_2, rf_3, rf_4, rf_5, rf_6, rf_7, rf_8, rf_9, rf_10, rf_11, rf_12, rf_13, rf_14, rf_15, rf_16, rf_17, rf_18, rf_19, rf_20, rf_21, rf_22, rf_23, rf_24, rf_25, rf_26, rf_27, rf_28, rf_29, rf_30, rf_31);


endmodule