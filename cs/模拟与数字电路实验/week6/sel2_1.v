#二选一选择器，输入为a,b,sel，输出为out,sel为0时选a信号
module mux2_1(
	input a,b,sel;
	output out
	);
	assign out = sel?b:a;
endmodule