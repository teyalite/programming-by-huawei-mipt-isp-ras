/**
 * @file SolveEquation.h
 * @author Abdoulkader Abdoulhamane Haidara
 * @brief Header file for Solve Equation and some enums that help
 * @version 0.1
 * @date 2021-09-25
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef QUADRATICEQUATION_SOLVEEQUATION_H
#define QUADRATICEQUATION_SOLVEEQUATION_H

/**
 * @brief the solution contains the two solutions variable which is the max identifiable number of solutions.
 * 
 */

enum RootType {
    NO_ROOT,
    ONE_ROOT,
    ONE_DOUBLE_ROOT,
    TWO_ROOT,
    INF_ROOT,
    EquationError,
};

struct Solution {
    double x1;
    double x2;
    enum RootType type;
};

typedef struct Solution Solution;

struct Coefficients {
    double a;
    double b;
    double c;
};

typedef struct Coefficients Coefficients;

Solution SolveLinear(Coefficients coefficients);
Solution SolveEquation(Coefficients coefficients);
void PrintSolution(Solution solution);

#endif //QUADRATICEQUATION_SOLVEEQUATION_H
