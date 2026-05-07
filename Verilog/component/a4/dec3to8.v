module dec3to8(input a, input b, input c, output wire [7:0] out, input en);
	assign out = en << {a, b, c};
endmodule
