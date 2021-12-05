/* Day Three - 2021 */
#define CATCH_CONFIG_MAIN
#include "../lib/catch.hpp"

#include <fstream>
#include <vector>

std::vector<std::string> parseInput(std::string filepath)
{
    std::ifstream in(filepath);
    std::vector<std::string> data;
    std::string line;

    while(std::getline(in, line))
    {
        data.push_back(line);
    }

    return data;
}

int binToInt(std::string inputBinary)
{
    return std::stoi(inputBinary, nullptr, 2);
}

// Return the count for each bit position from all the data
std::vector<int> getBitCount(std::vector<std::string> &data)
{
    std::vector<int> bitCount(data[0].size(), 0);

    for (auto & line: data)
    {
        for (int i = 0; i < line.length(); i++)
        {
            bitCount[i] += int(line[i] - '0');
        }
    }

    return bitCount;
}

// Use the count and total size to determine the mostCommon or leastCommon bit.
// Provide char to use in case of equality
char getCommonBit(int bitCount, int dataSize, bool mostCommon, char equalChar)
{
    if (bitCount > (dataSize - bitCount))
    {
        // Most common char should be 1
        return (mostCommon ? '1' : '0');
    }
    else if (bitCount == (dataSize - bitCount))
    {
        // Equally common
        return equalChar;
    }
    else
    {
        // Most common char should be 0
        return (mostCommon ? '0' : '1');
    }
}

std::string getCommonBitPattern(std::vector<std::string> &data, bool mostCommon, char equalChar)
{
    std::vector<int> bitCount = getBitCount(data);
    std::string pattern = "";

    for(auto & count: bitCount)
    {
        pattern += getCommonBit(count, data.size(), mostCommon, equalChar);
    }

    return pattern;
}

// TBD
int solvePartOne(std::vector<std::string> &data)
{
    std::string gamma = getCommonBitPattern(data, true, '1');
    std::string epsilon = getCommonBitPattern(data, false, '0');

    return (binToInt(gamma) * binToInt(epsilon));
}


int getRating(std::vector<std::string> &inData, bool mostCommon, char equalChar)
{
    // Take a copy of the data
    std::vector<std::string> data = inData;
    
    while (data.size() > 1)
    {
        // Discard numbers that don't match the bitPattern
        for (int bitNum = 0; bitNum < data[0].size(); bitNum++ )
        {
            std::string pattern = getCommonBitPattern(data, mostCommon, equalChar);

            for (int dataVal = (data.size() - 1); dataVal >= 0; dataVal--)
            {
                if (data[dataVal][bitNum] != pattern[bitNum])
                {
                    // Remove it from data
                    data.erase(data.begin() + dataVal);
                }
            }
        }
    }

    // Only one element left
    return binToInt(data[0]);
}

// TBD
int solvePartTwo(std::vector<std::string> &data)
{
    int oxygenRating = getRating(data, true, '1');
    int scrubberRating = getRating(data, false, '0');

    return (oxygenRating * scrubberRating);
}


// Tests

TEST_CASE("BinToInt")
{
    REQUIRE(binToInt("01001") == 9);
    REQUIRE(binToInt("10110") == 22);
}

TEST_CASE("BitCount")
{
    std::vector<std::string> data = {"110", "010", "010"};
    std::vector<int> bitCount = getBitCount(data);

    CHECK(bitCount.size() == 3);

    REQUIRE(bitCount[0] == 1);
    REQUIRE(bitCount[1] == 3);
    REQUIRE(bitCount[2] == 0);
}

TEST_CASE("CommonBit")
{
    REQUIRE(getCommonBit(50, 100, true, 'X') == 'X');
    REQUIRE(getCommonBit(51, 100, true, 'X') == '1');
    REQUIRE(getCommonBit(51, 100, false, 'X') == '0');
    REQUIRE(getCommonBit(49, 100, true, 'X') == '0');
    REQUIRE(getCommonBit(49, 100, false, 'X') == '1');
    REQUIRE(getCommonBit(51, 101, true, 'X') == '1');
    REQUIRE(getCommonBit(50, 101, true, 'X') == '0');
}

TEST_CASE("CommonBitPattern")
{
    std::vector<std::string> data = parseInput("test-01.txt");
    REQUIRE(getCommonBitPattern(data, true, '1') == "10110");
    REQUIRE(getCommonBitPattern(data, false, '0') == "01001");
}

TEST_CASE("P1_TestData")
{
    std::vector<std::string> data = parseInput("test-01.txt");
    REQUIRE(solvePartOne(data) == 198);
}

TEST_CASE("P1_InputData")
{
    std::vector<std::string> data = parseInput("input.txt");
    REQUIRE(solvePartOne(data) == 1307354);
}

TEST_CASE("P2_TestData")
{
    std::vector<std::string> data = parseInput("test-01.txt");
    // Oxygen Rating
    REQUIRE(getRating(data, true, '1') == 23);
    // Scrubber Rating
    REQUIRE(getRating(data, false, '0') == 10);
    // Part Two Solution
    REQUIRE(solvePartTwo(data) == 230);
}

TEST_CASE("P2_InputData")
{
    std::vector<std::string> data = parseInput("input.txt");
    REQUIRE(solvePartTwo(data) == 482500);
}
