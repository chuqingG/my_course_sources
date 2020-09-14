`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2019/11/22 18:30:04
// Design Name: 
// Module Name: lab8_4
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
module lab8_4(
input clk,rst,
input button,
input sw,
output reg [7:0] an,
output [0:7] seg);
reg [15:0] latest;
reg	[3:0] data;
reg [3:0] count;
reg [20:0] scan_cnt;
wire button_clean;
wire button_next;
reg  button_curr;
reg  [23:0] clean;
reg [2:0] curr_state;
reg [2:0] next_state0;
reg [2:0] next_state1;


//开关去抖动
always@(posedge clk)           //去抖动
begin
	if(button==1'b0)
		clean <= 24'h0;
	else if(clean<24'h1FFFFFF)
		clean <= clean + 24'b1;
end
always@(posedge clk)     
begin
	button_curr <= button_next;
end
assign button_next = clean[23];
assign button_clean=(button_curr == 1'b0 && button_next == 1'b1);

//时分复用
always@(posedge clk)     
begin
	if(scan_cnt == 21'h17ffff)
		scan_cnt <= 21'b0;
	else
		scan_cnt <= scan_cnt + 21'b1;
end
always@(posedge clk)                  //分时复用->1khz
begin
	case(scan_cnt[20:18])
        3'h0: an <= 8'b1111_1110;
        3'h1: an <= 8'b1111_1101;
        3'h2: an <= 8'b1111_1011;
        3'h3: an <= 8'b1111_0111;
        3'h4: an <= 8'b1110_1111;
		3'h5: an <= 8'b1101_1111;
		default: an <= 8'b1111_1111;
	endcase
end
always@(posedge clk)             
begin
	case(scan_cnt[20:18])
        3'h0: data <= latest[3:0];
        3'h1: data <= latest[7:4];
        3'h2: data <= latest[11:8];
        3'h3: data <= latest[15:12];
        3'h4: data <= curr_state;
		3'h5: data <= count;
		default: data <= 8'b0;
	endcase
end  
//有限状态机第一部分
always@(*)
begin
	case(curr_state)
		3'h0:next_state0 = 3'h0;
		3'h1:next_state0 = 3'h0;
		3'h2:next_state0 = 3'h3;
		3'h3:next_state0 = 3'h4;
		3'h4:next_state0 = 3'h0;
		default:next_state0 = 3'h0;
	endcase
end
always@(*)
begin
	case(curr_state)
		3'h0:next_state1 = 3'h1;
		3'h1:next_state1 = 3'h2;
		3'h2:next_state1 = 3'h2;
		3'h3:next_state1 = 3'h1;
		3'h4:next_state1 = 3'h1;
		default:next_state1 = 3'h0;
	endcase
end
//有限状态机第二部分
always@(posedge clk or posedge rst)      //更改已输入状态数
begin
	if(rst)
		curr_state <= 3'h0;
	else if(button_clean)
	begin
		if(sw == 1'b0)
			curr_state <= next_state0;
		else if(sw == 1'b1)
			curr_state <= next_state1;
	end
end
always@(posedge clk or posedge rst)
begin
	if(rst)
		count <= 4'h0;
	else if(button_clean && curr_state == 3'h4)
		count <= count + 4'h1;
end
always@(posedge clk or posedge rst)      //更改最近四个
begin
	if(rst)
		latest <= 16'h0;
	else if(button_clean)
	begin
		latest[15:4] <= latest[11:0];
		latest[0] <= sw;
	end
end

dist_mem_gen_0 dist_mem_gen_0(
.a      (data),
.spo    (seg));

endmodule



