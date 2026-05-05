module funcMinA (input A, input B, input C, input D, output Y);
    assign Y = (~B & ~C) | (~A & ~C & ~D) | (~A & ~B & D) | (A & B & C & D);
endmodule