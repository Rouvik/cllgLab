`include "xor.v"

module xor_tb();

	reg a, b;
	wire y;

	myxor x1(a, b, y);

	initial begin
		$dumpfile("./wave.vcd");
		$dumpvars(1, x1);
		$display("a\tb\ty");
		$monitor("%b\t%b\t%b", a, b, y);

		a = 0; b = 0; #10;
		a = 0; b = 1; #10;
		a = 1; b = 0; #10;
		a = 1; b = 1; #10;
	end
endmodule
