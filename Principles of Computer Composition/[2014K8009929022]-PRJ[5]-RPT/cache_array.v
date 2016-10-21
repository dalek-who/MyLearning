`include "parameters.vh"

module cache_array
#(
	parameter SINGLE_ELEMENT_SIZE_IN_BITS = 2,
	parameter NUMBER_WAYS = 8,
	parameter NUMBER_SETS = 64,
	parameter SET_PTR_WIDTH_IN_BITS = 6
)
(
	input reset_in,
	input clk_in,

	input access_en_in,
	input write_en_in,
	input [SET_PTR_WIDTH_IN_BITS-1:0]access_set_addr_in,
	input [NUMBER_WAYS-1:0]ways_select_in,
	input [SINGLE_ELEMENT_SIZE_IN_BITS-1:0]compare_in,
	output reg [NUMBER_WAYS-1:0]ways_select_out,
	input [SINGLE_ELEMENT_SIZE_IN_BITS-1:0]write_element_in,
	output [SINGLE_ELEMENT_SIZE_IN_BITS-1:0]read_element_out,
	output [SINGLE_ELEMENT_SIZE_IN_BITS*NUMBER_WAYS-1:0]read_full_elements_out
);

	wire [SINGLE_ELEMENT_SIZE_IN_BITS-1:0]read_out[NUMBER_WAYS-1:0];
	wire [SINGLE_ELEMENT_SIZE_IN_BITS-1:0]midor[NUMBER_WAYS-2:0];

	generate
	  genvar i;
		for(i=0;i<NUMBER_WAYS;i=i+1)
		begin : ram_array
			RAM
			#(
				.SINGLE_ELEMENT_SIZE_IN_BITS(SINGLE_ELEMENT_SIZE_IN_BITS),
				.NUMBER_SETS(NUMBER_SETS),
				.SET_PTR_WIDTH_IN_BITS(SET_PTR_WIDTH_IN_BITS)
			)
			ram
			(
				.reset_in(reset_in),
				.clk_in(clk_in),

				.access_en_in(access_en_in&&ways_select_in[i]),
				.write_en_in(write_en_in),
				.access_set_addr_in(access_set_addr_in),
				.write_element_in(write_element_in),
				.read_element_out(read_out[i])
			);
		end
	endgenerate

	generate
	  genvar j;
		for(j=0;j<NUMBER_WAYS;j=j+1)
		begin
			assign read_full_elements_out[j*SINGLE_ELEMENT_SIZE_IN_BITS+SINGLE_ELEMENT_SIZE_IN_BITS-1:j*SINGLE_ELEMENT_SIZE_IN_BITS]=read_out[j];
		end
	endgenerate

	generate
	  genvar k;
		for(k=0;k<NUMBER_WAYS;k=k+1)
		begin
			always@(*)
			begin
				if(compare_in==read_out[k])
					ways_select_out[k]=1;
				else
					ways_select_out[k]=0;
			end
		end
	endgenerate

	generate
	  genvar l;
		for(l=1;l<NUMBER_WAYS;l=l+1)
		begin
			if(l==1)
				assign midor[l-1]=read_out[0]|read_out[1];
			else
				assign midor[l-1]=midor[l-2]|read_out[l];
		end
	endgenerate
	
	assign read_element_out=midor[NUMBER_WAYS-2];

endmodule