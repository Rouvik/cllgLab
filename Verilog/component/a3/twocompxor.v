module twocompxor(input wire [3:0] A, output wire [3:0] y);
	assign y = (A ^ 4'b1111) + 1;
endmodule
