`include "a4/mux4to1.v"

module mux4to1_tb;
	reg [3:0] I;
	reg [1:0] sel;
	wire y;

	mux4to1 m1(I, sel, y);

	initial begin
		sel = 0;
		$dumpfile("./wave.vcd");
		$dumpvars(1, m1);
		$display("I\tsel\ty");
		$monitor("%b\t%d\t%b", I, sel, y);

		repeat (50) begin
			I = $urandom_range(0, 16);
			sel = sel + 1;

			#10;
		
			if (I[sel] != y) begin
				$display("Fatal error, selection mismatch");
			end
		end
	end
endmodule
