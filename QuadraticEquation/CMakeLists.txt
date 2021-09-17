cmake_minimum_required(VERSION 3.19)
project(QuadraticEquation C)

set(CMAKE_C_STANDARD 99)

add_executable(QuadraticEquation main.c SolveEquation.c SolveEquation.h Coefficients.h Discriminant.h Compare.c Compare.h Solution.h RootType.h Test.c Test.h)