`include "a5/funcImpl.v"

module funcImpl_tb();
	reg [2:0] I;
	wire F1, F2, F3;

	funcImpl f1(I, F1, F2, F3);

	initial begin
		$dumpfile("./wave.vcd");
		$dumpvars(1, f1);
		$display("I\tF1\tF2\tF3");
		$monitor("%b\t%b\t%b\t%b", I, F1, F2, F3);
		
		for(I = 0; I < 7; I = I + 1) begin
			#10;
		end
		#10;
	end
endmodule
