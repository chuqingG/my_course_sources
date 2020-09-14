`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2019/11/21 20:06:55
// Design Name: 
// Module Name: lab7_1
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

module lab7_1(
input [15:0] sw,
output [7:0] an,
output [0:7] seg);
assign an = sw[15:8];   
dist_mem_gen_1 dist_mem_gen_1(
.a      (sw[3:0]),
.spo    (seg));
endmodule
