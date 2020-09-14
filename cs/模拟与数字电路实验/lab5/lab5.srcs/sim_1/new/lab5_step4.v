`timescale 1ns / 100ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2019/11/02 10:12:56
// Design Name: 
// Module Name: lab5_step4
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

module lab5_step4();
reg		[3:0]  a,b,c,d;
reg	    [1:0]  sel;
wire	[3:0]  o;
lab5 lab5(
.a		(a),
.b		(b),
.c		(c),
.d		(d),
.sel	(sel),
.o		(o));
initial
begin
		a = 4'h1; b = 4'h5; c = 4'h8; d = 4'hF; sel = 2'h0;
	#20 a = 4'h1; b = 4'h5; c = 4'h8; d = 4'hF; sel = 2'h1;
	#20 a = 4'h1; b = 4'h5; c = 4'h8; d = 4'hF; sel = 2'h2;
	#20 a = 4'h1; b = 4'h5; c = 4'h8; d = 4'hF; sel = 2'h3;
	#20 a = 4'h1; b = 4'h5; c = 4'h8; d = 4'h6; sel = 2'h3;
	#20 $finish;
end	
endmodule

