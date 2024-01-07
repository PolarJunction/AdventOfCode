# Generate a new day as required
import os
import sys
import shutil

# Get year & day number
year = input("Year: ")
day = str(input("Day: ")).zfill(2)
dayPath = year + '/' + 'Day_' + day

# Check the year exists, create a new one if required
if not os.path.exists(year):
    os.makedirs(year)

# Check if the Day exists, check if we want to overwrite or cancel
if not os.path.exists(dayPath):
    os.makedirs(dayPath)
else:
    # Check if we want to overwrite
    clear = input(dayPath + " already exists, overwrite it?  y/n:  ")

    if (clear == "y"):
        shutil.rmtree(dayPath)
        os.makedirs(dayPath)
    else:
        print("Exiting, day generation aborted")
        sys.exit()

# Assume we have a year & day directory, populate it

# Empty input files
open(dayPath + "/input.txt", "x")
open(dayPath + "/test-01.txt", "x")
open(dayPath + "/Day_" + day + "_Problem.txt", "x")

# Write a basic CMakeLists
cmakeFile = open(dayPath + "/CMakeLists.txt", "w")
cmakeFile.write("""
cmake_minimum_required(VERSION 3.21)
project(Day_%s)

Include(FetchContent)

FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG        v3.0.0-preview3
)

FetchContent_MakeAvailable(Catch2)

set(CMAKE_CXX_STANDARD 14)

add_executable(Day_%s Day_%s.cpp)
target_link_libraries(Day_%s PRIVATE Catch2::Catch2WithMain)
""" % (day, day, day, day))
cmakeFile.close()

cppFile = open(dayPath + "/Day_" + day + ".cpp", "w")

cppFile.write("""/* Day_%s - %s */
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
    return 0;
}

// TBD
int solvePartTwo(std::vector<std::string> &data)
{
    return 0;
}

// Tests
TEST_CASE("P1_TestData")
{
    std::vector<std::string> data = parseInput("../test-01.txt");
    REQUIRE(solvePartOne(data) == 999);
}

TEST_CASE("P1_InputData")
{
    std::vector<std::string> data = parseInput("../input.txt");
    REQUIRE(solvePartOne(data) == 999);
}

TEST_CASE("P2_TestData")
{
    std::vector<std::string> data = parseInput("../test-01.txt");
    REQUIRE(solvePartTwo(data) == 999);
}

TEST_CASE("P2_InputData")
{
    std::vector<int> data = parseInput("../input.txt");
    REQUIRE(solvePartTwo(data) == 999);
}

""" % (day, year))

cppFile.close()
