module dec3to8(input a, input b, input c, output wire [7:0] out, input en);
	assign out[0] = en & ~a & ~b & ~c;
	assign out[1] = en & ~a & ~b & c;
	assign out[2] = en & ~a & b & ~c;
	assign out[3] = en & ~a & b & c;
	assign out[4] = en & a & ~b & ~c;
	assign out[5] = en & a & ~b & c;
	assign out[6] = en & a & b & ~c;
	assign out[7] = en & a & b & c;
endmodule
