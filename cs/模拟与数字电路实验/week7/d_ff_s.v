module d_ff_r(
	input clk,s,d,
	output reg q
	);
	always@(posedge clk )
	begin
		if(s == 1 )
			q <= 1'b1;
		else
			q <= d;
	end
endmodule