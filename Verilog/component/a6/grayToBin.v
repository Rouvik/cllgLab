module grayToBin (input [3:0] I, output reg [3:0] y);
    integer i;
    always @(*) begin
        y[3] = I[3];

        for (i = 2; i >= 0; i = i - 1) begin
            y[i] = y[i + 1] ^ I[i];
        end
    end
endmodule