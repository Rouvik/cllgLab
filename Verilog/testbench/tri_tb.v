`include "tri.v"

module tri_tb();
	reg d, en;
	wire y;

	mytri t1(en, d, y);

	initial begin
		$dumpfile("./wave.vcd");
		$dumpvars(1, t1);
		$display("en\td\ty");
		$monitor("%d\t%d\t%d", en, d, y);

		en = 0; d = 0; #10;
		en = 0; d = 1; #10;
		en = 1; d = 0; #10;
		en = 1; d = 1; #10;
	end
endmodule
