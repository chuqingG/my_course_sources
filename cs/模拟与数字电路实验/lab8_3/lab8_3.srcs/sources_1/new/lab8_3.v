`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2019/11/22 16:05:16
// Design Name: 
// Module Name: lab8_3
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
module lab8_3(
input clk,rst,
input [1:0] button,
output reg [7:0] an,
output [0:7] seg);
reg	[3:0] data;
reg [7:0] cnt;
reg [7:0] cnt_next;
reg [18:0] scan_cnt;
wire [1:0] button_clean;
wire [1:0] button_next;
reg [1:0] button_curr;
reg [26:0] clean0;
reg [26:0] clean1;

always@(posedge clk)           //去抖动
begin
	if(button[0]==1'b0)
		clean0 <= 27'h0;
	else if(clean0<27'h7FFFFFF)
		clean0 <= clean0 + 27'b1;
end
always@(posedge clk)
begin
	if(button[1]==1'b0)
		clean1 <= 27'h0;
	else if(clean1 < 27'h7FFFFFF)
		clean1 <= clean1 + 27'b1;
end
assign button_next[0] = clean0[26];
assign button_next[1] = clean1[26];
assign button_clean[0]=(button_curr[0] == 1'b0 && button_next[0] == 1'b1)? 1'b1:1'b0;
assign button_clean[1]=(button_curr[1] == 1'b0 && button_next[1] == 1'b1)? 1'b1:1'b0;
always@(posedge clk)     
begin
	button_curr <= button_next;
end


always@(posedge clk)     //周期转换
begin
	scan_cnt <= scan_cnt + 20'b1;
end
always@(posedge clk) //分时复用->1khz
begin
	case(scan_cnt[18])
        1'b0: an <= 8'b1111_1110;
        1'b1: an <= 8'b1111_1101;
		default: an <= 8'b1111_1111;
	endcase
end
always@(posedge clk)
begin
    case(scan_cnt[18])
        1'b0: data <= cnt[3:0];
        1'b1: data <= cnt[7:4];
		default: data <= 4'b0;
    endcase
end   
//有限状态机第一部分
always@(*)
begin
	case(button_clean)
		2'b00:cnt_next = cnt;
		2'b01:cnt_next = cnt - 8'b1;
		2'b10:cnt_next = cnt + 8'b1;
		2'b11:cnt_next = cnt;
		default:cnt_next = 8'h1F;
	endcase
end
//有限状态机第二部分
always@(posedge clk or posedge rst)
begin
	if(rst)
		cnt <= 8'h1F;
	else
		cnt <= cnt_next;
end
//有限状态机第三部分
dist_mem_gen_0 dist_mem_gen_0(
.a      (data),
.spo    (seg));
endmodule
