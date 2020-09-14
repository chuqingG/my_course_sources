`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2019/11/22 14:44:30
// Design Name: 
// Module Name: test
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
module test();
reg clk,rst,pulse;
initial
begin
	clk = 0;
	forever
	#10 clk = ~clk;
end
initial
begin
	rst = 0;
	#300 rst = 1;
	#50 $finish;
end
initial
begin
	pulse = 0;
	repeat(7)
	#50 pulse = ~pulse;
end
traffic_ctrl traffic_ctrl(
.clk	(clk),
.rst	(rst),
.timer_pulse  (pulse),
.green_light  (),
.yellow_light (),
.red_light	  ());
endmodule
