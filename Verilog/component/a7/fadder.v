module fadder (input a, input b, input cin, output out, output cout);
    assign out = a ^ b ^ cin;
    assign cout = (a & b) | (cin & (a ^ b));
endmodule