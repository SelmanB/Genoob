cmake_minimum_required(VERSION 2.8)
project(genoobb)

set(CMAKE_CXX_STANDARD 14)

add_executable(genoobb main.cpp individual.cpp individual.h problem.cpp problem.h gnrandom.cpp gnrandom.h)
