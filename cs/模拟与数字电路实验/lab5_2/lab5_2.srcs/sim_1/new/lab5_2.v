`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2019/11/05 01:07:41
// Design Name: 
// Module Name: lab5_2
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

module lab5_2( );
reg clk,rst_n,d;
wire q;
lab5_3 lab5_3(.clk (clk),.rst_n (rst_n),.d (d),.q (q));
initial
begin
        rst_n = 0;d = 0;
    #12 d = 1;
    #15 rst_n = 1;
    #10 d = 0;
    #13 $finish;
end
initial clk = 0;
always  #5 clk = ~clk;
endmodule
