`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2019/11/15 19:10:17
// Design Name: 
// Module Name: lab7_step4
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

module ttt(
input  clk,rst,
output reg [7:0] led);
reg [3:0] cnt;
wire pulse_10mhz;
//always #5 clk = ~clk;
always@(posedge clk)
begin
    if(rst)
        cnt <= 4'h0;
    else if(cnt>=9)
        cnt <= 4'h0;
    else
        cnt <= cnt + 4'h1;
end
assign pulse_10mhz = (cnt == 4'h1);
always@(posedge clk)
begin
    if(rst)
        led <= 1'b0;
    else if(pulse_10mhz)
        led <= ~led;
end
endmodule