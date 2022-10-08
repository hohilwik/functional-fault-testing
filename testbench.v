`timescale 1ns/1ps

`include "/home/hohilwik/Code/functional-fault-testing/top.v"

module testbench;

reg in1, in2, in3, in4;
wire o1, o2;
wire v1, v2;
reg [3:0] testval;
reg [4:0] sel;
reg control;

integer i, stuck, node;
integer scan1;
integer tb_file1;

top circ_fault(sel, 1'b0, in1, in2, in3, in4, o1, o2);
logic2 circ_verify( in1, in2, in3, in4, v1, v2);

initial begin

$dumpfile("logic2_tb.vcd");
$dumpvars;
	

tb_file1=$fopen("testcases_exhaustive.txt", "r");
	

for(i=0; i<16; i=i+1) begin
	scan1 = $fscanf(tb_file1, "%b\n", testval);
	$display("\nTestcase: %d %b", i+1, testval);

	in1 = testval[3];
	in2 = testval[2];
	in3 = testval[1];
	in4 = testval[0];

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
				$display("node:%d, sa%d ", node, stuck);
			end
			//$display("o1o2 %d%d v1v2 %d%d", o1, o2, v1, v2);


		end
	end
end 

$finish;

end




endmodule
