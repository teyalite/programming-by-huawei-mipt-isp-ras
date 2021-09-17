//
// Created by Abdoulkader Haidara on 17.09.2021.
//

#ifndef QUADRATICEQUATION_SOLUTION_H
#define QUADRATICEQUATION_SOLUTION_H

#include "RootType.h"

// the solution contains the two solutions variable which is the max identifiable number of solutions.

struct Solution {
    double x1;
    double x2;
    enum RootType type;
};

typedef struct Solution Solution;

#endif //QUADRATICEQUATION_SOLUTION_H
