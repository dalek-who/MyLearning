module alu(A,B,ALUop,Overflow,Zero,CarryOut,Result);
  input [31:0]A,B;
  input [2:0]ALUop;
  output Overflow,Zero,CarryOut;
  output [31:0]Result;
  wire cin;
  reg [31:0]result;
  wire [31:0]result1,C;
  wire [6:0]cout;

  assign C= (ALUop[2]==1)? ~B:B;
  assign cin=ALUop[2];
  
  add32 part1(cout,result1,A,C,cin);
    
  always @(A or B or result1 or cout or ALUop)
  begin
    case(ALUop)
      3'b000:result=A&B;
      3'b001:result=A|B;
      3'b010:
      begin
        result=result1;
      end
      3'b110:
      begin
        result=result1;
      end
      3'b111:
      begin
        if( (~(cout[6]^cout[5])&&result1[31]) || ((cout[6]^cout[5])&&cout[6]) )
          result=32'b1;
        else
          result=32'b0;
      end
      default:result=32'b0;
    endcase
  end

  assign Overflow=((~ALUop[2]&ALUop[1]&~ALUop[0])|(ALUop[2]&ALUop[1]&~ALUop[0])) & (cout[6]^cout[5]);
  assign Zero=((~ALUop[2]&ALUop[1]&~ALUop[0])|(ALUop[2]&ALUop[1]&~ALUop[0])) & (~|Result);
  assign CarryOut=((~ALUop[2]&ALUop[1]&~ALUop[0])|(ALUop[2]&ALUop[1]&~ALUop[0])) & cout[6];
  assign Result=result;
  
endmodule

module add32(cout,sum,a,b,cin);
  input [31:0]a,b;
  input cin;
  output [31:0]sum;
  output [6:0]cout;

  add8 p1(cout[0],sum[7:0],a[7:0],b[7:0],cin);
  add8 p2(cout[1],sum[15:8],a[15:8],b[15:8],cout[0]);
  add8 p3(cout[2],sum[23:16],a[23:16],b[23:16],cout[1]);
  add4 p4(cout[3],sum[27:24],a[27:24],b[27:24],cout[2]);
  add2 p5(cout[4],sum[29:28],a[29:28],b[29:28],cout[3]);
  add1 p6(cout[5],sum[30],a[30],b[30],cout[4]);
  add1 p7(cout[6],sum[31],a[31],b[31],cout[5]);
  
endmodule

module add1(cout,sum,a,b,cin);
  input a,b;
  input cin;
  output sum;
  output cout;
  
  wire p,g,c;
  
  assign p=a|b;
  assign g=a&b;
  assign c=g|(p&cin);
  assign {cout,sum}=a^b^{c,cin};
  
endmodule

module add2(cout,sum,a,b,cin);
  input [1:0]a,b;
  input cin;
  output [1:0]sum;
  output cout;
  
  wire [1:0]p,g,c;
  
  assign p=a|b;
  assign g=a&b;
  assign c[0]=g[0]|(p[0]&cin);
  assign c[1]=g[1]|(p[1]&g[0])|(p[1]&p[0]&cin);
  assign {cout,sum}=a^b^{c,cin};
  
endmodule

module add4(cout,sum,a,b,cin);
  input [3:0]a,b;
  input cin;
  output [3:0]sum;
  output cout;
  
  wire [3:0]p,g,c;
  
  assign p=a|b;
  assign g=a&b;
  assign c[0]=g[0]|(p[0]&cin);
  assign c[1]=g[1]|(p[1]&g[0])|(p[1]&p[0]&cin);
  assign c[2]=g[2]|(p[2]&g[1])|(p[2]&p[1]&g[0])|(p[2]&p[1]&p[0]&cin);
  assign c[3]=g[3]|(p[3]&g[2])|(p[3]&p[2]&g[1])|(p[3]&p[2]&p[1]&g[0])|(p[3]&p[2]&p[1]&p[0]&cin);
  assign {cout,sum}=a^b^{c,cin};
  
endmodule

module add8(cout,sum,a,b,cin);
  input [7:0]a,b;
  input cin;
  output [7:0]sum;
  output cout;
  
  wire [7:0]p,g,c;
  
  assign p=a|b;
  assign g=a&b;
  assign c[0]=g[0]|(p[0]&cin);
  assign c[1]=g[1]|(p[1]&g[0])|(p[1]&p[0]&cin);
  assign c[2]=g[2]|(p[2]&g[1])|(p[2]&p[1]&g[0])|(p[2]&p[1]&p[0]&cin);
  assign c[3]=g[3]|(p[3]&g[2])|(p[3]&p[2]&g[1])|(p[3]&p[2]&p[1]&g[0])|(p[3]&p[2]&p[1]&p[0]&cin);
  assign c[4]=g[4]|(p[4]&g[3])|(p[4]&p[3]&g[2])|(p[4]&p[3]&p[2]&g[1])|(p[4]&p[3]&p[2]&p[1]&g[0])|
  (p[4]&p[3]&p[2]&p[1]&p[0]&cin);
  assign c[5]=g[5]|(p[5]&g[4])|(p[5]&p[4]&g[3])|(p[5]&p[4]&p[3]&g[2])|(p[5]&p[4]&p[3]&p[2]&g[1])|
  (p[5]&p[4]&p[3]&p[2]&p[1]&g[0])|(p[5]&p[4]&p[3]&p[2]&p[1]&p[0]&cin);
  assign c[6]=g[6]|(p[6]&g[5])|(p[6]&p[5]&g[4])|(p[6]&p[5]&p[4]&g[3])|(p[6]&p[5]&p[4]&p[3]&g[2])|
  (p[6]&p[5]&p[4]&p[3]&p[2]&g[1])|(p[6]&p[5]&p[4]&p[3]&p[2]&p[1]&g[0])|(p[6]&p[5]&p[4]&p[3]&p[2]&p[1]&p[0]&cin);
  assign c[7]=g[7]|(p[7]&g[6])|(p[7]&p[6]&g[5])|(p[7]&p[6]&p[5]&g[4])|(p[7]&p[6]&p[5]&p[4]&g[3])|
  (p[7]&p[6]&p[5]&p[4]&p[3]&g[2])|(p[7]&p[6]&p[5]&p[4]&p[3]&p[2]&g[1])|(p[7]&p[6]&p[5]&p[4]&p[3]&p[2]&p[1]&g[0])|
  (p[7]&p[6]&p[5]&p[4]&p[3]&p[2]&p[1]&p[0]&cin);
  assign {cout,sum}=a^b^{c,cin};
  
endmodule
  