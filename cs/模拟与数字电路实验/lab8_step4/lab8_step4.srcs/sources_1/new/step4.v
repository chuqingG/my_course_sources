`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2019/11/22 14:43:48
// Design Name: 
// Module Name: step4
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
module traffic_ctrl(
input clk,
input rst,
input timer_pulse,
output green_light,yellow_light,red_light
);
parameter C_PASS = 2'b00;
parameter C_TRANS = 2'b01;
parameter C_STOP = 2'b10;
reg [1:0] curr_state;
reg [1:0] next_state;
//����״̬����һ����
always@(*)
begin
	if(timer_pulse)
	begin
		case(curr_state)
			C_PASS: next_state = C_TRANS;
			C_TRANS:next_state = C_STOP;
			C_STOP: next_state = C_PASS;
			default:next_state = C_PASS;
		endcase
	end
	else
		next_state = curr_state;
end
//����״̬���ڶ�����
always@(posedge clk or posedge rst)
begin
	if(rst)
		curr_state <= C_PASS;
	else
		curr_state <= next_state;
end
//����״̬����������,������źŵĸ�ֵ��Ӧ���ڴ˲���
assign green_light = (curr_state==C_PASS)? 1'b1 : 1'b0;
assign yellow_light = (curr_state==C_TRANS)? 1'b1 : 1'b0;
assign red_light = (curr_state==C_STOP)? 1'b1 : 1'b0;
endmodule
