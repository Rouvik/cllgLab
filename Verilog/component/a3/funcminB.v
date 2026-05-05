module funcMinB (input wire [2:0] A, output wire [2:0] B);
    assign B[2] = (A[1] & A[0]) | (A[2] & A[1]) | (A[2] & A[0]);
    assign B[1] = A[2] ^ A[1] ^ A[0];
    assign B[0] = ~A[0];
endmodule