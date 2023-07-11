
// Run Dijkstra's algorithm on given graph
void shortestPath(Graph const& graph, int source, int N)
{
	// create min heap and push source node having distance 0
	priority_queue<Node, vector<Node>, comp> min_heap;
	min_heap.push({source, 0});

	// set infinite distance from source to v initially
	vector<int> dist(N, INT_MAX);

	// distance from source to itself is zero
	dist[source] = 0;

	// boolean array to track vertices for which minimum
	// cost is already found
	vector<bool> done(N, false);
	done[0] = true;

	// stores predecessor of a vertex (to print path)
	vector<int> prev(N, -1);

	// run till min_heap is not empty
	while (!min_heap.empty())
	{
		// Remove and return best vertex
		Node node = min_heap.top();
		min_heap.pop();

		// get vertex number
		int u = node.vertex;

		// do for each neighbor v of u
		for (auto i : graph.adjList[u])
		{
			int v = i.dest;
			int weight = i.weight;

			// Relaxation step
			if (!done[v] && (dist[u] + weight) < dist[v])
			{
				dist[v] = dist[u] + weight;
				prev[v] = u;
				min_heap.push({v, dist[v]});
			}
		}

		// marked vertex u as done so it will not get picked up again
		done[u] = true;
	}

	for (int i = 1; i < N; ++i)
	{
		cout << "Path from vertex 0 to vertex " << i << " has minimum "
				"cost of " << dist[i] << " and the route is [ ";
		print_route(prev, i);
		cout << "]\n";
	}
}