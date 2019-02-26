cmake_minimum_required(VERSION 3.12)
project(genoob)

set(CMAKE_CXX_STANDARD 11)

add_library(genoob individual.h node.h gnrandom.h problem.h)