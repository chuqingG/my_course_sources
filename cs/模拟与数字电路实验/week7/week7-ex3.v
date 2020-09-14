module week7-ex3(
	input clk,r_n,
	output reg [3:0] pcount
	);
	always@(posedge clk or negedge r_n)
	begin
		if( r_n == 1'b0 )
			pcount <= 4'b0;
		else
			pcount <= pcount + 4'b1;
	end
endmodule
	