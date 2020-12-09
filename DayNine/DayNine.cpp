/* Day Eight - 2020 */
#include <fstream>
#include <deque>
#include <vector>
#include <iterator>

bool b_has_sum(std::vector<long>::iterator it_start, std::vector<long>::iterator it_end, long l_val)
{
    for (std::vector<long>::iterator it_i = it_start; it_i != it_end; ++it_i)
    {
        for (std::vector<long>::iterator it_j = it_start; it_j != it_end; ++it_j)
        {
            if(*it_i + *it_j == l_val && *it_i != *it_j)
            {
                return true;
            }
        }
    }
    
    return false;
}

// Check if an i_val has a sum in the queue
bool x_has_sum(const std::deque<long> &q_vals, long l_val)
{
    for (auto i : q_vals)
    {
        for (auto j : q_vals)
        {
            if (i + j == l_val && i != j)
            {
                printf("True - i: %u, j: %u, i_val: %u, \n", i, j, l_val);
                return true;
            }
        }
    }

    return false;
}

// Return true if we didn't hit an infinite loop
int main ()
{
    // Process the input file
    std::ifstream in("input.txt");

    int i_preamble = 25;
    long l_tmp;
    std::deque<long> q_vals;
    std::vector<long> v_vals;

    // Decode the input file into a vector of longs
    while( !in.eof() )
    {
        in >> l_tmp;
        v_vals.push_back(l_tmp);
    }

    // Check each value starting from the preamble for a sum
    for(int i=i_preamble-1; i < v_vals.size(); i++)
    {
        if(b_has_sum(v_vals.begin()+i, v_vals.begin()+i+i_preamble, v_vals[i+1]) == false)
        {
            // Found the first number without a sum, print it and break
            printf("P1 - Val: %ld\n", v_vals[i+1]);
            break;
        }
    }

        // // If we have reached the preamble size, we can start checking for the weakness
        // if (q_vals.size() == i_preamble)
        // {
        //     // if (b_has_sum(q_vals, l_tmp) == false)
        //     {
        //         // We found the first number without a sum, print it and break
        //         printf("P1 - Val: %ld\n", l_tmp);
        //         break;
        //     }
        // }

        // // Populate the queue
        // q_vals.push_back(l_tmp);

        // // Maintain the size of the queue
        // if (q_vals.size() > i_preamble)
        // {
        //     printf("i_tmp: %ld\n", l_tmp);
        //     q_vals.pop_front();
        // }
    // }

}