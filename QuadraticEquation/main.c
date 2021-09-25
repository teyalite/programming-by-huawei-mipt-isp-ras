/**
 * @file main.c
 * @author Abdoulkader Abdoulhamane Haidara
 * @brief This is the main function which calls other functions to perform operations
 * @version 0.1
 * @date 2021-09-25
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <stdio.h>
#include "SolveEquation.h"
#include "Test.h"

/**
 * @brief Get the Coefficients object (the coefficients a, b, c).
 * 
 * @return Coefficients 
 */
Coefficients getCoefficients() {

    printf("Equation form : aX^2 + bX + c; Enter values for a, b, c.\n");

    Coefficients coefficients;
    scanf("%lf %lf %lf", &coefficients.a, &coefficients.b, &coefficients.c);

    return coefficients;
};

int main() {
    /**
     * @brief get the coefficient from user input and solve the quadratic equation
     * 
     */
    Coefficients coefficients = getCoefficients();
    Solution solution = SolveEquation(coefficients);
    PrintSolution(solution);

    /**
     * @brief The next line is a test for checking if the solution is correct or not.
     * 
     */
    // RunTest();

    return 0;
}