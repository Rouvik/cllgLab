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

		I = 8'b00101010; sel = 3; #10;
		I = 8'b01101010; sel = 6; #10;
		I = 8'b00000000; sel = 5; #10;
		I = 8'b00101001; sel = 1; #10;
		I = 8'b00101001; sel = 4; #10;
		I = 8'b00101001; sel = 7; #10;
	end
endmodule
