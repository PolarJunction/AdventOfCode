/* Day Seven - 2020 */
#include <fstream>
#include <vector>
#include <unordered_map>

// Name of the bag, and how many are contained
struct bag
{
    std::string bagName;
    int value;
};

int main ()
{
    // Process the input file
    std::ifstream in("input.txt");
    std::string s_line;

    std::unordered_map<std::string, std::vector<bag>> allBags;

    while( getline(in, s_line))
    {
        std::string s_thisBag;
        std::string s_null;

        // Do something

    }

    return 0;
}
