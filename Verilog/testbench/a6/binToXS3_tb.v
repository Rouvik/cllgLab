`include "a6/binToXS3.v"

module binToXS3_tb;
	reg [3:0] I;
	wire [3:0] y;

	binToXS3 b1(I, y);

	initial begin
		$dumpfile("./wave.vcd");
		$dumpvars(1, b1);
		$display("I\ty");
		$monitor("%b\t%b", I, y);

		for(I = 0; I < 15; I = I + 1) #10;
		#10;
	end
endmodule
