/* Day_04 - 2021 */
#define CATCH_CONFIG_MAIN
#include <catch2/catch_test_macros.hpp>

#include <fstream>
#include <iterator>
#include <vector>
#include <sstream>
#include <algorithm>


struct Combination
{
    std::vector<int> values;
    int bingoCount;
};

struct Board
{
    int valueSum;
    bool hasWon;
    int winNum;
    std::vector<Combination> lines;
    std::vector<Combination> columns;
    std::vector<Combination> diagonals;
};

struct Game
{
    std::vector<int> calledNumbers;
    std::vector<Board> gameBoards;
};

Game parseInput(std::string filepath)
{
    std::ifstream in(filepath);
    std::vector<std::string> fileData;

    for (std::string line; std::getline(in, line); /* */)
    {
        fileData.push_back(line);
    }

    Game gameData;

    /* Pull out the called numbers */
    std::stringstream firstLine{fileData[0]};

    for (std::string num; std::getline(firstLine, num, ','); /* */)
    {
        gameData.calledNumbers.push_back(std::atoi(num.c_str()));
    }

    /* Pull out the bingo boards as lines */
    gameData.gameBoards = {};

    int curLine = 2; // Skip the first couple of lines for called number input and gap
    while ((curLine + 5) <= fileData.size())
    {
        Board tmpBoard = {};

        for (int i = curLine; i < curLine + 5; i++)
        {
            Combination tmpCombination = {{}, 0};

            std::stringstream boardLine{fileData[i]};
            /* For each number in the line */
            for (std::string num; std::getline(boardLine, num, ' '); /* */)
            {
                if (num.length() > 0)
                {
                    tmpCombination.values.push_back(std::atoi(num.c_str()));
                }
            }

            tmpBoard.lines.push_back(tmpCombination);
        }

        gameData.gameBoards.push_back(tmpBoard);
        curLine += 6;
    }

    /* For each bingo board, pull out the columns */
    for (auto & board : gameData.gameBoards)
    {
        for (int i = 0; i < board.lines.size(); i++)
        {
            Combination tmpCombination = {{}, 0};

            for (auto & line : board.lines)
            {
                // Push onto the column combinations
                tmpCombination.values.push_back(line.values[i]);

                // Increase the boards sum
                board.valueSum += line.values[i];
            }

            board.columns.push_back(tmpCombination);
        }
    }

    return gameData;
}

bool markCombination(Combination &combination, int num, int &boardSum)
{
    bool foundBingo = false;
    // If the calledNum is in the raw values, check each combination
    if (std::find(combination.values.begin(), combination.values.end(), num) != combination.values.end())
    {
        combination.bingoCount++;
        boardSum -= num;

        if (combination.bingoCount >= combination.values.size())
        {
            foundBingo = true;
        }
    }

    return foundBingo;
}

/* Return a vector of all winning boards in order of win */
std::vector<Board> getWinningBoards(Game game)
{
    std::vector<Board> winningBoards = {};

    for (auto & calledNum: game.calledNumbers)
    {
        for (auto & board : game.gameBoards)
        {
            if (!board.hasWon)
            {
                bool boardBingo = false;

                // Check the lines
                for (auto &line: board.lines)
                {
                    if(markCombination(line, calledNum, board.valueSum))
                    {
                        boardBingo = true;
                    }
                }

                // Check the columns
                for (auto &column: board.columns)
                {
                    int dummySum = 0; /* We don't want to mark the sum twice, ignore it on columns */
                    if(markCombination(column, calledNum, dummySum))
                    {
                        boardBingo = true;
                    }
                }

                if (boardBingo)
                {
                    board.hasWon = true;
                    board.winNum = calledNum;
                    winningBoards.push_back(board);
                }
            }
        }
    }

    return winningBoards;
}

int solvePartOne(Game &gameData)
{
    std::vector<Board> winningBoards = getWinningBoards(gameData);

    if (winningBoards.size() > 0)
    {
        return (winningBoards[0].valueSum * winningBoards[0].winNum);
    }
    return 0;
}

int solvePartTwo(Game &gameData)
{
    std::vector<Board> winningBoards = getWinningBoards(gameData);

    if (winningBoards.size() > 0)
    {
        return (winningBoards[winningBoards.size() - 1].valueSum * winningBoards[winningBoards.size() - 1].winNum);
    }
    return 0;
}

// Tests
TEST_CASE("MarkCombination")
{
    int sum = 10;
    Combination com = {{4, 5, 6, 9}, 0};

    markCombination(com, 5, sum);

    REQUIRE(sum == 5); // Sum is decremented by found mark
    REQUIRE(com.bingoCount == 1); // Bingo count is incremented
}

TEST_CASE("P1_TestData")
{
    Game game = parseInput("../test-01.txt");
    REQUIRE(solvePartOne(game) == 4512);
}

TEST_CASE("P1_InputData")
{
    Game game = parseInput("../input.txt");
    REQUIRE(solvePartOne(game) == 10374);
}

TEST_CASE("P2_TestData")
{
    Game game = parseInput("../test-01.txt");
    REQUIRE(solvePartTwo(game) == 1924);
}

TEST_CASE("P2_InputData")
{

    Game game = parseInput("../input.txt");
    REQUIRE(solvePartTwo(game) == 24742);
}
