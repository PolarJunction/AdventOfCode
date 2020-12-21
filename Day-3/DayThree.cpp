/* Day Three - 2020 */
#include <fstream>
#include <vector>

// Find the number of trees hit for a given map and slope
int i_get_trees_hit(std::vector<std::string> v_map, int i_mov_x, int i_mov_y)
{
	int i_cur_pos = 0;
	int i_trees_hit = 0;
	int i_map_len = v_map[0].length();

	// For each line in the map
	for (int i=0; i < v_map.size(); i+=i_mov_y) // access by reference to avoid copying
	{  
		// Check if we have hit a tree
    	if (v_map[i][i_cur_pos] == '#')
    	{
			i_trees_hit++;
    	}

		// Update Pos, Check if we need to wrap - simulates a repeating map
		if ((i_cur_pos += i_mov_x) >= i_map_len)
		{
			i_cur_pos -= i_map_len;
		}
	}

	return i_trees_hit;
}


int main ()
{
	// Process the input file
	std::ifstream in("input.txt");
	std::vector<std::pair<int, int>> v_slopes = { {1, 1}, {3, 1}, {5, 1}, {7, 1}, {1, 2} }; // Slopes provided

	std::string s_line;
	std::vector<std::string> v_map;
	int i_total_trees_hit = 1; // Start at one, we multiply trees hit for each slope together to find the product

	// Store the map in a vector of strings - one line per string
	while (in >> s_line)
	{
		v_map.push_back(s_line);
	}

	// For each slope, find the number of trees hit and multiply
	for (int i=0; i < v_slopes.size(); i++)
	{
		i_total_trees_hit *= i_get_trees_hit(v_map, v_slopes[i].first, v_slopes[i].second);
	}

	printf("P1 - Trees Hit: %u\n", i_get_trees_hit(v_map, 3, 1));
	printf("P2 - Total Trees Hit: %u\n", i_total_trees_hit);
}
