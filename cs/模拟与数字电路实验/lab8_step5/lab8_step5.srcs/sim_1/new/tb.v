`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2019/11/22 15:06:55
// Design Name: 
// Module Name: tb
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
module tb();
reg clk,rst;
initial
begin
	clk = 0;
	forever
	#5 clk = ~clk;
end
initial
begin
	rst = 1;
	#10	rst = 0;
	#50 rst = 1;
	#10 $finish;
end
test test(
.clk	(clk),
.rst	(rst),
.led	());
endmodule

