module mux4to1(input wire [3:0] I, input wire[1:0] sel, output wire y);
	assign y = (I[0] & ~sel[1] & ~sel[0]) |
		   (I[1] & ~sel[1] & sel[0]) |
		   (I[2] & sel[1] & ~sel[0]) |
		   (I[3] & sel[1] & sel[0]);
endmodule
