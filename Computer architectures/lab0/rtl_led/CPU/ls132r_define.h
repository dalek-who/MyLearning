`timescale 1ns/10ps

/****** Configuration ******/

`define LS132R_AXI_IF
`define LS132R_BUS_32BIT
//`define LS132R_BUS_64BIT
//`define LS132R_BUS_128BIT

`define LS132R_INST_SRAM_IFC

`ifdef LS132R_INST_SRAM_IFC
  `define LS132R_INST_SRAM_32BIT
  //`define LS132R_INST_SRAM_64BIT
  //`define LS132R_INST_SRAM_128BIT
  //`define LS132R_INST_SRAM_256BIT

  `define LS132R_INST_SRAM_MASK     32'hffff_0000
  `define LS132R_INST_SRAM_WINDOW   32'h0000_0000
`endif


`define LS132R_DATA_SRAM_IFC

`ifdef LS132R_DATA_SRAM_IFC
  `define LS132R_DATA_SRAM_32BIT
  //`define LS132R_DATA_SRAM_64BIT
  //`define LS132R_DATA_SRAM_128BIT
  //`define LS132R_DATA_SRAM_256BIT
    
  `define LS132R_DATA_SRAM_MASK     32'hffff_0000
  `define LS132R_DATA_SRAM_WINDOW   32'h0800_0000
`endif

`ifdef LS132R_INST_SRAM_IFC
`ifdef LS132R_DATA_SRAM_IFC 
  `define LS132R_DATA_SRAM_REDIRECT
`endif
`endif

//`define LS132R_MIPS32_RELEASE2 //not implement yet

  `define LS132R_SERIAL_MUL
//`define LS132R_HALF_SIZE_MUL
//`define LS132R_FULL_SIZE_MUL

//`define LS132R_TLB_MMU         //not implement yet
`define LS132R_FIX_MAPPING_MMU
//`define LS132R_BAT_MAPPING_MMU //not implement yet

//`define LS132R_HAVE_CACHE      //not implement yet
`ifdef LS132R_HAVE_CACHE
  //`define LS132R_HAVE_L1_ICACHE
  //`define LS132R_HAVE_L1_DCACHE
  //`define LS132R_HAVE_L2_SCACHE
  //`define LS132R_HAVE_L3_SCACHE
`endif

//`define LS132R_COUNT_DISABLE

//`define LS132R_HAVE_PROFILING

//`define LS132R_HAVE_WATCH


/****** Use DesignWare ******/
//`define LS132R_MUL_USE_DW
//`define LS132R_DIV_USE_DW
//`define LS132R_MUL_DIV_USE_DW




/****** Bus Width ******/
`define Lcpustbus       26
`define Lirbus          68
`define Lissuebus       260
`define Lwbbus          109
`define Lexbus          46
`define Lbrbus          67
`define Ldecstbus       37
`define Lexestbus       4
`define Ltoifcbus       74
`define Lfromifcbus     35
`define Ldmsegdreqbus   68
`define Ldmsegireqbus   35
`define Ldmsegdresbus   34
`define Ldmsegiresbus   34
`define Licompbus       33
`define Ldrsegreqbus    66

