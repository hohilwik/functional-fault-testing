`timescale 1ns/1ps
`include "/home/hohilwik/Code/functional-fault-testing/logic2.v"


module top(
	input wire [4:0] sel,
	input wire control,
	input wire a,
	input wire b,
	input wire c,
	input wire e,
	output wire y,
	output wire z
	);

logic2 circ(a, b, c, e, y, z);

initial begin
	$display("entered");


	if(sel==5'b00000) begin
		// do not assign
		$display("top");
	end
		
	if(sel==5'b00001) begin
		/*force*/ circ.a = control;
		$display("here");
	end
	
	if(sel==5'b00010) begin
		/*force*/ circ.b = control;
	end
		
	if(sel==5'b00011) begin
		/*force*/ circ.c = control;
	end

	if(sel==5'b00100) begin
		/*force*/ circ.d = control;
	end

	if(sel==5'b00101) begin
		/*force*/ circ.e = control;
	end

	if(sel==5'b00110) begin
		/*force*/ circ.f = control;
	end

	if(sel==5'b00111) begin
		/*force*/ circ.g = control;
	end

	if(sel==5'b01000) begin
		/*force*/ circ.h = control;
	end

	if(sel==5'b01001) begin
		/*force*/ circ.j = control;
	end

	if(sel==5'b01010) begin
		/*force*/ circ.k = control;
	end

	if(sel==5'b01011) begin
		/*force*/ circ.w = control;
	end

	if(sel==5'b01100) begin
		/*force*/ circ.x = control;
	end

	if(sel==5'b01101) begin
		/*force*/ circ.p = control;
	end

	if(sel==5'b01110) begin
		/*force*/ circ.q = control;
	end

	if(sel==5'b01111) begin
		/*force*/ circ.y = control;
	end

	if(sel==5'b10000) begin
		/*force*/ circ.z = control;
	end


end

endmodule