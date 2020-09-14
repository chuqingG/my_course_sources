`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2019/11/22 12:37:30
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
reg clk,button;
initial
begin
    clk = 0;
    forever
    #5 clk = ~clk;
end
initial
begin
    button = 1;
    #30  button = 0;
    #40  button = 1;
    #50  button = 0;
    #60  button = 1;
    #20  button = 0;
    #40  button = 1;
    #200 button = 0;
    #80  button = 1;
end
jitter_clr jitter_clr(
.clk          (clk),
.button       (button),
.button_clean ( ));
endmodule
