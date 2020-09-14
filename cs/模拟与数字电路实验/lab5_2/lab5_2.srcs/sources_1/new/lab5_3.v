`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2019/11/07 17:46:08
// Design Name: 
// Module Name: lab5_3
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

module lab5_3(
input clk,rst_n,d,
output reg q);
always@(posedge clk)
begin
    if(rst_n == 0)
		q <= 1'b0;
	else
		q <= d;
end
endmodule