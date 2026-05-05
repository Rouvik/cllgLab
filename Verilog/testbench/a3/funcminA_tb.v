`include "a3/funcminA.v"

module funcminA_tb;
    reg [3:0] I;
    wire Y;

    funcMinA f1(I[3], I[2], I[1], I[0], Y);

    initial begin
        $dumpfile("./wave.vcd");
        $dumpvars(1, f1);
        $display("A\tB\tC\tD\tY");
        $monitor("%b\t%b\t%b\t%b\t%b", I[3], I[2], I[1], I[0], Y);

        for (I = 0; I != 15; I = I + 1) begin
            #10;
        end
        #10;
    end
endmodule