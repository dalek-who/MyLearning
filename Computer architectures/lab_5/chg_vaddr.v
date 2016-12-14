module chg_vaddr(
	input [31:0]vaddr,
	output [31:0]paddr
);
	assign paddr={3'd0,vaddr[28:0]};
endmodule