/* Day Five - 2020 */
#include <fstream>
#include <set>

int main ()
{
    // Process the input file
    std::ifstream in("input.txt");
    std::string s_line;
    std::set<int> seat_ids;

    while( getline(in, s_line) )
    {
        int row_min = 0;
        int row_max = 127;
        int col_min = 0;
        int col_max = 7;

        for (char const &c: s_line)
        {
            switch(c)
            {
                case 'F': // Lower
                    row_max = (row_min + row_max)/2;
                    break;
                case 'B': // Upper
                    row_min = (row_min + row_max)/2;
                    row_min++; // Round Up
                    break;
                case 'L': // Lower
                    col_max = (col_min + col_max)/2;
                    break;
                case 'R': // Upper
                    col_min = (col_min + col_max)/2;
                    col_min++; // Round Up
                    break;
            }
        }

        // Store the seat ID in a set
        seat_ids.insert((row_min * 8) + col_min);
    }

    // The last element in the set will be the largest
    printf("P1 - Max Seat ID: %u\n", *--seat_ids.end());

    // Check the whole set for a missing number
    for(auto it = seat_ids.begin(); it != seat_ids.end(); it++)
    {
        // Seat skipped, difference between numbers == 2
        if(next(it) != seat_ids.end() && (*(next(it)) - *it) == 2) 
        {
            printf("P2 - My Seat ID: %u\n", *(it)+1);
        }
    }
}
