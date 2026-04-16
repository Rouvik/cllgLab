`include "bus.v"

module bus_tb();
	reg [3:0] I;
	reg cnt;
	wire [3:0] y;

	mybus b1(cnt, I, y);

	initial begin
		$dumpfile("./wave.vcd");
		$dumpvars(1, b1);
		$display("cnt\tI\ty");
		$monitor("%b\t%b\t%b", cnt, I, y);

		cnt = 0; I = 4'b0010; #10;
		cnt = 0; I = 4'b1010; #10;
		cnt = 1; I = 4'b0101; #10;
		cnt = 1; I = 4'b0011; #10;
	end
endmodule
