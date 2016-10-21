`include "parameters.vh"

module queue
(
	input [(`CACHE_SET_ASSOCIATIVITY)-1:0]valid_vec_in,
	input [(`CACHE_SET_ASSOCIATIVITY)-1:0]history_vec_in,
	input [(`CACHE_SET_ASSOCIATIVITY)-1:0]ways_select_in,
	output reg [(`CACHE_SET_ASSOCIATIVITY)-1:0]new_ways,
	output reg [1:0]solution
);

	wire [(`CACHE_SET_ASSOCIATIVITY)-1:0]mask1;
	wire [(`CACHE_SET_ASSOCIATIVITY)-1:0]mask2;
	wire [(`CACHE_SET_ASSOCIATIVITY)-1:0]new_ways_1;
	wire [(`CACHE_SET_ASSOCIATIVITY)-1:0]new_ways_2;
	
	generate
	  genvar i;
		for(i=0;i<(`CACHE_SET_ASSOCIATIVITY);i=i+1)
		begin
			if(i==0)
			begin
				assign new_ways_1[i]=~valid_vec_in[i];
				assign mask1[i]=valid_vec_in[i];
				assign new_ways_2[i]=~history_vec_in[i];
				assign mask2[i]=history_vec_in[i];
			end
			else
			begin
				assign new_ways_1[i]=(~valid_vec_in[i])&&mask1[i-1];
				assign mask1[i]=mask1[i-1]&&(~new_ways_1[i]);
				assign new_ways_2[i]=(~history_vec_in[i])&&mask2[i-1];
				assign mask2[i]=mask2[i-1]&&(~new_ways_2[i]);
			end
		end
	endgenerate

	always@(*)
	begin
		if(|(valid_vec_in&ways_select_in))
		begin
			solution=2'b00;
			new_ways=valid_vec_in&ways_select_in;
		end
		else if((&(valid_vec_in))==0)
		begin
			solution=2'b01;
			new_ways=new_ways_1;
		end
		else if((&(history_vec_in))==0)
		begin
			solution=2'b10;
			new_ways=new_ways_2;
		end
		else
		begin
			solution=2'b11;
			new_ways=1;
		end
	end

endmodule

module RAM
#(
	parameter SINGLE_ELEMENT_SIZE_IN_BITS = 2,
	parameter NUMBER_SETS = 64,
	parameter SET_PTR_WIDTH_IN_BITS = 6
)
(
	input reset_in,
	input clk_in,

	input access_en_in,
	input write_en_in,
	input [SET_PTR_WIDTH_IN_BITS-1:0]access_set_addr_in,
	input [SINGLE_ELEMENT_SIZE_IN_BITS-1:0]write_element_in,
	output reg [SINGLE_ELEMENT_SIZE_IN_BITS-1:0]read_element_out
);

	reg [SINGLE_ELEMENT_SIZE_IN_BITS-1:0]ram[NUMBER_SETS-1:0];
	
	generate
	  genvar i;
		for(i=0;i<NUMBER_SETS;i=i+1)
		begin
			always@(posedge clk_in or posedge reset_in)
			begin
				if(reset_in)
				begin
					ram[i]<=0;
				end
				else if(access_en_in&&write_en_in&&i==access_set_addr_in)
				begin
					ram[i]<=write_element_in;
				end
			end
		end		
	endgenerate

	always@(posedge clk_in or posedge reset_in)
	begin
		if (reset_in)
		begin
			read_element_out<=0;
		end
		else if(access_en_in)
		begin
			read_element_out<=ram[access_set_addr_in];
		end
		else
		begin
		  read_element_out<=0;
		 end
	end

endmodule

