`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2019/11/21 12:09:05
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
module tb( );
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
    #100 rst = 0;
end
test test(
.clk (clk),
.rst (rst),
.led ( ));
endmodule