cmake_minimum_required(VERSION 3.21)
project(Day_01)

Include(FetchContent)

FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG        v3.0.0-preview3
)

FetchContent_MakeAvailable(Catch2)

set(CMAKE_CXX_STANDARD 14)

add_executable(Day_01 Day_01.cpp)
target_link_libraries(Day_01 PRIVATE Catch2::Catch2WithMain)
