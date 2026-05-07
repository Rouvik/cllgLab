`include "a4/mux8to1.v"

module mux8to1_tb;
	reg [7:0] I;
	reg [2:0] sel;
	wire y;

	mux8to1 m1(I, sel, y);

	initial begin
		sel = 0;
		$dumpfile("./wave.vcd");
		$dumpvars(1, m1);
		$display("I\t\tsel\ty");
		$monitor("%b\t%d\t%b", I, sel, y);

		repeat (50) begin
			I = $urandom_range(0, 256);
			sel = sel + 1;

			#10;
		
			if (I[sel] != y) begin
				$display("Fatal error, selection mismatch");
			end
		end
	end
endmodule
