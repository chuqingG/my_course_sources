`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2019/11/22 00:50:29
// Design Name: 
// Module Name: lab7_3
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


module lab7_3(
input clk,rst,       
output reg [7:0] an,
output     [0:7] seg);
reg [23:0] cnt;
reg [15:0] count;
reg [3:0] data;
wire pulse;

always@(posedge clk)     //周期转换
begin
    if(rst) cnt <= 24'h0;
    else if(cnt==24'h98967f) cnt <= 0;
	else cnt <= cnt + 24'b1;
end
    
always@(posedge clk) //分时复用->1khz
begin
	case(cnt[19:18])
        2'b00: an <= 8'b1111_1110;
        2'b01: an <= 8'b1111_1101;
        2'b10: an <= 8'b1111_1011;
        2'b11: an <= 8'b1111_0111;
	endcase
end
always@(posedge clk)
begin
    case(cnt[19:18])
        2'b00: data <= count[3:0];
        2'b01: data <= count[7:4];
        2'b10: data <= count[11:8];
        2'b11: data <= count[15:12];
    endcase
end        
    
assign pulse = (cnt==24'h98967f) ? 1'b1 : 1'b0;     //100M->10
always@(posedge clk) //pulse作为计数使能信号   seg[0]
begin
    if(rst) count[3:0] <= 4'b0;
    else if(pulse) 
    begin
        if(count[3:0] == 4'b1001)
       		count[3:0] <= 4'b0;
    	else 
            count[3:0] <= count[3:0] + 4'b1;
    end
end       
always@(posedge clk) //                seg[1]
begin
    if(rst) count[7:4] <= 4'b0;
    else if(pulse) 
    begin
        if(count[7:0] == 8'b1001_1001)
       		count[7:4] <= 4'b0;
    	else if(count[3:0] == 4'b1001)
        	count[7:4] <= count[7:4] + 4'b1;
    end
end  
always@(posedge clk) //                seg[2]
begin
    if(rst) count[11:8] <= 4'b0;
    else if(pulse) 
    begin
        if(count[11:0] == 12'b0101_1001_1001)
       		count[11:8] <= 4'b0;
    	else if(count[7:0] == 8'b1001_1001)
        	count[11:8] <= count[11:8] + 4'b1;
    end
end  
always@(posedge clk) //                seg[3]
begin
    if(rst) count[15:12] <= 4'b0;
    else if(pulse) 
    begin
        if(count[15:0] == 16'b1001_0101_1001_1001)
       		count[15:12] <= 4'b0;
    	else if(count[11:0] == 12'b0101_1001_1001)
        	count[15:12] <= count[15:12] + 4'b1;
    end
end

dist_mem_gen_0 dist_mem_gen_0(
.a      (data),
.spo    (seg));
endmodule