`include "ls132r_define.h"
module ls132r_decoder_2_4(enable,in,out);

input        enable;
input  [1:0] in;     
output [3:0] out; 

assign out[3]=( in[1])&( in[0])&enable;
assign out[2]=( in[1])&(~in[0])&enable;
assign out[1]=(~in[1])&( in[0])&enable;
assign out[0]=(~in[1])&(~in[0])&enable;

endmodule //ls132r_decoder_2_4




module ls132r_decoder_3_8(in,out);

input [2:0] in;     
output [7:0] out; 

wire [2:0]in;
wire [7:0] out;

assign out[7]=( in[2])&( in[1])&( in[0]);
assign out[6]=( in[2])&( in[1])&(~in[0]);
assign out[5]=( in[2])&(~in[1])&( in[0]);
assign out[4]=( in[2])&(~in[1])&(~in[0]);
assign out[3]=(~in[2])&( in[1])&( in[0]);
assign out[2]=(~in[2])&( in[1])&(~in[0]);
assign out[1]=(~in[2])&(~in[1])&( in[0]);
assign out[0]=(~in[2])&(~in[1])&(~in[0]);

endmodule //ls132r_decoder_3_8





module ls132r_decoder_4_16(enable,in,out);

input enable;                   
input  [3:0] in;
output [15:0] out; 

wire enable;
wire [3:0] in;
wire [15:0] out;
wire [3:0] high_d;
wire [3:0] low_d;

assign high_d[3]=( in[3])&( in[2])&enable;
assign high_d[2]=( in[3])&(~in[2])&enable;
assign high_d[1]=(~in[3])&( in[2])&enable;
assign high_d[0]=(~in[3])&(~in[2])&enable;

assign low_d[3]=( in[1])&( in[0]);    
assign low_d[2]=( in[1])&(~in[0]);
assign low_d[1]=(~in[1])&( in[0]);
assign low_d[0]=(~in[1])&(~in[0]);

assign out[15]=high_d[3]&low_d[3];
assign out[14]=high_d[3]&low_d[2];
assign out[13]=high_d[3]&low_d[1];
assign out[12]=high_d[3]&low_d[0];
assign out[11]=high_d[2]&low_d[3];
assign out[10]=high_d[2]&low_d[2];
assign out[ 9]=high_d[2]&low_d[1];
assign out[ 8]=high_d[2]&low_d[0];    
assign out[ 7]=high_d[1]&low_d[3];
assign out[ 6]=high_d[1]&low_d[2];
assign out[ 5]=high_d[1]&low_d[1];
assign out[ 4]=high_d[1]&low_d[0];
assign out[ 3]=high_d[0]&low_d[3];
assign out[ 2]=high_d[0]&low_d[2];
assign out[ 1]=high_d[0]&low_d[1];
assign out[ 0]=high_d[0]&low_d[0];    

endmodule //ls132r_decoder_4_16






module ls132r_decoder_5_32(in,out);
    
input [4:0] in;
output [31:0] out; 

wire [4:0]in;
wire [31:0]out;

wire [3:0] high_d;
wire [7:0] low_d;

assign high_d[3]=( in[4])&( in[3]);
assign high_d[2]=( in[4])&(~in[3]);
assign high_d[1]=(~in[4])&( in[3]);
assign high_d[0]=(~in[4])&(~in[3]);

assign low_d[7]=( in[2])&( in[1])&( in[0]);
assign low_d[6]=( in[2])&( in[1])&(~in[0]);
assign low_d[5]=( in[2])&(~in[1])&( in[0]);
assign low_d[4]=( in[2])&(~in[1])&(~in[0]);
assign low_d[3]=(~in[2])&( in[1])&( in[0]);
assign low_d[2]=(~in[2])&( in[1])&(~in[0]);
assign low_d[1]=(~in[2])&(~in[1])&( in[0]);
assign low_d[0]=(~in[2])&(~in[1])&(~in[0]);

assign out[31]=high_d[3]&low_d[7];
assign out[30]=high_d[3]&low_d[6];
assign out[29]=high_d[3]&low_d[5];
assign out[28]=high_d[3]&low_d[4];
assign out[27]=high_d[3]&low_d[3];
assign out[26]=high_d[3]&low_d[2];
assign out[25]=high_d[3]&low_d[1];
assign out[24]=high_d[3]&low_d[0];    
assign out[23]=high_d[2]&low_d[7];
assign out[22]=high_d[2]&low_d[6];
assign out[21]=high_d[2]&low_d[5];
assign out[20]=high_d[2]&low_d[4];
assign out[19]=high_d[2]&low_d[3];
assign out[18]=high_d[2]&low_d[2];
assign out[17]=high_d[2]&low_d[1];
assign out[16]=high_d[2]&low_d[0];    
assign out[15]=high_d[1]&low_d[7];
assign out[14]=high_d[1]&low_d[6];
assign out[13]=high_d[1]&low_d[5];
assign out[12]=high_d[1]&low_d[4];
assign out[11]=high_d[1]&low_d[3];
assign out[10]=high_d[1]&low_d[2];
assign out[ 9]=high_d[1]&low_d[1];
assign out[ 8]=high_d[1]&low_d[0];    
assign out[ 7]=high_d[0]&low_d[7];
assign out[ 6]=high_d[0]&low_d[6];
assign out[ 5]=high_d[0]&low_d[5];
assign out[ 4]=high_d[0]&low_d[4];
assign out[ 3]=high_d[0]&low_d[3];
assign out[ 2]=high_d[0]&low_d[2];
assign out[ 1]=high_d[0]&low_d[1];
assign out[ 0]=high_d[0]&low_d[0];    

endmodule //ls132r_decoder_5_32





module ls132r_decoder_6_64(in,out);

input  [ 5:0] in;
output [63:0] out; 

wire [5:0]in;
wire [63:0] out;
wire [7:0] high_d;
wire [7:0] low_d;

assign high_d[7]=( in[5])&( in[4])&( in[3]);
assign high_d[6]=( in[5])&( in[4])&(~in[3]);
assign high_d[5]=( in[5])&(~in[4])&( in[3]);
assign high_d[4]=( in[5])&(~in[4])&(~in[3]);
assign high_d[3]=(~in[5])&( in[4])&( in[3]);
assign high_d[2]=(~in[5])&( in[4])&(~in[3]);
assign high_d[1]=(~in[5])&(~in[4])&( in[3]);
assign high_d[0]=(~in[5])&(~in[4])&(~in[3]);

assign low_d[7]=( in[2])&( in[1])&( in[0]);
assign low_d[6]=( in[2])&( in[1])&(~in[0]);
assign low_d[5]=( in[2])&(~in[1])&( in[0]);
assign low_d[4]=( in[2])&(~in[1])&(~in[0]);
assign low_d[3]=(~in[2])&( in[1])&( in[0]);
assign low_d[2]=(~in[2])&( in[1])&(~in[0]);
assign low_d[1]=(~in[2])&(~in[1])&( in[0]);
assign low_d[0]=(~in[2])&(~in[1])&(~in[0]);

assign out[63]=high_d[7]&low_d[7];
assign out[62]=high_d[7]&low_d[6];
assign out[61]=high_d[7]&low_d[5];
assign out[60]=high_d[7]&low_d[4];
assign out[59]=high_d[7]&low_d[3];
assign out[58]=high_d[7]&low_d[2];
assign out[57]=high_d[7]&low_d[1];
assign out[56]=high_d[7]&low_d[0];    
assign out[55]=high_d[6]&low_d[7];
assign out[54]=high_d[6]&low_d[6];
assign out[53]=high_d[6]&low_d[5];
assign out[52]=high_d[6]&low_d[4];
assign out[51]=high_d[6]&low_d[3];
assign out[50]=high_d[6]&low_d[2];
assign out[49]=high_d[6]&low_d[1];
assign out[48]=high_d[6]&low_d[0];    
assign out[47]=high_d[5]&low_d[7];
assign out[46]=high_d[5]&low_d[6];
assign out[45]=high_d[5]&low_d[5];
assign out[44]=high_d[5]&low_d[4];
assign out[43]=high_d[5]&low_d[3];
assign out[42]=high_d[5]&low_d[2];
assign out[41]=high_d[5]&low_d[1];
assign out[40]=high_d[5]&low_d[0];    
assign out[39]=high_d[4]&low_d[7];
assign out[38]=high_d[4]&low_d[6];
assign out[37]=high_d[4]&low_d[5];
assign out[36]=high_d[4]&low_d[4];
assign out[35]=high_d[4]&low_d[3];
assign out[34]=high_d[4]&low_d[2];
assign out[33]=high_d[4]&low_d[1];
assign out[32]=high_d[4]&low_d[0];    
assign out[31]=high_d[3]&low_d[7];
assign out[30]=high_d[3]&low_d[6];
assign out[29]=high_d[3]&low_d[5];
assign out[28]=high_d[3]&low_d[4];
assign out[27]=high_d[3]&low_d[3];
assign out[26]=high_d[3]&low_d[2];
assign out[25]=high_d[3]&low_d[1];
assign out[24]=high_d[3]&low_d[0];    
assign out[23]=high_d[2]&low_d[7];
assign out[22]=high_d[2]&low_d[6];
assign out[21]=high_d[2]&low_d[5];
assign out[20]=high_d[2]&low_d[4];
assign out[19]=high_d[2]&low_d[3];
assign out[18]=high_d[2]&low_d[2];
assign out[17]=high_d[2]&low_d[1];
assign out[16]=high_d[2]&low_d[0];    
assign out[15]=high_d[1]&low_d[7];
assign out[14]=high_d[1]&low_d[6];
assign out[13]=high_d[1]&low_d[5];
assign out[12]=high_d[1]&low_d[4];
assign out[11]=high_d[1]&low_d[3];
assign out[10]=high_d[1]&low_d[2];
assign out[ 9]=high_d[1]&low_d[1];
assign out[ 8]=high_d[1]&low_d[0];    
assign out[ 7]=high_d[0]&low_d[7];
assign out[ 6]=high_d[0]&low_d[6];
assign out[ 5]=high_d[0]&low_d[5];
assign out[ 4]=high_d[0]&low_d[4];
assign out[ 3]=high_d[0]&low_d[3];
assign out[ 2]=high_d[0]&low_d[2];
assign out[ 1]=high_d[0]&low_d[1];
assign out[ 0]=high_d[0]&low_d[0];    

endmodule //ls132r_decoder_6_64

module ls132r_first_one_32_5(in,out,nonzero);
input  [31:0] in;
output [4:0] out;
output nonzero;

wire [2:0] a3,a2,a1,a0;
wire [3:0] nz;
wire zero;

ls132r_first_one_8_3 first_one3(.in(in[31:24]),.out(a3),.nonzero(nz[3]));
ls132r_first_one_8_3 first_one2(.in(in[23:16]),.out(a2),.nonzero(nz[2]));
ls132r_first_one_8_3 first_one1(.in(in[15: 8]),.out(a1),.nonzero(nz[1]));
ls132r_first_one_8_3 first_one0(.in(in[ 7: 0]),.out(a0),.nonzero(nz[0]));

ls132r_first_one_4_2 first_one4(.in(nz),.out(out[4:3]),.nonzero(nonzero));

assign out[2:0]= a0 |
                (a1 & {3{~nz[0]}})    |
                (a2 & {3{~|nz[1:0]}}) |
                (a3 & {3{~|nz[2:0]}});

endmodule

module ls132r_first_one_16_4(in,out,nonzero);
input  [15:0] in;
output [3:0] out;
output nonzero;
 
wire [1:0] a3,a2,a1,a0;
wire [3:0] nz;
wire zero;
 
ls132r_first_one_4_2 first_one_4_2_3(.in(in[15:12]),.out(a3),.nonzero(nz[3]));
ls132r_first_one_4_2 first_one_4_2_2(.in(in[11: 8]),.out(a2),.nonzero(nz[2]));
ls132r_first_one_4_2 first_one_4_2_1(.in(in[ 7: 4]),.out(a1),.nonzero(nz[1]));
ls132r_first_one_4_2 first_one_4_2_0(.in(in[ 3: 0]),.out(a0),.nonzero(nz[0]));

ls132r_first_one_4_2 first_one4(.in(nz),.out(out[3:2]),.nonzero(nonzero));

assign out[1:0]= a0 |
                (a1 & {2{~nz[0]}}) |
                (a2 & {2{~|nz[1:0]}}) |
                (a3 & {2{~|nz[2:0]}});
 
endmodule


module ls132r_first_one_8_3(in,out,nonzero);
input  [7:0] in;
output [2:0] out;
output nonzero;
 
assign out[2]=(~(|in[3:0]))&(|in[7:4]);
assign out[1]=((~in[0]) & (~in[1]) & (~in[4]) & (~in[5]) & (in[6] | in[7])) |
              ((~in[0]) & (~in[1]) & (in[2] | in[3]));
assign out[0]=((~in[0]) & (~in[2]) & (~in[4]) & (~in[6]) & in[7])|
              ((~in[0]) & (~in[2]) & (~in[4]) & in[5])|
              ((~in[0]) & (~in[2]) & in[3])|
              ((~in[0]) & in[1]);
assign nonzero=|in[7:0];
endmodule

module ls132r_first_one_4_2(in,out,nonzero);
input  [3:0] in;
output [1:0] out;
output nonzero;
 
assign out[1] = (~in[0])&(~in[1]) & (in[2] | in[3]);
assign out[0] = ((~in[0])&( in[1])) | ((~in[0])&(~in[2])&( in[3]));
assign nonzero   = |in[3:0];
endmodule
 

module ls132r_change_order_64(in,out);
input  [63:0] in;
output [63:0] out;
                                                                                                                              
assign out = {in[ 0],in[ 1],in[ 2],in[ 3],in[ 4],in[ 5],in[ 6],in[ 7],in[ 8],in[ 9],
              in[10],in[11],in[12],in[13],in[14],in[15],in[16],in[17],in[18],in[19],
              in[20],in[21],in[22],in[23],in[24],in[25],in[26],in[27],in[28],in[29],
              in[30],in[31],in[32],in[33],in[34],in[35],in[36],in[37],in[38],in[39],
              in[40],in[41],in[42],in[43],in[44],in[45],in[46],in[47],in[48],in[49],
              in[50],in[51],in[52],in[53],in[54],in[55],in[56],in[57],in[58],in[59],
              in[60],in[61],in[62],in[63]};
endmodule
 
module ls132r_first_one_64_6(in,out,nonzero);
input  [63:0] in;
output [5:0] out;
output nonzero;

wire [3:0] a3,a2,a1,a0;
wire [3:0] nz;
wire zero;

ls132r_first_one_16_4 first_one_16_4_3(.in(in[63:48]),.out(a3),.nonzero(nz[3]));
ls132r_first_one_16_4 first_one_16_4_2(.in(in[47:32]),.out(a2),.nonzero(nz[2]));
ls132r_first_one_16_4 first_one_16_4_1(.in(in[31:16]),.out(a1),.nonzero(nz[1]));
ls132r_first_one_16_4 first_one_16_4_0(.in(in[15: 0]),.out(a0),.nonzero(nz[0]));

ls132r_first_one_4_2  first_one_4_2_0(.in(nz),.out(out[5:4]),.nonzero(nonzero));

assign out[3:0]= a0 |
                (a1 & {4{~nz[0]}}) |
                (a2 & {4{~|nz[1:0]}}) |
                (a3 & {4{~|nz[2:0]}});
endmodule

module CSA4_2(in,cin,cout,s,c);
input[3:0]      in;
input           cin;
output          cout;
output          s,c;

wire    temp;

CSA3_2  counter0( .in(in[2:0]),.s(temp),.c(cout) );
CSA3_2  counter1( .in({in[3],temp,cin}),.s(s),.c(c) );

endmodule

module CSA3_2(in,s,c);
input[2:0]      in;
output          s,c;

assign  s = in[0]^in[1]^in[2];
assign  c = (in[0]&in[1]) | (in[0]&in[2]) | (in[1]&in[2]);

endmodule

module ls132r_ejtag_rstgen(tck, trst_in, trst_out, testmode);
input       tck; 
input       trst_in;
input       testmode;
output      trst_out;

reg         rff, rff1; 

always @ (posedge tck or negedge trst_in)
  begin
    if(!trst_in) {rff1, rff} <= 2'b0;
    else         {rff1, rff} <= {rff, 1'b1}; 
  end

assign trst_out = testmode ? trst_in : rff1; 

endmodule
