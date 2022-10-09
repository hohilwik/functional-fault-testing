`timescale 1ns/1ps

module logic2(
	input wire a,
	input wire b,
	input wire c,
	input wire e,
	input wire h,
	output wire y,
	output wire z
	);

wire d, f, g, h, j, k, w, x, p, q;
assign f = d;

or gate1(d, a, b);
and gate2(p, d, e);
not gate3(g, p);
or gate4(j, g, h);
nand gate5(w, b, j);
and gate6(x, j ,g);
not gate7(q, f);
nor gate8(k, q, c);

// final outputs
and gate9(z, w, x);
or gate10(y, k, a);




endmodule