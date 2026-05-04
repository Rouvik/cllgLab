module mytri(input en, input d, output y);
	assign y = en ? d : 1'bz;
endmodule
