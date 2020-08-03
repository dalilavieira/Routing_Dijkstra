module dijkstra(out, clk, reset);
	input clk, reset;
	output reg [32-1:0] out;
	integer i, v;

	//parameters
	reg [32-1:0]graph[512-1:0];
	reg [32-1:0]src, dest, u;
	reg signed [32-1:0]parent[32-1:0];

	//intern
	reg [32-1:0] dist[32-1:0], sptSet[32-1:0];
	reg [32-1:0] min = 9999999;
	//inicializacao provisoria
	initial begin
		for (i = 0; i < 32; i = i + 1) begin
			parent[i] = -1;
			dist[i] = 9999999;
			sptSet[i] = 0;
			graph[i] = 0;
		end
		src = 0;
		dest = 3;
		graph[0+9*1] = 1;
		graph[0+9*2] = 1;
		graph[1+9*3] = 4;
	end

	always @(posedge clk) begin
		dist[src] = 0;

		for (i = 0; i < 31; i = i + 1) begin
			//u = minDist(dist, sptSet)
			min = 9999999;
			for (v = 0; v < 32; v = v + 1) begin
				if(sptSet[v] == 0 && dist[v] <= min)begin
					min = dist[v];
					u = i;
				end
			end	
			//if(u != 0)begin
			//$write(u,"\n");end
			sptSet[u] = 1;
			for (v = 0; v < 31; v = v + 1) begin
				if (!sptSet[v] && graph[u+9*v] && dist[u] + graph[u+9*v] < dist[v]) begin
					parent[v] = u; 
					dist[v] = dist[u] + graph[u+9*v]; 
				end
			end
		end

		out = dist[dest];
		$write(out,"\n");
	end
endmodule


module test;
	reg clk;
	reg reset;
	initial begin
		$dumpfile("dij.vcd");
		$dumpvars;
		clk = 0;
		reset = 0;
		#30 $finish;
	end
	always #1 clk = !clk;
	wire [32-1:0] out;
	dijkstra d1 (out, clk, reset);
endmodule
