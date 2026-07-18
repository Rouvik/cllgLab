`include "a7/addsub4.v"

module addsub4_tb();
    reg [3:0] a, b;
    reg mode, cin;
    wire cout;
    wire [3:0] out;


    addsub4 a1(a, b, cin, mode, out, cout);

    initial begin
        $dumpfile("./wave.vcd");
        $dumpvars(1, a1);
        $display("cin\ta\tb\tout\tcout\tmode");
        $monitor("%b\t%b\t%b\t%b\t%b\t%b", cin, a, b, out, cout, mode);

        repeat (32) begin
            a = $urandom_range(0, 16);
            b = $urandom_range(0, 16);
            cin = $urandom_range(0, 1);
            mode = $urandom_range(0, 1);
            #10;
        end
    end
endmodule