module dec3to8(input a, input b, input c, output wire [7:0] out, input en);
	assign out[0] = ~a & ~b & ~c;
	assign out[1] = ~a & ~b & c;
	assign out[2] = ~a & b & ~c;
	assign out[3] = ~a & b & c;
	assign out[4] = a & ~b & ~c;
	assign out[5] = a & ~b & c;
	assign out[6] = a & b & ~c;
	assign out[7] = a & b & c;
endmodule
