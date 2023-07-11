//Topological normal

#include <stdio.h>
#include <stdlib.h>



// A structure to represent a Vertix 
struct Vertix 
{ 
	// The vertix ID
	int v;
	
	// List of all adjacent vertixes
    struct Vertix** AdjList;  
}; 

// A structure for a graph
struct Graph 
{ 
	// Total number of vertixes in the graph.
    int num_of_vertixes; 
	
	// The vertixes in the graph
    struct Vertix* vertixes; 
}; 

int topological_sort(Graph g, Vertix start) {
	
	bool[g.num_of_vertixes] visited = false;
	int[g.num_of_vertixes] sorted_stack;
	
	struct Vertix** temp_list = start->AdjList; 
	
	visited[start.v] = true;
	while (temp_list != NULL) {
		visited[temp_list->v] = true;
		temp_list++;
	}
	temp_list--;
	sorted_stack[0] = temp_list->v;
	
	
	return 0;
}