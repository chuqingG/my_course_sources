`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2019/11/05 00:43:49
// Design Name: 
// Module Name: lab5_1
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


module lab5_1();
reg a,b;
initial
begin
         a = 1; b = 0;
    #100 b = 1;
    #100 a = 0;
    #75 b = 0;
    #75 b = 1;
    #50 $finish;
end
endmodule
