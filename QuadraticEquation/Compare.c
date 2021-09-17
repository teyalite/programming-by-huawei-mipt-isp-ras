//
// Created by Abdoulkader Haidara on 17.09.2021.
//

#include "Compare.h"

// Here we have the definitions of some function to compare double withe the tolerance of 1e-11.

const static double TOLERANCE = 0.000000000001;

bool isEqual(double a, double b) {
    return (a - b) < TOLERANCE;
}

bool isZero(double a) {
    return isEqual(a, TOLERANCE);
}