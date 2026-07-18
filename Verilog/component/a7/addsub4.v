`include "a7/fadder.v"

module addsub4 (input wire [3:0] a, input wire [3:0] b, input cin, input mode, output wire [3:0] out, output cout);
    wire [3:1] carry;

    fadder f0(a[0], mode ^ b[0], cin | mode, out[0], carry[1]);
    fadder f1(a[1], mode ^ b[1], carry[1], out[1], carry[2]);
    fadder f2(a[2], mode ^ b[2], carry[2], out[2], carry[3]);
    fadder f3(a[3], mode ^ b[3], carry[3], out[3], cout);
endmodule