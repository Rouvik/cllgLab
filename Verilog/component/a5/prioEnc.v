module prioEnc(input wire [3:0] I, output wire [2:0] y, output wire gs);
	assign gs = I == 0 ? 0 : 1;

	
endmodule
