#include <stdio.h>
#include "Coefficients.h"
#include "SolveEquation.h"
#include "Test.h"

// This function get user input for the coefficients a, b, c.

Coefficients getCoefficients() {

    printf("Equation form : aX^2 + bX + c; Enter values for a, b, c.\n");

    Coefficients coefficients;
    scanf("%lf %lf %lf", &coefficients.a, &coefficients.b, &coefficients.c);

    return coefficients;
};

int main() {
    // get the coefficient from user input and solve the quadratic equation
    Coefficients coefficients = getCoefficients();
    Solution solution = SolveEquation(coefficients);
    PrintSolution(solution);

    // The next line is a test for checking if the solution is correct or not.
    // RunTest();

    return 0;
}