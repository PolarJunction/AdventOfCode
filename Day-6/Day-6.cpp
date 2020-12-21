/* Day Six - 2020 */
#include <fstream>
#include <algorithm>
#include <set>

int main ()
{
    // Process the input file
    std::ifstream in("input.txt");
    std::string s_answers;
    std::string s_line;
    std::set<char> c_unique;

    int i_count = 0;
    int i_com_count = 0;
    int i_group_sz = 0;

    while( getline(in, s_line))
    {
        // This means we have to add an extra empty line at the end of the input to "finish" the last entry
        if (s_line.empty())
        {
            // Remove duplicates by inserting into set
            c_unique.insert(s_answers.begin(), s_answers.end());

            // P1 - Find the total number of questions responded to
            i_count += c_unique.size();

            // Check how many questions every person responded to
            for(const char &c: c_unique)
            {
                if (std::count(s_answers.begin(), s_answers.end(), c) == i_group_sz)
                {
                    i_com_count++;
                }
            }

            // Cleanup
            i_group_sz = 0;
            c_unique.clear();
            s_answers.clear();
            s_line.clear();
        }
        else
        {
            i_group_sz++;
            s_answers.append(s_line);
        }
    }

    printf("P1 - Sum Questions: %u\n", i_count);
    printf("P2 - Common Questions: %u\n", i_com_count);
}
