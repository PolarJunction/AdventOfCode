/* Day Four - 2021 */
#define CATCH_CONFIG_MAIN
#include <catch2/catch_test_macros.hpp>

#include <fstream>
#include <iterator>
#include <vector>

std::vector<int> parseInput(std::string filepath)
{
    std::ifstream in(filepath);
    std::istream_iterator<int> start(in), end;
    std::vector<int> t_input(start, end);
    bool t_first = true;

    for (std::string line; std::getline(in, line);)
    {
        if (t_first)
        {
            // Read the first line into a vector of ints
            t_first = false;
        }

        // Read the  following lines into boards of possible combinations


    }

    return t_input;
}

// TBD
int solvePartOne(std::vector<int> &data)
{
    return 0;
}

// TBD
int solvePartTwo(std::vector<int> &data)
{
    return 0;
}

// Tests
TEST_CASE("Part One - Test Data")
{
    std::vector<int> data = parseInput("test-01.txt");
    REQUIRE(solvePartOne(data) == 999);
}

TEST_CASE("Part One - Input Data")
{
    std::vector<int> data = parseInput("input.txt");
    REQUIRE(solvePartOne(data) == 999);
}

TEST_CASE("Part Two - Test Data")
{
    std::vector<int> data = parseInput("test-01.txt");
    REQUIRE(solvePartTwo(data) == 999);
}

TEST_CASE("Part Two - Input Data")
{
    std::vector<int> data = parseInput("input.txt");
    REQUIRE(solvePartTwo(data) == 999);
}
