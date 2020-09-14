`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2019/11/21 21:08:45
// Design Name: 
// Module Name: lab7_2
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

module lab7_2(
input clk,rst,
input      [7:0] sw,         //用右8个开关
output reg [7:0] an,
output     [0:7] seg);
reg [19:0] cnt;
reg   scan_cnt;
reg [3:0] data;
wire pulse;
    
always@(posedge clk)     //周期转换
begin
	if(rst) cnt <= 20'h0;
	else if(cnt==20'h186a0) cnt <= 0;
	else cnt <= cnt + 20'b1;
end
assign pulse = (cnt==20'h186a0) ? 1'b1 : 1'b0;     //100M->1K
always@(posedge clk) //pulse作为计数使能信号
begin
    if(rst) scan_cnt <= 1'b0;
    else if(pulse) scan_cnt <= scan_cnt + 1'b1;
end    

always@(posedge clk) //分时复用
begin
    case(scan_cnt)
        1'b0: an = 8'b1111_1110;
        1'b1: an = 8'b1111_1101;
    endcase
end
always@(posedge clk)
begin
    case(scan_cnt)
        1'b0: data <= sw[3:0];
        1'b1: data <= sw[7:4];
    endcase
end
dist_mem_gen_0 dist_mem_gen_0(
.a      (data),
.spo    (seg));
endmodule