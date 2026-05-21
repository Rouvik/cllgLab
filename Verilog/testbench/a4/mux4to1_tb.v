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

		I = 4'b1010; sel = 0; #10;
		I = 4'b1011; sel = 0; #10;
		I = 4'b1110; sel = 1; #10;
		I = 4'b1010; sel = 2; #10;
		I = 4'b1110; sel = 3; #10;
		I = 4'b1100; sel = 2; #10;
		I = 4'b1000; sel = 2; #10;
		I = 4'b0100; sel = 1; #10;
	end
endmodule
