cmake_minimum_required(VERSION 3.14)

project(Voronoi VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Voronoi src/main.cpp)

target_include_directories(Voronoi PRIVATE include)
