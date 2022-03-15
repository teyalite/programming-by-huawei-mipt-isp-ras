/**
 * @file SolveEquation.c
 * @author Abdoulkader Abdoulhamane Haidara
 * @brief The solve equation methods and helper methods are located here.
 * @version 0.1
 * @date 2021-09-25
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "SolveEquation.h"
#include <stdio.h>
#include "Compare.h"
#include <math.h>

/**
 * @brief Discriminant Type help us to determine which type of root we may have.
 * 
 */

enum DiscriminantType {
    PositiveDiscriminant,
    NegativeDiscriminant,
    ZeroDiscriminant,
};

/**
 * @brief The value of the determinant and its type.
 * 
 */

struct Discriminant {
    double value;
    enum DiscriminantType type;
};

typedef struct Discriminant Discriminant;

/**
 * @brief This function solve the linear equation given when a is zero.
 * 
 * @param coefficients 
 * @return Solution 
 */

Solution SolveLinear(Coefficients coefficients) {

    if (isZero(coefficients.b)) {

        Solution solution;

        /**
         * @brief When b is zero and c as well we has infinite roots. But if c is not zero then it's not an equation.
         * 
         */

        solution.type = isZero(coefficients.c) ? INF_ROOT : EquationError;

        return solution;
    } else {
        // linear equation solution.
        Solution solution;
        solution.type = ONE_ROOT;
        solution.x1 = -coefficients.c / coefficients.b;

        return solution;
    }
};

// This function compute the discriminant and return a struct discriminant that has the value and an information about the type.

Discriminant GetDiscriminant(Coefficients coefficients) {

    Discriminant discriminant;
    discriminant.value = (coefficients.b * coefficients.b) - (4 * coefficients.a * coefficients.c);

    if (discriminant.value < 0.0) {

        discriminant.type = NegativeDiscriminant;
    } else if (isZero(discriminant.value)) {

        discriminant.type = ZeroDiscriminant;
    } else {

        discriminant.type = PositiveDiscriminant;
    }

    return discriminant;
};

/**
 * @brief This is a function that do the treatment to the solution of the equation
 * 
 * @param coefficients 
 * @return Solution 
 */

Solution SolveEquation(Coefficients coefficients) {

    if (isZero(coefficients.a)) {
        /**
         * @brief when the coefficient a is 0 then it becomes a linear equation
         * 
         * @return return 
         */
        return SolveLinear(coefficients);
    } else {

        Solution solution;
        /**
         * @brief We get the discriminant that has two properties value and type
         * 
         */
        Discriminant discriminant = GetDiscriminant(coefficients);

        switch (discriminant.type) {
            case PositiveDiscriminant:
                /**
                 * @brief when the discriminant is positive we have 2 solutions.
                 * 
                 */
                solution.type = TWO_ROOT;
                double sqrtDiscriminant = sqrt(discriminant.value);

                solution.x1 = (-coefficients.b - sqrtDiscriminant) / (2 * coefficients.a);
                solution.x2 = (-coefficients.b + sqrtDiscriminant) / (2 * coefficients.a);

                break;
            case ZeroDiscriminant:
                /**
                 * @brief In this case the discriminant is equal to 0.
                 * 
                 */
                solution.type = ONE_DOUBLE_ROOT;
                solution.x1 = -coefficients.b / (2 * coefficients.a);

                break;
            case NegativeDiscriminant:
                /**
                 * @brief In this case the discriminant is equal to negative there is no real roots for the equation.
                 * 
                 */
                solution.type = NO_ROOT;

                break;

            default:
                break;
        }

        return solution;
    }
};

/**
 * @brief This function print the solutions if there exist and with a description text.
 * 
 * @param solution 
 */

void PrintSolution(Solution solution) {

    switch (solution.type) {
        case NO_ROOT:
            /**
             * @brief the equation formed by user input doesn't have any solution
             * 
             */
            printf("There is no root for this equation.\n");
            break;
        case ONE_ROOT:
            /**
             * @brief the equation formed by user input only has one solution
             * 
             */
            printf("This equation has one root: %lf.\n", solution.x1);
            break;
        case ONE_DOUBLE_ROOT:
            /**
             * @brief the equation formed by user input has one solution double like (x - 1)^2
             * 
             */
            printf("This equation has one double root: %lf.\n", solution.x1);
            break;
        case TWO_ROOT:
            /**
             * @brief the equation formed by user input has two real roots
             * 
             */
            printf("This equation has two roots: %lf and %lf.\n", solution.x1, solution.x2);
            break;
        case INF_ROOT:
            /**
             * @brief the equation formed by user input has infinite solution this happens when all the coefficients are zero.
             * 
             */
            printf("This equation has infinite roots.\n");
            break;
        case EquationError:
            /**
             * @brief the equation formed by user input is not an equation at all example: a and b are zero and c is not 0
             * 
             */
            printf("Error: Impossible to solve !");
            break;
        default:
            break;
    }
};