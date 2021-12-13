/* Day Two - 2021 */
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
    std::vector<int> data = parseInput("../test-01.txt");
    REQUIRE(solvePartOne(data) == 999);
}

TEST_CASE("Part One - Input Data")
{
    std::vector<int> data = parseInput("../input.txt");
    REQUIRE(solvePartOne(data) == 999);
}

TEST_CASE("Part Two - Test Data")
{
    std::vector<int> data = parseInput("../test-01.txt");
    REQUIRE(solvePartTwo(data) == 999);
}

TEST_CASE("Part Two - Input Data")
{
    std::vector<int> data = parseInput("../input.txt");
    REQUIRE(solvePartTwo(data) == 999);
}
