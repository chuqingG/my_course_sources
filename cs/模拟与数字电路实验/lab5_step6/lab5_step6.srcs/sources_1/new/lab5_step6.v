`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2019/11/05 00:30:50
// Design Name: 
// Module Name: lab5_step6
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

module lab5_step6();
reg clk,rst_n,clk_a;
reg [7:0] r1,r2,r3;
integer i;
initial clk = 0;
always #5 clk = ~clk;
initial
begin
    rst_n = 0;
    #55 rst_n = 1;
    #245 $stop;
end
initial
begin
    clk_a = 0;
    forever #5 clk_a = ~clk_a;
end
initial
begin
    r1 = 0;
    repeat(10)
    begin
        @(posedge clk);
        #2 r1 = $random%256;
    end
end
initial
begin
    for(i=0;i<20;i=i+1)
    begin
        r2 = i;#10;
    end
end
initial
begin
    r3=0;
    while(r3<10)
    begin
        @(posedge clk);
        r3 = r3 +1;
    end
end
endmodule