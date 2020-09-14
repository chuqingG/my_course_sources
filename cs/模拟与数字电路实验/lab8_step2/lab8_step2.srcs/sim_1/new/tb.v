`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2019/11/22 12:52:43
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
module tb( );               //·ÂÕæÎÄ¼þ
reg clk,button;
initial
begin
	clk = 0;
    forever
    #5 clk = ~clk;
end
initial
begin
    button = 0;
    #50 button = 1;
    #100 button = 0;
    #30 $finish;
end
step2 step2(
.clk	(clk),
.button	(button),
.button_redge ());
endmodule
