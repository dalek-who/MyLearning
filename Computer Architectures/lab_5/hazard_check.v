module hazard_check(
	input [4:0]wb_dest,
	input  wb_dest_rdy,
	input [4:0]mem_dest,
	input mem_dest_rdy,
	input [4:0]ex_dest,
	input ex_dest_rdy,
	input [4:0]id_rs,
	input rs_need,
	input [4:0]id_rt,
	input rt_need,
	output hazard_free,
	output reg [1:0]vsrc1_sel,
	output reg [1:0]vsrc2_sel
);
	wire wb_rs,wb_rt,mem_rs,mem_rt,ex_rs,ex_rt;
	assign wb_rs = rs_need & (|id_rs) & (id_rs==wb_dest);
	assign wb_rt = rt_need & (|id_rt) & (id_rt==wb_dest);
	assign mem_rs = rs_need & (|id_rs) & (id_rs==mem_dest);
	assign mem_rt = rt_need & (|id_rt) & (id_rt==mem_dest);
	assign ex_rs = rs_need & (|id_rs) & (id_rs==ex_dest);
	assign ex_rt = rt_need & (|id_rt) & (id_rt==ex_dest);

	reg hazard_free1,hazard_free2;
	assign hazard_free = hazard_free1 & hazard_free2;
	//reg [1:0]vsrc1_sel,vsrc2_sel;
	always@(*)begin
		if(ex_rs)begin
			vsrc1_sel=2'd1;
			hazard_free1=ex_dest_rdy;
		end
		else if(mem_rs) begin
			vsrc1_sel=2'd2;
			hazard_free1=mem_dest_rdy;
		end
		else if(wb_rs) begin
			vsrc1_sel=2'd3;
			hazard_free1=wb_dest_rdy;
		end
		else begin
			vsrc1_sel=2'd0;
			hazard_free1=1;
		end
	end
	always@(*)begin
		if(ex_rt)begin
			vsrc2_sel=2'd1;
			hazard_free2=ex_dest_rdy;
		end
		else if(mem_rt) begin
			vsrc2_sel=2'd2;
			hazard_free2=mem_dest_rdy;
		end
		else if(wb_rt) begin
			vsrc2_sel=2'd3;
			hazard_free2=wb_dest_rdy;
		end
		else begin
			vsrc2_sel=2'd0;
			hazard_free2=1;
		end
	end
endmodule