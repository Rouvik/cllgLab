`include "twocompxor.v"

module twocompxor_tb();
	reg [3:0] A;
	wire [3:0] y;
	integer i;

	twocompxor t1(A, y);

	initial begin
		A = 0;
		$dumpfile("./wave.vcd");
		$dumpvars(1, t1);
		$display("./wave.vcd");
		$monitor("%b\t%b", A, y);

		#10;
		for(i = 1; i < 16; i = i + 1) begin
			A = i; #10;
		end
	end
endmodule
