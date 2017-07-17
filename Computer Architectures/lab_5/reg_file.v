module regfiles(wdata,raddr1,raddr2,waddr,clk,wen,rdata1,rdata2,rst,rf_0,rf_1, rf_2, rf_3, rf_4, rf_5, rf_6, rf_7, rf_8, rf_9, rf_10, rf_11, rf_12, rf_13, rf_14, rf_15, rf_16, rf_17, rf_18, rf_19, rf_20, rf_21, rf_22, rf_23, rf_24, rf_25, rf_26, rf_27, rf_28, rf_29, rf_30, rf_31);
	input [31:0]wdata;
	input [4:0]raddr1,raddr2,waddr;
	input wen,clk,rst;
	output [31:0]rdata1,rdata2;

	 output [31:0]rf_0;
    output [31:0]rf_1;
    output [31:0]rf_2;
    output [31:0]rf_3;
    output [31:0]rf_4;
    output [31:0]rf_5;
    output [31:0]rf_6;
    output [31:0]rf_7;
    output [31:0]rf_8;
    output [31:0]rf_9;
    output [31:0]rf_10;
    output [31:0]rf_11;
    output [31:0]rf_12;
    output [31:0]rf_13;
    output [31:0]rf_14;
    output [31:0]rf_15;
    output [31:0]rf_16;
    output [31:0]rf_17;
    output [31:0]rf_18;
    output [31:0]rf_19;
    output [31:0]rf_20;
    output [31:0]rf_21;
    output [31:0]rf_22;
    output [31:0]rf_23;
    output [31:0]rf_24;
    output [31:0]rf_25;
    output [31:0]rf_26;
    output [31:0]rf_27;
    output [31:0]rf_28;
    output [31:0]rf_29;
    output [31:0]rf_30;
    output [31:0]rf_31;



	reg [31:0]dffreg[31:0];
	integer i;
	assign rdata1=dffreg[raddr1];
	assign rdata2=dffreg[raddr2];
	always @(posedge clk or posedge rst) begin
		if (rst) begin
			for(i=0;i<32;i=i+1)
				dffreg[i]<=32'b0;
		end
		else if (wen==1&&waddr!=5'b0) begin
			dffreg[waddr] <= wdata;
		end
	end


	assign rf_0 = 32'd0;
    assign rf_1 = dffreg[1];
    assign rf_2 = dffreg[2];
    assign rf_3 = dffreg[3];
    assign rf_4 = dffreg[4];
    assign rf_5 = dffreg[5];
    assign rf_6 = dffreg[6];
    assign rf_7 = dffreg[7];
    assign rf_8 = dffreg[8];
    assign rf_9 = dffreg[9];
    assign rf_10 = dffreg[10];
    assign rf_11 = dffreg[11];
    assign rf_12 = dffreg[12];
    assign rf_13 = dffreg[13];
    assign rf_14 = dffreg[14];
    assign rf_15 = dffreg[15];
    assign rf_16 = dffreg[16];
    assign rf_17 = dffreg[17];
    assign rf_18 = dffreg[18];
    assign rf_19 = dffreg[19];
    assign rf_20 = dffreg[20];
    assign rf_21 = dffreg[21];
    assign rf_22 = dffreg[22];
    assign rf_23 = dffreg[23];
    assign rf_24 = dffreg[24];
    assign rf_25 = dffreg[25];
    assign rf_26 = dffreg[26];
    assign rf_27 = dffreg[27];
    assign rf_28 = dffreg[28];
    assign rf_29 = dffreg[29];
    assign rf_30 = dffreg[30];
    assign rf_31 = dffreg[31];
    
endmodule