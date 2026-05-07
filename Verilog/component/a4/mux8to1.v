`include "a4/mux4to1.v"

module mux8to1(input wire [7:0] I, input wire [2:0] sel, output wire y);
	wire y1, y2;

	mux4to1 m1(I[3:0], sel[1:0], y1);
	mux4to1 m2(I[7:4], sel[1:0], y2);

	assign y = (y1 & ~sel[2]) | (y2 & sel[2]);
endmodule
