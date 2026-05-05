`include "a3/funcminB.v"

module funcminB_tb;
    reg [2:0] I;
    wire [2:0] Y;

    funcMinB f1(I, Y);

    initial begin
        $dumpfile("./wave.vcd");
        $dumpvars(1, f1);
        $display("A\tB");
        $monitor("%d\t%d", I, Y);

        for (I = 0; I != 7; I = I + 1) begin
            #10;
        end
    end
endmodule