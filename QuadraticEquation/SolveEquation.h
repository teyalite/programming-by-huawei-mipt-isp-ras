//
// Created by Abdoulkader Haidara on 17.09.2021.
//

#ifndef QUADRATICEQUATION_SOLVEEQUATION_H
#define QUADRATICEQUATION_SOLVEEQUATION_H

#include "Solution.h"
#include "Coefficients.h"

Solution SolveLinear(Coefficients coefficients);
Solution SolveEquation(Coefficients coefficients);
void PrintSolution(Solution solution);

#endif //QUADRATICEQUATION_SOLVEEQUATION_H
