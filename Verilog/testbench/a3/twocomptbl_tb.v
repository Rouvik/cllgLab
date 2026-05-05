`include "a3/twocomptbl.v"

module twocomptbl_tb();
	reg [3:0] A;
	wire [3:0] y;

	twocomptbl t1(A, y);

	initial begin
		$dumpfile("./wave.vcd");
		$dumpvars(1, t1);
		$display("./wave.vcd");
		$monitor("%b\t%b", A, y);

		for(A = 0; A != 15; A = A + 1) begin
			#10;
		end
	end
endmodule
