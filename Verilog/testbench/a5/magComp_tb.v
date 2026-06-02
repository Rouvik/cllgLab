`include "a5/magComp.v"

module magComp_tb;
    reg [3:0] A, B;
    wire gt, lt, eq;

    magComp m1(A, B, gt, lt, eq);

    initial begin
        $dumpfile("./wave.vcd");
        $dumpvars(1, m1);
        $display("A\tB\tgt\tlt\teq");
        $monitor("%d\t%d\t%b\t%b\t%b", A, B, gt, lt, eq);

        A = 5; B = 3; #10;
        A = 2; B = 4; #10;
        A = 1; B = 1; #10;
        A = 6; B = 9; #10;
        A = 10; B = 4; #10;
        A = 0; B = 3; #10;
        A = 0; B = 0; #10;
        A = 4; B = 3; #10;
    end
endmodule
