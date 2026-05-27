`include "a5/magComp.v"

module magComp_tb;
    reg [3:0] A, B;
    wire gt, lt, eq;

    magComp m1(A, B, gt, lt, eq);

    initial begin
        $display("A\tB\tgt\tlt\teq");
        $monitor("%d\t%d\t%b\t%b\t%b", A, B, gt, lt, eq);

        repeat (20) begin
            A = $urandom_range(0, 16);
            B = $urandom_range(0, 16);
            #10;
        end
    end
endmodule
