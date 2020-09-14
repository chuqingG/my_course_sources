module week7-ex5(
	input clk,r,
	output reg [3:0] pcount
	);
	always@( posedge clk or posedge r)
	begin
		if( r == 1'b1)
			pcount <= 4'b0;
		else
			pcount <= pcount + 4'b1;
	end
endmodule