`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2019/11/07 18:14:20
// Design Name: 
// Module Name: testlab5_4
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


module testlab5_4( );
reg  [2:0] s;
wire [7:0] y;
decoder3_8 decode(.s (s),.y (y));
initial s = 3'b0;
always #10 s = s + 3'b001;
initial
begin
    #80 $finish;
end
endmodule
