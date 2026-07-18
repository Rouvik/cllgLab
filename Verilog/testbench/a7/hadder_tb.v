`include "a7/hadder.v"

module hadder_tb ();
    reg a, b;
    wire out, cout;

    hadder h1(a, b, out, cout);

    initial begin
        $dumpfile("./wave.vcd");
        $dumpvars(1, h1);
        $display("a\tb\tout\tcout");
        $monitor("%b\t%b\t%b\t%b", a, b, out, cout);

         a = 0; b = 0; #10;
         a = 0; b = 1; #10;
         a = 1; b = 0; #10;
         a = 1; b = 1; #10;
    end
endmodule