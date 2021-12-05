/* Day Two - 2021 */
#define CATCH_CONFIG_MAIN
#include "../lib/catch.hpp"

#include <fstream>
#include <iterator>
#include <vector>

struct Instruction
{
    char direction;
    int value;
};

std::vector<Instruction> parseInput(std::string filepath)
{
    std::ifstream in(filepath);
    std::string line;

    std::vector<Instruction> data = {};

    while (std::getline(in, line))
    {
        Instruction tmp;

        tmp.direction = line[0];
        tmp.value = atoi(line.substr(line.find(" "), (line.length() - 1)).c_str());

        data.push_back(tmp);
    }

    return data;
}

int solvePartOne(std::vector<Instruction> &data)
{
    int distance = 0;
    int depth = 0;

    for (int i = 0; i < data.size(); i++)
    {
        switch (data[i].direction)
        {
            case 'f':
                distance += data[i].value;
                break;
            case 'd':
                depth += data[i].value;
                break;
            default: // u
                depth -=  data[i].value;
                break;
        }
    }

    return (distance * depth);
}

int solvePartTwo(std::vector<Instruction> &data)
{
    int distance = 0;
    int depth = 0;
    int aim = 0;

    for (int i = 0; i < data.size(); i++)
    {
        switch (data[i].direction)
        {
        case 'f':
            distance += data[i].value;
            depth += (aim * data[i].value);
            break;
        case 'd':
            aim += data[i].value;
            break;
        default: // u
            aim -= data[i].value;
            break;
        }
    }

    return (distance * depth);
}

// Tests
TEST_CASE("Part One - Test Data")
{
    std::vector<Instruction> data = parseInput("test-01.txt");
    REQUIRE(solvePartOne(data) == 150);
}

TEST_CASE("Part One - Input Data")
{
    std::vector<Instruction> data = parseInput("input.txt");
    REQUIRE(solvePartOne(data) == 2272262);
}

TEST_CASE("Part Two - Test Data")
{
    std::vector<Instruction> data = parseInput("test-01.txt");
    REQUIRE(solvePartTwo(data) == 900);
}

TEST_CASE("Part Two - Input Data")
{
    std::vector<Instruction> data = parseInput("input.txt");
    REQUIRE(solvePartTwo(data) == 2134882034);
}
