`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2019/11/08 18:56:59
// Design Name: 
// Module Name: cnt32
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

module cnt32(
input			 clk,
output reg [7:0] led);
reg [31:0] cnt;
always@(posedge clk)
begin
	cnt <= cnt + 1;
	led <= cnt[31:24];
end
endmodule
