`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2019/11/21 19:17:53
// Design Name: 
// Module Name: example3
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

module example3(
input             clk,rst,
input      [15:0] sw,
output reg [7:0]  an,
output     [0:7] seg);
reg [19:0] cnt;
reg [1:0] scan_cnt;
reg [3:0] data;
wire pulse;
    
decode decode( //调用译码模块
.data (data),
.seg (seg));
     
always@(posedge clk)     //周期转换
begin
	if(rst) cnt <= 20'h0;
	else if(cnt==20'h186a0) cnt <= 0;
	else cnt <= cnt + 20'b1;
end
assign pulse = (cnt==20'h186a0) ? 1'b1 : 1'b0;     //100M->1K
always@(posedge clk) //pulse作为计数使能信号
begin
	if(rst) scan_cnt <= 2'h0;
	else if(pulse) scan_cnt <= scan_cnt + 2'b1;
end    

always@(posedge clk) //分时复用
begin
    case(scan_cnt)
        2'h0: an <= 8'b1111_1110;
        2'h1: an <= 8'b1111_1101;
        2'h2: an <= 8'b1111_1011;
        2'h3: an <= 8'b1111_0111;
    endcase
end
always@(posedge clk)
begin
    case(scan_cnt)
        2'h0: data <= sw[3:0];
        2'h1: data <= sw[7:4];
        2'h2: data <= sw[11:8];
    2'h3: data <= sw[15:12];
    endcase
end
endmodule

module decode( //译码模块
input [3:0] data,
output reg [0:7] seg);
always@(*)
begin
    case(data[3:0])
        4'h0: seg = 8'b0000_0011; //CA CB CC CD CE CF CG DP
        4'h1: seg = 8'b1001_1111; //CA CB CC CD CE CF CG DP
        4'h2: seg = 8'b0010_0101; //CA CB CC CD CE CF CG DP
        4'h3: seg = 8'b0000_1101; //CA CB CC CD CE CF CG DP
        4'h4: seg = 8'b1001_1001; //CA CB CC CD CE CF CG DP
        4'h5: seg = 8'b0100_1001; //CA CB CC CD CE CF CG DP
        4'h6: seg = 8'b0100_0001; //CA CB CC CD CE CF CG DP
        4'h7: seg = 8'b0001_1111; //CA CB CC CD CE CF CG DP
        4'h8: seg = 8'b0000_0001; //CA CB CC CD CE CF CG DP
        4'h9: seg = 8'b0000_1001; //CA CB CC CD CE CF CG DP
        4'hA: seg = 8'b0001_0001; //CA CB CC CD CE CF CG DP
        4'hB: seg = 8'b1100_0001; //CA CB CC CD CE CF CG DP
        4'hC: seg = 8'b0110_0011; //CA CB CC CD CE CF CG DP
        4'hD: seg = 8'b1000_0101; //CA CB CC CD CE CF CG DP
        4'hE: seg = 8'b0110_0001; //CA CB CC CD CE CF CG DP
        4'hF: seg = 8'b0111_0001; //CA CB CC CD CE CF CG DP
        default: seg = 8'b0000_0000;
    endcase
end
endmodule