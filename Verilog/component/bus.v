module mybus(input cnt, input wire [3:0] I, output wire [3:0] y);
	assign y = cnt ? I : 4'dz;
endmodule
