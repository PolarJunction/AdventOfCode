/* Day One - 2021 */
#define CATCH_CONFIG_MAIN
#include "../lib/catch.hpp"

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

int getNumLessThan(std::vector<int> &data, int delta)
{
    int count = 0;

    for (int i = delta; i < data.size(); i++)
    {
        if (data[i] > data[i - delta])
        {
            count++;
        }
    }

    return count;
}

// Return the number of measurements that are larger than the previous
int solvePartOne(std::vector<int> &data)
{
    return getNumLessThan(data, 1);
}

// Return the number of times the sum of measurements in a three measurement window are larger than the previous
int solvePartTwo(std::vector<int> &data)
{
    // A + B + C < B + C + D
    // Simplifies to A < D
    return getNumLessThan(data, 3);
}

// Tests
TEST_CASE("Part One - Test Data")
{
    std::vector<int> data = parseInput("test-01.txt");
    REQUIRE(solvePartOne(data) == 7);
}

TEST_CASE("Part One - Input Data")
{
    std::vector<int> data = parseInput("input.txt");
    REQUIRE(solvePartOne(data) == 1502);
}

TEST_CASE("Part Two - Test Data")
{
    std::vector<int> data = parseInput("test-01.txt");
    REQUIRE(solvePartTwo(data) == 5);
}

TEST_CASE("Part Two - Input Data")
{
    std::vector<int> data = parseInput("input.txt");
    REQUIRE(solvePartTwo(data) == 1538);
}
