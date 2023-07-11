
// Perform BFS on graph starting from vertex v
void BFS(Graph const &graph, int start, vector<bool> &discovered)
{
	// create a queue used to do BFS
	queue<int> q;

	// mark source vertex as discovered
	discovered[start] = true;

	// push source vertex into the queue
	q.push(start);

	// for numbering ranks
	int global_rank_counter = 0;
	ranks[start] = global_rank_counter;
	global_rank_counter++;

	int current = start;

	// run till queue is not empty
	while (!q.empty())
	{
		// pop front node from queue and print it
		current = q.front();
		q.pop();

		// do for every edge (current -> u)
		for (int u : graph.adjList[current]) {
			if (!discovered[u])
			{
				
				cout << u << " ";
				
				// mark it discovered and push it into queue
				discovered[u] = true;
				q.push(u);
				
				// for counting ranks
				rank[u] = global_rank_counter;
			}
		}
		// for counting ranks
		global_rank_counter++;
	}
}