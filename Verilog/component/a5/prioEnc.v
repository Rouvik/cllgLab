module prioEnc(input wire [3:0] I, output wire [1:0] y, output wire gs);
	assign gs = I == 0 ? 0 : 1;

	assign y[0] = I[3] | (~I[2] & I[1]);
	assign y[1] = I[3] | I[2];
endmodule
