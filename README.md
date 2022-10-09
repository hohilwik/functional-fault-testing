# functional-fault-testing

Module for the combinational circuit:

```v
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
```

Module for simulating stuck-at faults for the circuit, with select register and control

```v
`timescale 1ns/1ps
`include "/home/hohilwik/Code/functional-fault-testing/logic2.v"


module top(
	input wire [4:0] sel,
	input wire control,
	input wire a,
	input wire b,
	input wire c,
	input wire e,
	input wire h,
	output wire y,
	output wire z
	);

logic2 circ(a, b, c, e, h, y, z);

initial begin

	if(sel==5'b00000) begin
		// do not force
	end
		
	if(sel==5'b00001) begin
		force circ.a = control;
	end
	
	if(sel==5'b00010) begin
		force circ.b = control;
	end
		
	if(sel==5'b00011) begin
		force circ.c = control;
	end

	if(sel==5'b00100) begin
		force circ.d = control;
	end

	if(sel==5'b00101) begin
		force circ.e = control;
	end

	if(sel==5'b00110) begin
		force circ.f = control;
	end

	if(sel==5'b00111) begin
		force circ.g = control;
	end

	if(sel==5'b01000) begin
		force circ.h = control;
	end

	if(sel==5'b01001) begin
		force circ.j = control;
	end

	if(sel==5'b01010) begin
		force circ.k = control;
	end

	if(sel==5'b01011) begin
		force circ.w = control;
	end

	if(sel==5'b01100) begin
		force circ.x = control;
	end

	if(sel==5'b01101) begin
		force circ.p = control;
	end

	if(sel==5'b01110) begin
		force circ.q = control;
	end

	if(sel==5'b01111) begin
		force circ.y = control;
	end

	if(sel==5'b10000) begin
		force circ.z = control;
	end
end

endmodule
```

Testbench for going through all test cases, and comparing with non-faulty circuit. Output is all single stuck-at faults detected by that test case

```v
`timescale 1ns/1ps

`include "/home/hohilwik/Code/functional-fault-testing/top.v"

module testbench;

reg in1, in2, in3, in4, in5;
wire o1, o2;
wire v1, v2;
reg [4:0] testval;
reg [4:0] sel;
reg control;

integer i, stuck, node;
integer scan1;
integer tb_file1;

top circ_fault(sel, 1'b0, in1, in2, in3, in4, in5, o1, o2);
logic2 circ_verify( in1, in2, in3, in4, in5, v1, v2);

initial begin

$dumpfile("logic2_tb.vcd");
$dumpvars;
	

tb_file1=$fopen("testcases_exhaustive.txt", "r");
	

for(i=0; i<16; i=i+1) begin
	scan1 = $fscanf(tb_file1, "%b\n", testval);
	$display("\nTestcase: %d %b", i+1, testval);

	in1 = testval[4];
	in2 = testval[3];
	in3 = testval[2];
	in4 = testval[1];
	in5 = testval[0];

	$display("Expected: %d%d", v1, v2);		

	for(node=1; node<=16; node=node+1) begin
		sel = node;
		for(stuck=0; stuck<=1; stuck=stuck+1) begin
			if(stuck==0) begin
				control = 1'b0;
			end
			if(stuck==1) begin
				control = 1'b1;
			end
			
			#20
			if( (o1!=v1)||(o2!=v2) ) begin
				$display("node:%d s-a-%d, ", node, stuck);
			end

		end
	end
end 

$finish;

end

endmodule
```

Output table given by fault simulation for each test case:

