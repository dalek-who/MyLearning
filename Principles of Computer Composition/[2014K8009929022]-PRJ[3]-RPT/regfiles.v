module regfiles(clk,rst,wen,raddr1,raddr2,waddr,wdata,rdata1,rdata2);
  input clk,rst,wen;
  input [31:0]wdata;
  input [4:0]raddr1,raddr2,waddr;
  output [31:0]rdata1,rdata2;
  wire clk;
  reg [31:0]r[31:0];
  
  always @(posedge clk or posedge rst)
  begin
    if(rst)
      begin
        r[0]=32'b0;r[1]=32'b0;r[2]=32'b0;r[3]=32'b0;
        r[4]=32'b0;r[5]=32'b0;r[6]=32'b0;r[7]=32'b0;
        r[8]=32'b0;r[9]=32'b0;r[10]=32'b0;r[11]=32'b0;
        r[12]=32'b0;r[13]=32'b0;r[14]=32'b0;r[15]=32'b0;
        r[16]=32'b0;r[17]=32'b0;r[18]=32'b0;r[19]=32'b0;
        r[20]=32'b0;r[21]=32'b0;r[22]=32'b0;r[23]=32'b0;
        r[24]=32'b0;r[25]=32'b0;r[26]=32'b0;r[27]=32'b0;
        r[28]=32'b0;r[29]=32'b0;r[30]=32'b0;r[31]=32'b0;
      end
    else if(wen==1 && waddr!=5'b0)
      r[waddr]<=wdata;
 	  else
      r[waddr]<=r[waddr];
  end
  
  assign rdata1= (raddr1==5'b0)? 32'b0:r[raddr1];
  //assign rdata1= r[raddr1];
  assign rdata2= (raddr2==5'b0)? 32'b0:r[raddr2];
  
endmodule