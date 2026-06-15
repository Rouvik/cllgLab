`include "a6/grayToBin.v"

module grayToBin_tb;
    reg [3:0] I;
    wire [3:0] y;

    grayToBin g1(I, y);

    initial begin
        $dumpfile("./wave.vcd");
        $dumpvars(1, g1);
        $display("I\ty");
        $monitor("%b\t%b", I, y);

        for (I = 0; I < 15; I = I + 1) begin
            #10;
        end
        #10;
    end
endmodule