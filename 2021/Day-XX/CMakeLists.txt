cmake_minimum_required(VERSION 3.21)
project(Day_XX)

Include(FetchContent)

FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG        v3.0.0-preview3
)

FetchContent_MakeAvailable(Catch2)

set(CMAKE_CXX_STANDARD 14)

add_executable(Day_XX Day_XX.cpp)
target_link_libraries(Day_XX PRIVATE Catch2::Catch2WithMain)