/****** Internal bus width ******/
`define LS132R_WIDTH_BLOCK  4'b0001 
`define LS132R_WIDTH_64BIT  4'b1111 
`define LS132R_WIDTH_24BIT  4'b1011 
`define LS132R_WIDTH_32BIT  4'b1010 
`define LS132R_WIDTH_16BIT  4'b1001 
`define LS132R_WIDTH_8BIT   4'b1000 
`define LS132R_WIDTH_FULL   4'b0000 

/****** Internal Excode ******/
/* EX_RESET     */  /* EX_EJTAGBOOT */  
/* EX_SOFTRESET */ 
/* EX_NMI       */ 
`define LS132R_EX_INT          6'h00 //Interrupt
`define LS132R_EX_MOD          6'h01 //TLB Modification
`define LS132R_EX_TLBLR        6'h22 //TLB Refill  (load or fetch)
`define LS132R_EX_TLBLI        6'h02 //TLB Invalid (load or fetch)
`define LS132R_EX_TLBSR        6'h23 //TLB Refill  (store)
`define LS132R_EX_TLBSI        6'h03 //TLB Invalid (store)
`define LS132R_EX_ADEL         6'h04 //Address Error (load or fetch)
`define LS132R_EX_ADES         6'h05 //Address Error (store)
`define LS132R_EX_IBE          6'h06 //Bus Error (instruction fetch)
`define LS132R_EX_DBE          6'h07 //Bus Error (load or store)
`define LS132R_EX_SYS          6'h08 //Syscall
`define LS132R_EX_BP           6'h09 //Breakpoint
`define LS132R_EX_RI           6'h0a //Reserved Instruction
`define LS132R_EX_CPU          6'h0b //Coprocessor Unusable
`define LS132R_EX_OV           6'h0c //Arithmatic Overflow
`define LS132R_EX_TRAP         6'h0d //Trap
`define LS132R_EX_FPE          6'h0f //Float Point Exception
`define LS132R_EX_TLBRI        6'h13 //TLB Read-Inhibit
`define LS132R_EX_TLBXI        6'h14 //TLB Execution-Inhibit
`define LS132R_EX_WATCH        6'h17 //Reference to WatchHi/WatchLo Address
`define LS132R_EX_MCHECK       6'h18 //Machine Check
`define LS132R_EX_CACHEERR     6'h1e //Cache Error

`define LS132R_EX_DSS          6'h20 //Debug Sigle Step
`define LS132R_EX_DBP          6'h21 //Debug Breakpoint
`define LS132R_EX_DDBL         6'h22 //Debug Data Break Load
`define LS132R_EX_DDBS         6'h23 //Debug Data Break Store
`define LS132R_EX_DIB          6'h24 //Debug Instruction Break
`define LS132R_EX_DINT         6'h25 //Debug Interrupt
`define LS132R_EX_DDBLIMPR     6'h32 //Debug Data Break Load Imprecise
`define LS132R_EX_DDBSIMPR     6'h33 //Debug Data Break Store Imprecise


/****** Vector Interrupt Entries ******/
`ifdef LS132R_RANDOM_TEST

`define LS132R_INT0_ENTRY_BEV0  32'hbfc0_0400
`define LS132R_INT1_ENTRY_BEV0  32'hbfc0_0410
`define LS132R_INT2_ENTRY_BEV0  32'hbfc0_0420
`define LS132R_INT3_ENTRY_BEV0  32'hbfc0_0430
`define LS132R_INT4_ENTRY_BEV0  32'hbfc0_0440
`define LS132R_INT5_ENTRY_BEV0  32'hbfc0_0450
`define LS132R_INT6_ENTRY_BEV0  32'hbfc0_0460
`define LS132R_INT7_ENTRY_BEV0  32'hbfc0_0470

`else

`define LS132R_INT0_ENTRY_BEV0  32'h8000_0200
`define LS132R_INT1_ENTRY_BEV0  32'h8000_0220
`define LS132R_INT2_ENTRY_BEV0  32'h8000_0240
`define LS132R_INT3_ENTRY_BEV0  32'h8000_0260
`define LS132R_INT4_ENTRY_BEV0  32'h8000_0280
`define LS132R_INT5_ENTRY_BEV0  32'h8000_02a0
`define LS132R_INT6_ENTRY_BEV0  32'h8000_02c0
`define LS132R_INT7_ENTRY_BEV0  32'h8000_02e0

`endif

