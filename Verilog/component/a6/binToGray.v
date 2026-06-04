module binToGray(input [3:0] I, output [3:0] y);
	assign y = I ^ (I >> 1);
endmodule
