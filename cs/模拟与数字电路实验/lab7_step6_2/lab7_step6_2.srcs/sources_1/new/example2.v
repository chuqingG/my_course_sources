`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2019/11/21 19:05:32
// Design Name: 
// Module Name: example2
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
module example2(
input [15:0] sw,
output [7:0] an,
output reg [0:7] seg);
assign an = sw[15:8];
always@(*)
begin
    case(sw[3:0])
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
