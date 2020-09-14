module week7-ex4(
	input clk,set_9,
	output reg [3:0] ncount
	);
	always@(posedge clk)
	begin
		if(set_9 == 1b'0 || ncount == 4b'0)
			ncount <= 4'b1001;
		else
			ncount <= ncount - 4b'1;
	end
endmodule