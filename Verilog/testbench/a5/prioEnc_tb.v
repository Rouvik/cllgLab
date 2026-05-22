`include "a5/prioEnc.v"

module prioEnc_tb;
    reg [3:0] I;
    wire [1:0] y;
    wire gs;

    prioEnc p1(I, y, gs);

    initial begin
        $dumpfile("./wave.vcd");
        $dumpvars(1, p1);
        $display("I\ty\tgs");
        $monitor("%b\t%d\t%b", I, y, gs);

        for (I = 0; I < 15; I = I + 1) begin
            #10;
        end
        #10;
    end
endmodule