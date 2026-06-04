module binToBCD(input wire [3:0] I, output wire [4:0] y);
	assign y = I > 9 ? I + 6 : I;
endmodule