```
Testcase: 1
node: 1 s-a-1, node: 2 s-a-1, node: 6 s-a-1, node: 7 s-a-0, node: 9 s-a-0, node: 15 s-a-1, node: 16 s-a-0,
Testcase: 2
node: 1 s-a-1, node: 2 s-a-1, node: 6 s-a-1, node: 7 s-a-0, node: 9 s-a-0, node: 15 s-a-1, node: 16 s-a-0,
Testcase: 3
node: 1 s-a-1, node: 2 s-a-1, node: 4 s-a-1, node: 6 s-a-1, node: 7 s-a-0, node: 9 s-a-0, node: 15 s-a-1, node: 16 s-a-0,
Testcase: 4
node: 1 s-a-1, node: 2 s-a-1, node: 4 s-a-1, node: 6 s-a-1, node: 7 s-a-0, node: 9 s-a-0, node: 15 s-a-1, node: 16 s-a-0,
Testcase: 5
node: 1 s-a-1, node: 2 s-a-1, node: 7 s-a-0, node: 9 s-a-0, node: 15 s-a-1, node: 16 s-a-0,
Testcase: 6
node: 1 s-a-1, node: 2 s-a-1, node: 7 s-a-0, node: 9 s-a-0, node: 15 s-a-1, node: 16 s-a-0,
Testcase: 7
node: 1 s-a-1, node: 2 s-a-1, node: 4 s-a-1, node: 7 s-a-0, node: 9 s-a-0, node: 15 s-a-1, node: 16 s-a-0,
Testcase: 8
node: 1 s-a-1, node: 2 s-a-1, node: 4 s-a-1, node: 7 s-a-0, node: 9 s-a-0, node: 15 s-a-1, node: 16 s-a-0,
Testcase: 9
node: 2 s-a-0, node: 3 s-a-1, node: 6 s-a-0, node: 15 s-a-0, node: 16 s-a-1,
Testcase: 10
node: 2 s-a-0, node: 3 s-a-1, node: 6 s-a-0, node: 15 s-a-0, node: 16 s-a-1,
Testcase: 11
node: 2 s-a-0, node: 3 s-a-1, node: 6 s-a-0, node: 15 s-a-0, node: 16 s-a-1,
Testcase: 12
node: 2 s-a-0, node: 3 s-a-1, node: 6 s-a-0, node: 15 s-a-0, node: 16 s-a-1,
Testcase: 13
node: 1 s-a-1, node: 2 s-a-0, node: 3 s-a-0, node: 15 s-a-1, node: 16 s-a-1,
Testcase: 14
node: 1 s-a-1, node: 2 s-a-0, node: 3 s-a-0, node: 15 s-a-1, node: 16 s-a-1,
Testcase: 15
node: 1 s-a-1, node: 2 s-a-0, node: 3 s-a-0, node: 15 s-a-1, node: 16 s-a-1,
Testcase: 16
node: 1 s-a-1, node: 2 s-a-0, node: 3 s-a-0, node: 15 s-a-1, node: 16 s-a-1,
Testcase: 17
node: 1 s-a-0, node: 2 s-a-1, node: 5 s-a-1, node: 7 s-a-0, node: 9 s-a-0, node: 15 s-a-0, node: 16 s-a-0,
Testcase: 18
node: 1 s-a-0, node: 2 s-a-1, node: 5 s-a-1, node: 7 s-a-0, node: 9 s-a-0, node: 15 s-a-0, node: 16 s-a-0,
Testcase: 19
node: 1 s-a-0, node: 4 s-a-0, node: 5 s-a-0, node: 7 s-a-1, node: 15 s-a-0, node: 16 s-a-1,
Testcase: 20
node: 1 s-a-0, node: 4 s-a-0, node: 5 s-a-0, node: 7 s-a-1, node: 15 s-a-0, node: 16 s-a-1,
Testcase: 21
node: 1 s-a-0, node: 2 s-a-1, node: 5 s-a-1, node: 7 s-a-0, node: 9 s-a-0, node: 15 s-a-0, node: 16 s-a-0,
Testcase: 22
node: 1 s-a-0, node: 2 s-a-1, node: 5 s-a-1, node: 7 s-a-0, node: 9 s-a-0, node: 15 s-a-0, node: 16 s-a-0,
Testcase: 23
node: 1 s-a-0, node: 4 s-a-0, node: 5 s-a-0, node: 7 s-a-1, node: 15 s-a-0, node: 16 s-a-1,
Testcase: 24
node: 1 s-a-0, node: 4 s-a-0, node: 5 s-a-0, node: 7 s-a-1, node: 15 s-a-0, node: 16 s-a-1,
Testcase: 25
node: 2 s-a-0, node: 15 s-a-0, node: 16 s-a-1,
Testcase: 26
node: 2 s-a-0, node: 15 s-a-0, node: 16 s-a-1,
Testcase: 27
node: 15 s-a-0, node: 16 s-a-1,
Testcase: 28
node: 15 s-a-0, node: 16 s-a-1,
Testcase: 29
node: 1 s-a-0, node: 2 s-a-0, node: 15 s-a-0, node: 16 s-a-1,
Testcase: 30
node: 1 s-a-0, node: 2 s-a-0, node: 15 s-a-0, node: 16 s-a-1,
Testcase: 31
node: 1 s-a-0, node: 15 s-a-0, node: 16 s-a-1,
Testcase: 32
node: 1 s-a-0, node: 15 s-a-0, node: 16 s-a-1,
```