/****** Internal Op & Fmt Code ******/
/*Fix point operation*/
`define LS132R_OP_CLO      8'h00 
`define LS132R_OP_CLZ      8'h01 
`define LS132R_OP_EXT      8'h02
`define LS132R_OP_INS      8'h03
`define LS132R_OP_WSBH     8'h04
`define LS132R_OP_MOV      8'h05 //LUI,RDPGPR,WRPGPR
`define LS132R_OP_ROTR     8'h06 //ROTRV
`define LS132R_OP_SEB      8'h08
`define LS132R_OP_SEH      8'h09
`define LS132R_OP_MOVN     8'h0a 
`define LS132R_OP_MOVZ     8'h0b 
`define LS132R_OP_MFHI     8'h0c 
`define LS132R_OP_MFLO     8'h0d 
`define LS132R_OP_MTHI     8'h0e 
`define LS132R_OP_MTLO     8'h0f 
`define LS132R_OP_MUL      8'h10 
`define LS132R_OP_SLL      8'h11 //NOP,SSNOP,EHB,SLLV
`define LS132R_OP_SRL      8'h12 //SRLV
`define LS132R_OP_SRA      8'h13
`define LS132R_OP_MULT     8'h14 
`define LS132R_OP_MULTU    8'h15 
`define LS132R_OP_DIV      8'h16
`define LS132R_OP_DIVU     8'h17
`define LS132R_OP_ADD      8'h18 //ADDI
`define LS132R_OP_ADDU     8'h19 //ADDIU,
`define LS132R_OP_SUB      8'h1a
`define LS132R_OP_SUBU     8'h1b
`define LS132R_OP_AND      8'h1c //ANDI
`define LS132R_OP_OR       8'h1d //ORI
`define LS132R_OP_XOR      8'h1e //XORI
`define LS132R_OP_NOR      8'h1f
`define LS132R_OP_TEQ      8'h20 //TEQI
`define LS132R_OP_TNE      8'h21 //TNEI
`define LS132R_OP_TLT      8'h22 //TLTI
`define LS132R_OP_TLTU     8'h23 //TLTIU
`define LS132R_OP_TGE      8'h24 //TGEI`
`define LS132R_OP_TGEU     8'h25 //TEEI
`define LS132R_OP_SLT      8'h26 //SLTI
`define LS132R_OP_SLTU     8'h27 //SLTIU
`define LS132R_OP_MADD     8'h28 
`define LS132R_OP_MADDU    8'h29 
`define LS132R_OP_MSUB     8'h2a 
`define LS132R_OP_MSUBU    8'h2b 
`define LS132R_OP_J        8'h2c
`define LS132R_OP_JR       8'h2d //JR.HB
`define LS132R_OP_JAL      8'h2e 
`define LS132R_OP_JALR     8'h2f //JALR.HB
`define LS132R_OP_BEQ      8'h30
`define LS132R_OP_BNE      8'h31
`define LS132R_OP_BLEZ     8'h32
`define LS132R_OP_BGTZ     8'h33
`define LS132R_OP_BLTZ     8'h34
`define LS132R_OP_BGEZ     8'h35
`define LS132R_OP_BLTZAL   8'h36
`define LS132R_OP_BGEZAL   8'h37
`define LS132R_OP_BEQL     8'h38
`define LS132R_OP_BNEL     8'h39
`define LS132R_OP_BLEZL    8'h3a
`define LS132R_OP_BGTZL    8'h3b
`define LS132R_OP_BLTZL    8'h3c
`define LS132R_OP_BGEZL    8'h3d
`define LS132R_OP_BLTZALL  8'h3e
`define LS132R_OP_BGEZALL  8'h3f
 
/*CP0 operation*/
`define LS132R_OP_MFC1     8'h80 
`define LS132R_OP_CFC1     8'h81 
`define LS132R_OP_MTC1     8'h82 
`define LS132R_OP_CTC1     8'h83 
`define LS132R_OP_DI       8'h84 
`define LS132R_OP_EI       8'h85 
`define LS132R_OP_SYNC     8'h86
`define LS132R_OP_ERET     8'h87
`define LS132R_OP_TLBP     8'h88
`define LS132R_OP_TLBR     8'h89
`define LS132R_OP_TLBWI    8'h8a
`define LS132R_OP_TLBWR    8'h8b
`define LS132R_OP_MFC0     8'h8c //RDHWR
`define LS132R_OP_MTC0     8'h8d
`define LS132R_OP_SYNCI    8'h8e 
`define LS132R_OP_DERET    8'h8f
`define LS132R_OP_LB       8'h90
`define LS132R_OP_LH       8'h91
`define LS132R_OP_LW       8'h92 
`define LS132R_OP_LDC1     8'h93
`define LS132R_OP_LBU      8'h94
`define LS132R_OP_LHU      8'h95
`define LS132R_OP_LL       8'h96
`define LS132R_OP_PREF     8'h97
`define LS132R_OP_SB       8'h98
`define LS132R_OP_SH       8'h99
`define LS132R_OP_SW       8'h9a 
`define LS132R_OP_SDC1     8'h9b 
`define LS132R_OP_LBUX     8'h9c 
`define LS132R_OP_LHX      8'h9d 
`define LS132R_OP_SC       8'h9e
`define LS132R_OP_LWX      8'h9f 
`define LS132R_OP_CACHE0   8'ha0
`define LS132R_OP_CACHE1   8'ha1
`define LS132R_OP_LWC1     8'ha2
`define LS132R_OP_SWC1     8'ha3
`define LS132R_OP_CACHE4   8'ha4
`define LS132R_OP_CACHE5   8'ha5
`define LS132R_OP_PREFX    8'ha6
`define LS132R_OP_CACHE7   8'ha7
`define LS132R_OP_CACHE8   8'ha8
`define LS132R_OP_CACHE9   8'ha9
`define LS132R_OP_CACHE10  8'haa
`define LS132R_OP_CACHE11  8'hab
`define LS132R_OP_CACHE12  8'hac
`define LS132R_OP_CACHE13  8'had
`define LS132R_OP_CACHE14  8'hae
`define LS132R_OP_CACHE15  8'haf
`define LS132R_OP_CACHE16  8'hb0
`define LS132R_OP_CACHE17  8'hb1
`define LS132R_OP_CACHE18  8'hb2
`define LS132R_OP_CACHE19  8'hb3
`define LS132R_OP_CACHE20  8'hb4
`define LS132R_OP_CACHE21  8'hb5
`define LS132R_OP_CACHE22  8'hb6
`define LS132R_OP_CACHE23  8'hb7
`define LS132R_OP_LWL      8'hb8
`define LS132R_OP_LWR      8'hb9
`define LS132R_OP_SWL      8'hba
`define LS132R_OP_SWR      8'hbb
`define LS132R_OP_CACHE28  8'hbc
`define LS132R_OP_CACHE29  8'hbd
`define LS132R_OP_CACHE30  8'hbe
`define LS132R_OP_CACHE31  8'hbf
 
/*Floating point operation*/ //same as LS232
`define LS132R_OP_FADD     8'h40
`define LS132R_OP_FSUB     8'h41
`define LS132R_OP_FMUL     8'h42
`define LS132R_OP_FDIV     8'h43
`define LS132R_OP_FSQRT    8'h44
`define LS132R_OP_FABS     8'h45
`define LS132R_OP_FMOV     8'h46
`define LS132R_OP_FNEG     8'h47
`define LS132R_OP_ROUNDL   8'h48
`define LS132R_OP_TRUNCL   8'h49
`define LS132R_OP_CEILL    8'h4a
`define LS132R_OP_FLOORL   8'h4b
`define LS132R_OP_ROUNDW   8'h4c
`define LS132R_OP_TRUNCW   8'h4d
`define LS132R_OP_CEILW    8'h4e
`define LS132R_OP_FLOORW   8'h4f
`define LS132R_OP_RECIP    8'h5c
`define LS132R_OP_RSQRT    8'h5d
`define LS132R_OP_CVTS     8'h60
`define LS132R_OP_CVTD     8'h61
`define LS132R_OP_CVTW     8'h64
`define LS132R_OP_CVTL     8'h65
`define LS132R_OP_MOVF     8'h66
`define LS132R_OP_MOVT     8'h67
`define LS132R_OP_BC1F     8'h68
`define LS132R_OP_BC1T     8'h69
`define LS132R_OP_BC1FL    8'h6a
`define LS132R_OP_BC1TL    8'h6b
`define LS132R_OP_FMOVF    8'h6c
`define LS132R_OP_FMOVT    8'h6d
`define LS132R_OP_FMOVZ    8'h6e
`define LS132R_OP_FMOVN    8'h6f
`define LS132R_OP_CF       8'h70
`define LS132R_OP_CUN      8'h71
`define LS132R_OP_CEQ      8'h72
`define LS132R_OP_CUEQ     8'h73
`define LS132R_OP_COLT     8'h74
`define LS132R_OP_CULT     8'h75
`define LS132R_OP_COLE     8'h76
`define LS132R_OP_CULE     8'h77
`define LS132R_OP_CSF      8'h78
`define LS132R_OP_CNGLE    8'h79
`define LS132R_OP_CSEQ     8'h7a
`define LS132R_OP_CNGL     8'h7b
`define LS132R_OP_CLT      8'h7c
`define LS132R_OP_CNGE     8'h7d
`define LS132R_OP_CLE      8'h7e
`define LS132R_OP_CNGT     8'h7f

/*Floating point format*/
`define LS132R_FMT_S       5'h10
`define LS132R_FMT_D       5'h11
`define LS132R_FMT_W       5'h14
`define LS132R_FMT_L       5'h15
`define LS132R_FMT_PS      5'hb

