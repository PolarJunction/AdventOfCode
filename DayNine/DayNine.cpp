/* Day Nine - 2020 */
#include <fstream>
#include <vector>
#include <iterator>

bool b_has_sum(std::vector<long>::iterator it_start, std::vector<long>::iterator it_end, long l_val)
{
    for (std::vector<long>::iterator it_i = it_start; it_i < it_end; ++it_i)
    {
        for (std::vector<long>::iterator it_j = it_start; it_j < it_end; ++it_j)
        {
            if((*it_i + *it_j == l_val) && (*it_i != *it_j)) return true;
        }
    }
    return false;
}


void v_find_weakness(std::vector<long> v_vals, long l_tgt)
{
    int i_idx = 0;

    while (i_idx < v_vals.size())
    {
        long l_sum = 0;

        for (int i=i_idx; i<v_vals.size(); i++)
        {
            l_sum += v_vals[i];

            if (l_sum > l_tgt)
            {
                break;
            }
            else if (l_sum == l_tgt) // Found the weakness
            {
                long l_smallest = v_vals[i_idx];
                long l_largest = v_vals[i_idx];

                // We need to find the smallest/largest across the range
                for (int j=i_idx; j<=i; j++)
                {
                    if (v_vals[j] < l_smallest) l_smallest = v_vals[j];
                    if (v_vals[j] > l_largest) l_largest = v_vals[j];
                }

                printf("P2 - Weakness: %ld\n", (l_smallest + l_largest));

                i_idx = v_vals.size();
                break;
            }
        }

        i_idx++;
    }
}


int main ()
{
    // Process the input file
    std::ifstream in("input.txt");
    std::vector<long> v_vals;

    int i_preamble = 25;
    long l_tmp = 0;

    // Decode the input file into a vector of longs
    while( !in.eof() )
    {
        in >> l_tmp;
        v_vals.push_back(l_tmp);
    }

    // Check each value starting from the preamble for a sum
    for(int i=i_preamble; i < v_vals.size(); i++)
    {
        // We pass a span of the total vector to be checked
        if(b_has_sum(v_vals.begin()+i-i_preamble, v_vals.begin()+i, v_vals[i]) == false)
        {
            // Found the first number without a sum, print it and break
            printf("P1 - Val: %ld\n", v_vals[i]);
            l_tmp = v_vals[i];
            break;
        }
    }

    // Now that we have the target value, we need to find a contiguous sum
    v_find_weakness(v_vals, l_tmp);
}
