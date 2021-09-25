/**
 * @file Compare.c
 * @author Abdoulkader Abdoulhamane Haidara
 * @brief Here we have the definitions of some function to compare double withe the tolerance of 1e-11.
 * @version 0.1
 * @date 2021-09-25
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "Compare.h"

/**
 * @brief The tolerance for comparison.
 * 
 */
const static double TOLERANCE = 1e-11;

/**
 * @brief Compare two double with the tolerance above.
 * 
 * @param a 
 * @param b 
 * @return true 
 * @return false 
 */
bool isEqual(double a, double b) {
    return (a - b) < TOLERANCE;
}

/**
 * @brief Check if a double is Zero according to our tolerance.
 * 
 * @param a 
 * @return true 
 * @return false 
 */
bool isZero(double a) {
    return isEqual(a, TOLERANCE);
}