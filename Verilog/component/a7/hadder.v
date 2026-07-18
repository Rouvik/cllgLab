module hadder(input a, input b, output out, output cout);
    assign out = a ^ b;
    assign cout = a & b;
endmodule