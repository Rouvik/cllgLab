`include "a6/binToGray.v"

module binToGray_tb;
	reg [3:0] I;
	wire [3:0] y;

	binToGray b1(I, y);

	initial begin
		$dumpfile("./wave.vcd");
		$dumpvars(1, b1);
		$display("I\ty");
		$monitor("%b\t%b", I, y);

		for(I = 0; I < 15; I = I + 1) #10;
		#10;
	end
endmodule
