/*
branch_type:
rev: 0      1
5:  beq -- bne
4:  blt -- bge
3:  ble -- bgt
2:  rev
1:  j
0:  jr
*/
module branch_check(
	input [5:0]branch_type,
	input [31:0]opa,
	input [31:0]opb,
	output reg br_taken,
	output j_taken,
	output jr_taken
);
	wire b,j,jr;
	assign jr_taken = branch_type[0];
	assign j_taken = branch_type[1];
	assign rev = branch_type[2];
	assign beq = branch_type[5];
	assign blt = branch_type[4];
	assign ble = branch_type[3];

//	reg br_taken;
	always @(*)begin
		if(beq)
			br_taken=(opa==opb);
		else if(blt)
			br_taken=opa[31];
		else if(ble)
			br_taken=(opa[31])|~(|opa[30:0]);
		else
			br_taken=0;
		if(rev)
			br_taken=~br_taken;
	end

endmodule