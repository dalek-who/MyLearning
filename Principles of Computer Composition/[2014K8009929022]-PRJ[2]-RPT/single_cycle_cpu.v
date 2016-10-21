module single_cycle_cpu(rst,clk,PC,Instruction,Address,MemWrite,Write_data,MemRead,Read_data);
  input rst,clk;
  input [31:0]Instruction,Read_data;
  output MemWrite,MemRead;
  output [31:0]PC,Address,Write_data;
  reg [31:0]PC;
  
  wire PCSrc;//cpu
  
  wire [31:0]A,B;wire [2:0]ALUop;wire Overflow,Zero,CarryOut;wire [31:0]Result;//alu
  
  wire wen;wire [4:0]raddr1,raddr2,waddr;wire [31:0]wdata;wire [31:0]rdata1,rdata2;//regfiles
  
  wire [1:0]ALUOp;wire [5:0]FunctionCode;wire [2:0]ALUcontrol;//Generating_ALU_Control
  
  wire [5:0]Opcode;wire RegDst,ALUSrc,MemtoReg,RegWrite,MemRead,MemWrite,Branch,ALUOp1,ALUOp0;//Control_Truth_Table
  
  alu part1(A,B,ALUop,Overflow,Zero,CarryOut,Result);
  regfiles part2(clk,rst,wen,raddr1,raddr2,waddr,wdata,rdata1,rdata2);
  Generating_ALU_Control part3(ALUOp,FunctionCode,ALUcontrol);
  Control_Truth_Table part4(Opcode,RegDst,ALUSrc,MemtoReg,RegWrite,MemRead,MemWrite,Branch,ALUOp1,ALUOp0);
  
  always @(posedge clk or posedge rst) 
  begin
    if(rst)
      PC<=32'b0;
    else
      PC<=(PCSrc)? PC+4+((Instruction[15])? {14'h3fff,Instruction[15:0],2'b0}:{14'b0,Instruction[15:0],2'b0}):PC+4;
  end
  
  assign PCSrc=Branch&Zero;
  assign Address=Result;
  assign Write_data=rdata2;
  //cpu
  assign A=rdata1;
  assign B= (ALUSrc)? ((Instruction[15])? {16'hffff,Instruction[15:0]}:{16'b0,Instruction[15:0]}) : rdata2;
  assign ALUop=ALUcontrol;
  //alu
  assign wen=RegWrite;
  assign raddr1=Instruction[25:21];
  assign raddr2=Instruction[20:16];
  assign waddr= (RegDst)? Instruction[15:11]:Instruction[20:16];
  assign wdata= (MemtoReg)? Read_data:Result;
  //regfiles
  assign ALUOp[1]=ALUOp1;
  assign ALUOp[0]=ALUOp0;
  assign FunctionCode=Instruction[5:0];
  //Generating_ALU_Control
  assign Opcode=Instruction[31:26];
  //Control_Truth_Table

endmodule

module Generating_ALU_Control(ALUOp,FunctionCode,ALUcontrol);
  input [1:0]ALUOp;
  input [5:0]FunctionCode;
  output [2:0]ALUcontrol;
  reg [2:0]ALUcontrol;
  
  always @(ALUOp or FunctionCode)
  begin
    case(ALUOp)
      2'b00:ALUcontrol=3'b010;//add
      2'b01:ALUcontrol=3'b110;//sub
      2'b10:
      begin
        case(FunctionCode)
          6'b100000:ALUcontrol=3'b010;//add
          6'b100010:ALUcontrol=3'b110;//sub
          6'b100100:ALUcontrol=3'b000;//and
          6'b100101:ALUcontrol=3'b001;//or
          6'b101010:ALUcontrol=3'b111;//slt
          default:ALUcontrol=3'b000;
        endcase
      end
      default:ALUcontrol=3'b000;
    endcase
  end
    
endmodule

module Control_Truth_Table(Opcode,RegDst,ALUSrc,MemtoReg,RegWrite,MemRead,MemWrite,Branch,ALUOp1,ALUOp0);
  input [5:0]Opcode;
  output RegDst,ALUSrc,MemtoReg,RegWrite,MemRead,MemWrite,Branch,ALUOp1,ALUOp0;
  reg RegDst,ALUSrc,MemtoReg,RegWrite,MemRead,MemWrite,Branch,ALUOp1,ALUOp0;
  
  always @(Opcode)
  begin
    case(Opcode)
      6'b000000://waddr=Instruction[15:11],B=rdata2,wdata=Result,wen=1,MemRead=0,MemWrite=0,PC=PC+4,case(FunctionCode)
      begin
        RegDst=1'b1;ALUSrc=1'b0;MemtoReg=1'b0;RegWrite=1'b1;MemRead=1'b0;MemWrite=1'b0;Branch=1'b0;ALUOp1=1'b1;ALUOp0=1'b0;
      end
      6'b100011://waddr=Instruction[20:16],B=Instruction[15:0],wdata=Read_data,wen=1,MemRead=1,MemWrite=0,PC=PC+4,add
      begin
        RegDst=1'b0;ALUSrc=1'b1;MemtoReg=1'b1;RegWrite=1'b1;MemRead=1'b1;MemWrite=1'b0;Branch=1'b0;ALUOp1=1'b0;ALUOp0=1'b0;
      end
      6'b101011://B=Instruction[15:0],wen=0,MemRead=0,MemWrite=1,PC=PC+4,add
      begin
        RegDst=1'b0;ALUSrc=1'b1;MemtoReg=1'b0;RegWrite=1'b0;MemRead=1'b0;MemWrite=1'b1;Branch=1'b0;ALUOp1=1'b0;ALUOp0=1'b0;
      end
      6'b000100://B=rdata2,wen=0,MemRead=0,MemWrite=0,PC=PC+4+Insturction[15:0],sub
      begin
        RegDst=1'b0;ALUSrc=1'b0;MemtoReg=1'b0;RegWrite=1'b0;MemRead=1'b0;MemWrite=1'b0;Branch=1'b1;ALUOp1=1'b0;ALUOp0=1'b1;
      end
      default:
      begin
        RegDst=1'b0;ALUSrc=1'b0;MemtoReg=1'b0;RegWrite=1'b0;MemRead=1'b0;MemWrite=1'b0;Branch=1'b0;ALUOp1=1'b0;ALUOp0=1'b0;
      end
    endcase
  end
  
endmodule
  