
void topological_sort (int num_of_vertixes, int start, Graph g) {
	
	int global_counter = 1;
	int num_of_visited = 0;
	int current = start;
	int sorted[num_of_vertixes];
	int ranks[num_of_vertixes];
	
	while (num_of_visited < num_of_vertixes) {
		
		if (check_if_no_unvisited_neighbours(current) == true) {
			mark_visited(current);
			
			// Add vertix to sorted list (or output stack)
			add_to_sorted(current);
			
			// Add a rank to the vertix
			ranks[current] = global_counter;
			global_counter++;
			
			if (go_back_until_unvisited_neighbours(current) == false) {
				start_with_next_unvisited_vertix(current);
			}
		}
	
		else {
			mark_visited(current);
			// Add vertix to sorted list (or output stack)
			add_to_sorted(current);
			go_next_neighbour(current);
			num_of_visited++;
		}
	}
	
	for int (i = 0; i < num_of_vertixes; i++) {
		printf ("%d, rank = %d\n", sorted[i], ranks[sorted[i]]);
	}
}