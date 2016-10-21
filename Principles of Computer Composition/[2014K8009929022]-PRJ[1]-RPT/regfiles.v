module regfiles(clk,rst,wen,raddr1,raddr2,waddr,wdata,rdata1,rdata2);
  input clk,rst,wen;
  input [31:0]wdata;
  input [4:0]raddr1,raddr2,waddr;
  output [31:0]rdata1,rdata2;
  wire clk;
  reg [31:0]r[31:0];
  
  always @(posedge clk)
  begin
    if(wen==1 && waddr!=5'b0)
      r[waddr]<=wdata;
    else
      r[waddr]<=r[waddr];
  end
  
  assign rdata1= (raddr1==5'b0)? 32'b0:r[raddr1];
  //assign rdata1= r[raddr1];
  assign rdata2= (raddr2==5'b0)? 32'b0:r[raddr2];
  
endmodule