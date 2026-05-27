module magComp (input wire [3:0] A, input wire [3:0] B, output reg gt, output reg lt, output reg eq);
	always @(*) begin
		if (A > B) begin
			gt = 1; lt = 0; eq = 0;
		end
		else if (A < B) begin
			gt = 0; lt = 1; eq = 0;
		end
		else begin
			gt = 0; lt = 0; eq = 1;
		end
	end
endmodule
