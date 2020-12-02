/* Day One - 2020 */
#include <fstream>
#include <vector>
#include <iterator>
#include <algorithm>

const int tgt_val = 2020;

int main ()
{
	// Process the input file
	std::ifstream in("input.txt");
	std::istream_iterator<int> start(in), end;
	std::vector<int> t_input(start, end);

	// Part One
	for (int i = 0; i < t_input.size(); i++)
	{
		// Loop through the vector, subtract the value from the tgt_val and check if the result is in the array
		auto it = std::find(t_input.begin(), t_input.end(), (tgt_val - t_input[i])); 

		// If we found the result of the subtraction in the vector, use it to find the multiplication 
		if (it != t_input.end())
		{
			printf("Part One - Result Found: %u\n", (t_input[it - t_input.begin()] * t_input[i]));
			break;
		}
	}

	// Part Two
	for(int i = 0; i < t_input.size(); i++)
	{
		// For each value in t_input, subtract each value in the vector, then check if the result is present
		for(int j = 0; j < t_input.size(); j++)
		{
			auto it = std::find(t_input.begin(), t_input.end(), (tgt_val - t_input[i] - t_input[j]));

			if (it != t_input.end())
			{
				int i_val = (t_input[it - t_input.begin()] * t_input[i] * t_input[j]);
				printf("Part Two - Result Found: %u\n", i_val);

				// Break out early
				i = t_input.size();
				break;
			}
		}
	}
}
