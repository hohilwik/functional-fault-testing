module test_mux(
	input [7:0]val,
	output wire [255:0]out
	);
	
genvar i;

generate for(i=0; i<256; i=i+1)
	begin:genbit
		if(val==i) begin
			out[i] = 1;
		end else begin
			out[i] = 0;
		end
			
		
	end
	endgenerate

endmodule