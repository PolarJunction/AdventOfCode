/* Day Twelve - 2020 */
#include <fstream>
#include <vector>
#include <cmath>

struct instruction
{
    char c_action;
    int i_value;
};

void v_print_instructions(std::vector<instruction> v_instructions)
{
    for (auto step : v_instructions)
    {
        printf("%c%u\n", step.c_action, step.i_value);
    }
}

int i_turn(int i_dir, int i_angle)
{
    printf("Start: %i, Angle: %i", i_dir, i_angle);
    // 0 - N, 1 - E, 2 - S, 3 - W
    int i_tmp = i_angle/90;
    i_dir += i_tmp;

    // Wrap
    if (i_dir < 0) i_dir += 4;
    if (i_dir > 3) i_dir -= 4;

    printf(", Result: %i\n", i_dir);

    return i_dir;
}

int i_parse_part_one(std::vector<instruction> v_nav)
{
    int i_northSouth = 0;
    int i_eastWest = 0;
    int i_dir = 1; // 0 - N, 1 - E, 2 - S, 3 - W

    for (auto step : v_nav)
    {
        switch (step.c_action)
        {
            case 'N':
                i_northSouth += step.i_value;
                break;
            case 'S':
                i_northSouth -= step.i_value;
                break;
            case 'E':
                i_eastWest += step.i_value;
                break;
            case 'W':
                i_eastWest -= step.i_value;
                break;
            case 'F':
                switch(i_dir)
                {
                    case 0: i_northSouth += step.i_value; break;
                    case 1: i_eastWest += step.i_value; break;
                    case 2: i_northSouth -= step.i_value; break;
                    case 3: i_eastWest -= step.i_value; break;
                }
                break;
            case 'L':
                i_dir = i_turn(i_dir, -step.i_value);
                break;
            case 'R':
                i_dir = i_turn(i_dir, +step.i_value);
                break;
        }
        
        // printf("Instruction: %c%i, ", step.c_action, step.i_value);
    }
    
    printf("northSouth: %i, eastWest: %i, Manhatten Dist: %i\n", i_northSouth, i_eastWest, (std::abs(i_northSouth) + std::abs(i_eastWest)));

    return 0;
}

int main ()
{
    // Process the input file
    std::ifstream in("input.txt");
    std::vector<instruction> v_nav;

    instruction x_tmp;

    // Copy the input into a vector of instructions
    while ( in >> x_tmp.c_action >> x_tmp.i_value )
    {
        v_nav.push_back(x_tmp);
    }

    // Part One - Work out the manhatten result for the instructions
    i_parse_part_one(v_nav);


    // v_print_instructions(v_nav);
}
