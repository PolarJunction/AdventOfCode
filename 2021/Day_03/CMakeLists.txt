cmake_minimum_required(VERSION 3.21)
project(Day_03)

Include(FetchContent)

FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG        v3.0.0-preview3
)

FetchContent_MakeAvailable(Catch2)

set(CMAKE_CXX_STANDARD 14)

add_executable(Day_03 Day_03.cpp)
target_link_libraries(Day_03 PRIVATE Catch2::Catch2WithMain)