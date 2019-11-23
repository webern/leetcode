# cmdgen by (c) Matthew James Briggs
cmake_minimum_required(VERSION 3.0)
project(leetcode LANGUAGES CXX VERSION 0.0.1)

set(DEBUG_INFO "leetcode/CMakeLists.txt")
set(MAIN_PROGRAM_NAME leetcode)
message(STATUS "${DEBUG_INFO}:${CMAKE_CURRENT_LIST_LINE} file starting")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(DIR_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src")

file(GLOB_RECURSE FILES_SOURCES "${DIR_SOURCES}/*.cpp")
file(GLOB_RECURSE FILES_HEADERS "${DIR_SOURCES}/*.h*")
file(GLOB_RECURSE FILES_ALL "${DIR_SOURCES}/*")

add_executable(${MAIN_PROGRAM_NAME} "${FILES_SOURCES}")