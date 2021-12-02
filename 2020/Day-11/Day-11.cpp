/* Day Eleven - 2020 */
#include <fstream>
#include <vector>

const char OCCUPIED = '#';
const char EMPTY = 'L';

// Check if we have a seat in the dir, before the maximum distance
bool b_seat_in_dir(const std::vector<std::string> &v_map, int x_pos, int y_pos, int x_mod, int y_mod, int max_mod)
{
    // For a given line, loop through from 1 - Mod Max checking for seats in that direction
    for (int i = 0; i < max_mod; i++)
    {
        // Apply the direction modification
        x_pos += x_mod;
        y_pos += y_mod;

        // Check the boundaries
        if (x_pos >= 0 && x_pos < v_map[0].length() && y_pos >= 0 && y_pos < v_map.size())
        {
            // Check the seat
            if (v_map[y_pos][x_pos] == OCCUPIED)
            {
                // printf("Seat - X: %u , Y: %u, Char: %c\n", x_pos, y_pos, v_map[y_pos][x_pos]);
                return true;
            }
            else if (v_map[y_pos][x_pos] == EMPTY)
            {
                // Blocked by empty seat
                return false;
            }
        }
        else
        {
            // We've hit a boundary, return false
            return false;
        }
    }
    return false;
}

// Y Row, X Col
int i_get_num_surrounding(const std::vector<std::string> &v_map, int x, int y, int dist)
{
    int i_surr = 0;

    /*
        -x -y |   -y  | +x -y
        _______________________
          -x  |  x y  |  +x 
        _______________________
        -x +y |   +y  | +x +y 

        map[y, x]
    */

    // Top Left
    if (b_seat_in_dir(v_map, x, y, -1, -1, dist)) i_surr++;

    // Top Mid
    if (b_seat_in_dir(v_map, x, y, 0, -1, dist)) i_surr++;

    // Top Right
    if (b_seat_in_dir(v_map, x, y, 1, -1, dist)) i_surr++;

    // Mid Left
    if (b_seat_in_dir(v_map, x, y, -1, 0, dist)) i_surr++;

    // Mid Right
    if (b_seat_in_dir(v_map, x, y, 1, 0, dist)) i_surr++;
    
    // Bot Left
    if (b_seat_in_dir(v_map, x, y, -1, 1, dist)) i_surr++;

    // Bot Mid
    if (b_seat_in_dir(v_map, x, y, 0, 1, dist)) i_surr++;

    // Bot Right
    if (b_seat_in_dir(v_map, x, y, 1, 1, dist)) i_surr++;

    return i_surr;
}


bool b_step_rules(const std::vector<std::string> &v_seat_map, std::vector<std::string> &v_next_seat_map, int i_max_seats, int i_view_dist)
{
    bool b_modified = false; // Track if we have made any changes

    // Start by copying v_seat_map to v_next_seat_map
    v_next_seat_map = v_seat_map;

    // Update according to rules, and modify copy of array for next run
    for (int i = 0; i < v_seat_map.size(); i++)
    {
        for (int j = 0; j < v_seat_map[i].length(); j++)
        {
            // If a seat is empty, and there are no occupied seats adjacent to it, the seat becomes occupied
            if (v_seat_map[i][j] == EMPTY && i_get_num_surrounding(v_seat_map, j, i, i_view_dist) == 0)
            {
                v_next_seat_map[i][j] = OCCUPIED;
                b_modified = true;
            }

            // If a seat is occupied, and X or more seats adjacent are occupied, the seat becomes empty
            if (v_seat_map[i][j] == OCCUPIED && i_get_num_surrounding(v_seat_map, j, i, i_view_dist) >= i_max_seats)
            {
                v_next_seat_map[i][j] = EMPTY;
                b_modified = true;
            }
        }
    }

    // Inform whether or not there has been a change
    return b_modified;
}


int i_count_occupied(const std::vector<std::string> &v_seat_map)
{
    int i_count = 0;

    for (auto row : v_seat_map)
    {
        for (auto seat : row)
        {
            if (seat == OCCUPIED) i_count++;
        }
    }

    return i_count;
}

int main ()
{
    // Process the input file
    std::ifstream in("input.txt");
    std::vector<std::string> v_seats;
    std::vector<std::string> v_seats_curr;
    std::vector<std::string> v_seats_next;
    std::string s_tmp;

    // Copy the input into a vector of strings
    while (in >> s_tmp)
    {
        v_seats.push_back(s_tmp);
    }

    // Copy the original seats so we can use them in both parts
    v_seats_curr = v_seats;

    // Part One
    while (b_step_rules(v_seats_curr, v_seats_next, 4, 1))
    {
        v_seats_curr = v_seats_next;
    }

    printf("P1 - Occupied Seats: %u\n", i_count_occupied(v_seats_curr));

    // Reset for Part Two which has different rules
    v_seats_curr = v_seats;

    // Part Two
    while (b_step_rules(v_seats_curr, v_seats_next, 5, 9999))
    {
        v_seats_curr = v_seats_next;
    }

    printf("P2 - Occupied Seats: %u\n", i_count_occupied(v_seats_curr));
}
