module mux_4(in0,in1,in2,in3,mout,control);
	input [31:0]in0,in1,in2,in3;
	input [1:0]control;
	output [31:0]mout;
	reg [31:0]mout;
	always @(*) begin
		case(control)
			2'd0:mout=in0;
			2'd1:mout=in1;
			2'd2:mout=in2;
			2'd3:mout=in3;
			default:mout=32'd0;
		endcase
	end
endmodule