`include "a7/fadder.v"

module fadder_tb ();
    reg a, b, cin;
    wire out, cout;

    integer i;

    fadder f1(a, b, cin, out, cout);

    initial begin
        $dumpfile("./wave.vcd");
        $dumpvars(1, f1);
        $display("cin\ta\tb\tout\tcout");
        $monitor("%b\t%b\t%b\t%b\t%b", cin, a, b, out, cout);

        for (i = 0; i < 8; i += 1) begin
            {cin, a, b} = i; #10;
        end
    end
endmodule