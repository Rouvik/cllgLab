`include "majority.v"

module majority_tb();
	reg [2:0] A;
	wire y;
	integer i;

	majority m1(A, y);

	initial begin
		A = 0;
		$dumpfile("./wave.vcd");
		$dumpvars(1, m1);
		$display("A\ty");
		$monitor("%b\t%b", A, y);

		#10;
		for(i = 1; i < 8; i = i + 1) begin
			A = i; #10;
		end
	end

endmodule
