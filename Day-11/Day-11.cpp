/* Day Ten - 2020 */
#include <fstream>
#include <vector>
#include <algorithm>

int main ()
{
    // Process the input file
    std::ifstream in("input.txt");
    std::vector<int> v_vals;

    int i_tmp = 0;
    int i_count = 0;
    int i_one_jolt = 0;
    int i_three_jolt = 1; // Final device is always rated 3 higher
    long l_combinations = 1;

    // Lookup for chunk-size count
    int ia_lookup[5] = {1, 1, 2, 4, 7};
   
    // The charging port is always 0
    v_vals.push_back(i_tmp);

    // Decode the input file into a vector of longs
    while( in >> i_tmp )
    {
        v_vals.push_back(i_tmp);
    }

    // Sort the vector
    std::sort(v_vals.begin(), v_vals.end());

    /* P1 count occurances of diff's of 1 or 3
       P2 count consequtive 1 diffs, and calculate the number of possible combinations */
    for (int i = 0; i < v_vals.size(); i++)
    {
        // Get the difference of each adapter from the previous in the vector
        i_tmp = v_vals[i+1] - v_vals[i];

        if (i_tmp == 1)
        {
            i_one_jolt++;
            i_count++;
        }
        else
        {
            if (i_tmp == 3)
            {
                i_three_jolt++;
            }

            // Add the number of combinations from consequtive 1 diffs
            l_combinations *= ia_lookup[i_count];
            i_count = 0;
        }
    }

    printf("P1 - 1j Diff: %u, 3j Diff: %u, Product: %u\n", i_one_jolt, i_three_jolt, (i_one_jolt * i_three_jolt));
    printf("P2 - Combinations: %ld\n", l_combinations);
}
