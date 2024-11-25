cmake_minimum_required(VERSION 3.31)
project(Dungeon VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SDL3_DIR "D:/Libs/SDL3/cmake")

add_executable(${PROJECT_NAME} main.cpp)

find_package(SDL3 REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE SDL3::SDL3)