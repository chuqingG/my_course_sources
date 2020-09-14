#八位优先编码器
module encoder8_3(
	input [7:0] i,
	output reg [2:0] y
	);
	always@(i)
		case(i)
		8'b1xxx_xxxx:y = 3'd7;
		8'b01xx_xxxx:y = 3'd6;
		8'b001x_xxxx:y = 3'd5;
		8'b0001_xxxx:y = 3'd4;
		8'b0000_1xxx:y = 3'd3;
		8'b0000_01xx:y = 3'd2;
		8'b0000_001x:y = 3'd1;
		8'b0000_0001:y = 3'd0;
		endcase
	end
endmodule