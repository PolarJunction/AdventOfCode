/* Day_02 - 2022 */
#define CATCH_CONFIG_MAIN
#include <catch2/catch_test_macros.hpp>

#include <fstream>
#include <iterator>
#include <vector>

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

// TBD
int solvePartOne(std::vector<std::string> &data)
{
	int total = 0;

	for (auto line : data)
	{
		int score = 0;
		int choice = (line[2] - 'W');  // X = 1, Y = 2, Z = 3
		char opponent = line[0];
		char mine = line[2];


		if ((opponent == 'A' && mine == 'X') || (opponent == 'B' && mine == 'Y') || (opponent == 'C' && mine == 'Z'))
		{
			score = 3;
		}
		else if ((opponent == 'A' && mine == 'Y') || (opponent == 'B' && mine == 'Z') || (opponent == 'C' && mine == 'X'))
		{
			score = 6;
		}

		total += (score + choice);
	}

	return total;
}

// TBD
int solvePartTwo(std::vector<std::string> &data)
{
	int total = 0;

	for (auto line : data)
	{
		char opponent = line[0];
		char outcome = line[2];
		int choice = 0;
		char mine = ' ';
		int score = 0;

		if (outcome == 'Y') // Draw
		{
			score = 3;
			mine = opponent;
		}
		else if (outcome == 'Z') // Win
		{
			score = 6;

			if (opponent == 'A')
			{
				mine = 'B';
			}
			else if (opponent == 'B')
			{
				mine = 'C';
			}
			else mine = 'A';

		}
		else if (outcome == 'X') // Lose
		{
			if (opponent == 'A')
			{
				mine = 'C';
			}
			else if (opponent == 'B')
			{
				mine = 'A';
			}
			else mine = 'B';
		}

		choice = (mine - '@');

		total += (score + choice);
	}

    return total;
}

// Tests
TEST_CASE("P1_TestData")
{
    std::vector<std::string> data = parseInput("../test-01.txt");
    REQUIRE(solvePartOne(data) == 15);
}

TEST_CASE("P1_InputData")
{
    std::vector<std::string> data = parseInput("../input.txt");
    REQUIRE(solvePartOne(data) == 10404);
}

TEST_CASE("P2_TestData")
{
    std::vector<std::string> data = parseInput("../test-01.txt");
    REQUIRE(solvePartTwo(data) == 12);
}

TEST_CASE("P2_InputData")
{
    std::vector<std::string> data = parseInput("../input.txt");
    REQUIRE(solvePartTwo(data) == 10334);
}

