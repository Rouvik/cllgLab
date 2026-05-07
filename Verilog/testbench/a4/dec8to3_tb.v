`include "a4/dec3to8.v"

module dec8to4_tb;
	reg [2:0] I;
	reg en;
	wire [7:0] out;

	dec3to8 d1(I[2], I[1], I[0], out, en);

	initial begin
		$display("I\ten\tout");
		$monitor("%d\t%b\t%b", I, en, out);
		
		en = 0; I = 3; #10;
		
		en = 1;
		for(I = 0; I != 7; I = I + 1) begin
			#10;
		end
	end
endmodule
