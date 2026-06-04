`include "a6/binToBCD.v"

module binToBCD_tb;
	reg [3:0] I;
	wire [4:0] y;

	binToBCD b1(I, y);

	initial begin
		$dumpfile("./wave.vcd");
		$dumpvars(1, b1);
		$display("I\t\ty");
		$monitor("%b\t\t%b", I, y);

		for(I = 0; I < 15; I = I + 1) #10;
		#10;
	end
endmodule
