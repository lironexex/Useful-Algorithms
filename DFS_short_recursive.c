
// Function to perform DFS Traversal
void DFS(Graph const &graph, int v, vector<bool> &discovered)
{
	// mark current node as discovered
	discovered[v] = true;

	// print current node
	cout << v << " ";

	// do for every edge (v -> u)
	for (int u : graph.adjList[v])
	{
		// u is not discovered
		if (!discovered[u])
			DFS(graph, u, discovered);
	}
}
