`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2019/11/22 12:35:50
// Design Name: 
// Module Name: lab8_step1
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////

module jitter_clr(
input clk,
input button,
output button_clean
);
reg [3:0] cnt;
always@(posedge clk)
begin
	if(button==1'b0)
		cnt <= 4'h0;
	else if(cnt<4'h8)
		cnt <= cnt + 1'b1;
end
assign button_clean = cnt[3];
endmodule