/* Day_01 - 2022 */
#define CATCH_CONFIG_MAIN
#include <catch2/catch_test_macros.hpp>

#include <fstream>
#include <iterator>
#include <vector>
#include <algorithm>

std::vector<std::string> parseInput(std::string filepath)
{
    std::ifstream in(filepath);
    std::vector<std::string> fileData;

    for (std::string line; std::getline(in, line); /* */)
    {
        fileData.push_back(line);
    }

    return fileData;
}

std::vector<int> process_data(std::vector<std::string>& data)
{
    std::vector<int> elves;
    int current = 0;

    for (auto line : data)
    {
        if (line.empty())
        {
            elves.push_back(current);
            current = 0;
        }
        else
        {
            current += stoi(line);
        }
    }

    elves.push_back(current);

    return elves;
}

// TBD
int solvePartOne(std::vector<std::string> &data)
{
    std::vector<int> elves = process_data(data);

    // Sort descending
    std::sort(elves.rbegin(), elves.rend());

    // Return the most
    return elves[0];
}

// TBD
int solvePartTwo(std::vector<std::string> &data)
{
    std::vector<int> elves = process_data(data);

    // Sort descending
    std::sort(elves.rbegin(), elves.rend());

    // Sum the three with the most
    return (elves[0] + elves[1] + elves[2]);
    
}

// Tests
TEST_CASE("P1_TestData")
{
    std::vector<std::string> data = parseInput("../../../test-01.txt");
    REQUIRE(solvePartOne(data) == 24000);
}

TEST_CASE("P1_InputData")
{
    std::vector<std::string> data = parseInput("../../../input.txt");
    REQUIRE(solvePartOne(data) == 70369);
}

TEST_CASE("P2_TestData")
{
    std::vector<std::string> data = parseInput("../../../test-01.txt");
    REQUIRE(solvePartTwo(data) == 45000);
}

TEST_CASE("P2_InputData")
{
    std::vector<std::string> data = parseInput("../../../input.txt");
    REQUIRE(solvePartTwo(data) == 999);
}

