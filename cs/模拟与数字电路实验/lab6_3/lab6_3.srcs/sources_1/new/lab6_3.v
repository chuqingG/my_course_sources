`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2019/11/08 18:35:44
// Design Name: 
// Module Name: lab6_3
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

module cnt(
input			 clk,
output reg [7:0] led);
always@(posedge clk)
begin
	if(led >= 255)
		led <= 8'b0;
	else
		led <= led + 8'b1;
end
endmodule