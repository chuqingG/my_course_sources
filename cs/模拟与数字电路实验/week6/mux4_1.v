module mux2_1(
	input a,b,sel;
	output out
	);
	assign out = sel?b:a;
endmodule

module mux4_1(
	input a,b,c,d,sel1,sel0,
	output out
	);
	wire w1,w2;
	mux2_1 mux1(
	.a		(a),
	.b		(b),
	.sel	(sel1),
	.out	(w1)
	);
	mux2_1 mux2(
	.a		(c),
	.b		(d),
	.sel	(sel1),
	.out	(w2)
	);
	mux2_1 mux3(
	.a		(w1),
	.b		(w2),
	.sel	(sel0),
	.out	(out)
	);
endmodule