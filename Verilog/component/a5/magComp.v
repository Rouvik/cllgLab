module magComp (input wire [3:0] A, input wire [3:0] B, output wire gt, output wire lt, output wire eq);
    wire x3 = (A[3] ~^ B[3]);
    wire x2 = (A[2] ~^ B[2]);
    wire x1 = (A[1] ~^ B[1]);

    assign eq = &(~(A ^ B));
    assign gt = (A[3] & ~B[3]) | (x3 & A[2] & ~B[2]) | (x3 & x2 & A[1] & ~B[1]) | (x3 & x2 & x1 & A[0] & ~B[0]);
    assign lt = eq ~| gt;
endmodule