`define LS132R_CCA_UNCACHE  3'b010
`define LS132R_CCA_CACHE    3'b011

/****** MIPS32 Op & Fmt Code ******/
`define MIPS32_FMT_S        5'h10
`define MIPS32_FMT_D        5'h11
`define MIPS32_FMT_W        5'h14
`define MIPS32_FMT_L        5'h15
`define MIPS32_FMT_PS       5'h16

`define MIPS32_COND_F       4'h0
`define MIPS32_COND_UN      4'h1
`define MIPS32_COND_EQ      4'h2
`define MIPS32_COND_UEQ     4'h3
`define MIPS32_COND_OLT     4'h4
`define MIPS32_COND_ULT     4'h5
`define MIPS32_COND_OLE     4'h6
`define MIPS32_COND_ULE     4'h7
`define MIPS32_COND_SF      4'h8
`define MIPS32_COND_NGLE    4'h9
`define MIPS32_COND_SEQ     4'ha
`define MIPS32_COND_NGL     4'hb
`define MIPS32_COND_LT      4'hc
`define MIPS32_COND_NGE     4'hd
`define MIPS32_COND_LE      4'he
`define MIPS32_COND_NGT     4'hf


/****** AXI Parameter ******/
// burst type
`define AXI_BURST_FIXED 2'b00
`define AXI_BURST_INCR  2'b01
`define AXI_BURST_WRAP  2'b10

// burst length
`define AXI_LEN_1       4'h0
`define AXI_LEN_2       4'h1
`define AXI_LEN_4       4'h3
`define AXI_LEN_8       4'h7

// burst size
`define AXI_SIZE_1B     3'b000 
`define AXI_SIZE_2B     3'b001
`define AXI_SIZE_4B     3'b010
`define AXI_SIZE_8B     3'b011
`define AXI_SIZE_16B    3'b100

// lock type
`define AXI_LOCK_NORMAL 2'b00

// cache & coherence attribute
`define AXI_NO_CACHE_NO_BUF 4'b0000 

// prot attribute
`define AXI_PROT0_NORMAL    1'b0
`define AXI_PROT1_NONSECURE 1'b1
`define AXI_PROT2_DATA      1'b1
`define AXI_PROT2_INST      1'b0




