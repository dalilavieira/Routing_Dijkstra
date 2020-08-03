module dijkstra(clk, dist, sptSet, out);
	input clk;
	output reg [32-1:0] out;
	input [32-1:0][32-1:0] dist, sptSet;
	integer i;

	reg [32-1:0] min = 9999999;
	

	//inicializacao provisoria
	initial begin
		for (i = 0; i < 32; i = i + 1) begin
			if(sptSet[i] == 0 && dist[i] <= min)begin
				min = dist[i];
				out = i;
			end
		end
		

	end

	always @(posedge clk) begin
	end
endmodule


module test;
	reg clk;
	wire [32-1:0] out;	
	reg [32-1:0][32-1:0] dist, sptSet;
	initial begin
		$dumpfile("dij.vcd");
		$dumpvars;
		clk = 0;
		#200 $finish;
	end
	always #1 clk = !clk;
	dijkstra d1 (clk, dist, sptSet, out);
endmodule
