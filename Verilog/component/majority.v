module majority(input wire [2:0] A, output y);
	assign y = (A[2] & A[1]) | (A[0] & (A[2] ^ A[1]));
endmodule

