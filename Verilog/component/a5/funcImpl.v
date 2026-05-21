`include "a4/dec3to8.v"

module funcImpl(input wire [2:0] I, output wire F1, output wire F2, output wire F3);
	wire [7:0] y;
	dec3to8 d1(I[2], I[1], I[0], y, 1'b1);

	assign F1 = ~(~y[2] & ~y[4] & ~y[7]);
	assign F2 = ~(~y[0] & ~y[3]);
	assign F3 = ~(~y[0] & ~y[2] & ~y[3] & ~y[4] & ~y[7]);
endmodule
