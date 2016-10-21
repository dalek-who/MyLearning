module multi_cycle_cpu(rst,clk,Address,MemWrite,Write_data,MemRead,Read_data);
  input rst,clk;
  input [31:0]Read_data;
  output MemWrite,MemRead;
  output [31:0]Address,Write_data;
  
  reg [31:0]PC,ALUOut,A,B,Instruction,MemWdata;
  wire [31:0]pc;
  //Outputs Control
  wire PCWrite,PCWriteCond,IorD,MemRead,MemWrite,IRWrite,MemtoReg,ALUSrcA,RegWrite,RegDst;
  wire [1:0]PCSource,ALUOp,ALUSrcB;
  reg [3:0]NState,State;
  wire [5:0]Op;
  wire [9:0]state;
  //ALU control
  wire [5:0]FunctionCode;
  reg [2:0]ALUcontrol;
  //alu
  wire [31:0]C,D,Result;
  wire [2:0]ALUop;
  wire Overflow,Zero,CarryOut;
  wire [31:0]Signextend,Signextend2;
  //regfiles
  wire wen;
  wire [4:0]raddr1,raddr2,waddr;
  wire [31:0]rdata1,rdata2,wdata;
  
  alu alu1(C,D,ALUop,Overflow,Zero,CarryOut,Result);
  regfiles regfiles1(clk,rst,wen,raddr1,raddr2,waddr,wdata,rdata1,rdata2);
  
  //multi_cycle_cpu  
  always @(posedge clk or posedge rst)
  begin
    if(rst)
      begin
        PC<=32'b0;
        A<=32'b0;
        Instruction<=32'b0;
        B<=32'b0;
        ALUOut<=32'b0;
        MemWdata<=32'b0;
        NState<=4'b0;
        State<=4'b0;
      end
    else
      begin
        if(PCWrite|(PCWriteCond&Zero))
          PC<=pc;
        else PC<=PC;
        if(IRWrite)
          Instruction<=Read_data;
        else
          Instruction<=Instruction;
        ALUOut<=Result;
        A<=rdata1;
        B<=rdata2;
        MemWdata<=Read_data;
        State<=NState;
      end
  end

  assign Address= (IorD)? ALUOut:PC;
  assign Write_data=B;
  assign pc= (PCSource[1])? {PC[31:28],Instruction[25:0],2'b00}:( (PCSource[0])? ALUOut:Result );
  
  //Outputs Control
  assign state[0]=(State==4'd0)? 1:0;
  assign state[1]=(State==4'd1)? 1:0;
  assign state[2]=(State==4'd2)? 1:0;
  assign state[3]=(State==4'd3)? 1:0;
  assign state[4]=(State==4'd4)? 1:0;
  assign state[5]=(State==4'd5)? 1:0;
  assign state[6]=(State==4'd6)? 1:0;
  assign state[7]=(State==4'd7)? 1:0;
  assign state[8]=(State==4'd8)? 1:0;
  assign state[9]=(State==4'd9)? 1:0;
  assign Op=Instruction[31:26];
  assign PCWrite=state[0]|state[9];
  assign PCWriteCond=state[8];
  assign IorD=state[3]|state[5];
  assign MemRead=state[0]|state[3];
  assign MemWrite=state[5];
  assign IRWrite=state[0];
  assign MemtoReg=state[4];
  assign PCSource[1]=state[9];
  assign PCSource[0]=state[8];
  assign ALUOp[1]=state[6];
  assign ALUOp[0]=state[8];
  assign ALUSrcB[1]=state[1]|state[2];
  assign ALUSrcB[0]=state[0]|state[1];
  assign ALUSrcA=state[2]|state[6]|state[8];
  assign RegWrite=state[4]|state[7];
  assign RegDst=state[7];
  always @(Op or State)
  begin
    case(State)
      4'b0000:NState=4'b0001;
      4'b0001:
        begin
          case(Op)
            6'b000000:NState=4'b0110;//R-type
            6'b100011:NState=4'b0010;//lw
            6'b101011:NState=4'b0010;//sw
            6'b000100:NState=4'b1000;//beq
            default:NState=4'b0000;
          endcase
        end
      4'b0010:
        begin
          case(Op)
            6'b100011:NState=4'b0011;//lw
            6'b101011:NState=4'b0101;//sw
            default:NState=4'b0000;
          endcase
        end
      4'b0011:NState=4'b0100;
      4'b0110:NState=4'b0111;
      default:NState=4'b0000;
    endcase
  end
  
  //ALU control
  assign FunctionCode=Instruction[5:0];
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
  
  //alu
  assign ALUop=ALUcontrol;
  assign C= (ALUSrcA)? A:PC;
  assign D= (ALUSrcB[1])? ( (ALUSrcB[0])? Signextend2:Signextend):( (ALUSrcB[0])? 32'd4:B);
  assign Signextend= (Instruction[15])? {16'hffff,Instruction[15:0]}:{16'b0,Instruction[15:0]};
  assign Signextend2= (Instruction[15])? {14'h3fff,Instruction[15:0],2'b0}:{14'b0,Instruction[15:0],2'b0};
  //regfiles
  assign raddr1=Instruction[25:21];
  assign raddr2=Instruction[20:16];
  assign waddr= (RegDst)? Instruction[15:11]:Instruction[20:16];
  assign wdata= (MemtoReg)? MemWdata:ALUOut;
  assign wen=RegWrite;

  
endmodule