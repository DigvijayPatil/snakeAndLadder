cmake_minimum_required(VERSION 3.10)

project(SnakeAndLadder)

file(GLOB_RECURSE sources   src/*.cpp)
file(GLOB_RECURSE headers 	include/*.hpp)

# Get All file from the directory
add_executable(SnakeAndLadder ${sources} ${headers})

target_include_directories(SnakeAndLadder PUBLIC include)