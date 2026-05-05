module twocomptbl (input wire [3:0] A, output wire [3:0] B);
    assign B[3] = (A[3] & ~A[2] & ~A[1] & ~A[0]) | (~A[3] & (A[2] | A[1] | A[0]));
    assign B[2] = (A[2] & ~A[1] & ~A[0]) | (~A[2] & (A[1] | A[0]));
    assign B[1] = A[1] ^ A[0];
    assign B[0] = A[0];
endmodule