
void bfs(int num_of_vertixes, Graph g) {
	
	int global_counter = 1;
	int num_of_visited = 0;
	int current = start;
	int sorted[num_of_vertixes];
	int ranks[num_of_vertixes];
	int queue[num_of_vertixes];
	
	push_indegrees_0_to_queue(g, queue);
	
	current = pop(queue);
	
	while (num_of_visited < num_of_vertixes) {
		
		mark_visited(current);
		
		if (check_if_no_unvisited_neighbours(current) == true) {
			
			// Add a rank to the vertix
			ranks[current] = global_counter;
			
			if (queue_is_empty(queue)) {
				start_with_next_unvisited_vertix(current);
			}
			
			current = pop(queue);
			global_counter++;

		}
	
		else {
				
			// Add all the neighbour vertixes to sorted list (or output stack)
			add_neighbours_to_sorted(current);
			
			// Add all the neighbour vertixes to queue list
			push_neighbours_to_queue(current, queue);
			
			mark_visited_neighbours(current);
			
			if (queue_is_empty(queue)) {
				ranks[current] = global_counter;
				start_with_next_unvisited_vertix(current);
			}
			
			current = pop(queue);
		}
	}
	
	for int (i = 0; i < num_of_vertixes; i++) {
		printf ("%d, rank = %d\n", sorted[i], ranks[sorted[i]]);
	}
}