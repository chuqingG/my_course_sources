module d_ff_r(
	input clk,r_n,d,
	output reg q
	);
	always@(posedge clk or negedge r_n)
	begin
		if(r_n == 0 )
			q <= 1'b0;
		else
			q <= d;
	end
endmodule