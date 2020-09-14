`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2019/11/22 15:07:29
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
module test(
input clk,rst,
output led);
reg [1:0] curr_state;
reg [1:0] next_state;
//有限状态机第一部分
always@(*)
begin
	case(curr_state)
		2'b00:next_state = 2'b01;
		2'b01:next_state = 2'b10;
		2'b10:next_state = 2'b11;
		2'b11:next_state = 2'b00;
		default:next_state = 2'b00;
	endcase
end
//有限状态机第二部分
always@(posedge clk or posedge rst)
begin
	if(rst)
		curr_state <= 2'b00;
	else
		curr_state <= next_state;
end
//有限状态机第三部分
assign led = (curr_state==2'b11)? 1'b1 : 1'b0;
endmodule