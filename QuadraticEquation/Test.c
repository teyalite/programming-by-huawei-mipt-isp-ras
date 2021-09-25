/**
 * @file Test.c
 * @author Abdoulkader Abdoulhamane Haidara
 * @brief Here is the source file for unit tests
 * @version 0.1
 * @date 2021-09-25
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "Test.h"
#include <stdio.h>
#include "SolveEquation.h"
#include "Compare.h"

/**
 * @brief constant determining the number of test.
 * 
 */
enum {
    NUMBER_OF_TEST = 6
};

/**
 * @brief struct for a single test with coefficients and expected soluton
 * 
 */
struct Test {
    Coefficients coefficients;
    Solution solution;
};

typedef struct Test Test;

const static Test tests[NUMBER_OF_TEST] = {
        /**
         * @brief test case for INF_ROOT
         * 
         */
        {
            .coefficients = {0.0, 0.0, 0.0},
            .solution = {.type = INF_ROOT}
        },
        /**
         * @brief test case for ONE_ROOT
         * 
         */
        {
            .coefficients = {0.0, 2.0, -1.0},
            .solution = {.x1 = 0.500000, .type = ONE_ROOT}
        },
        /**
         * @brief test case  for ONE_DOUBLE_ROOT
         * 
         */
        {
            .coefficients = {1.0, 2.0, 1.0},
            .solution = {.x1 = -1.000000, .type = ONE_DOUBLE_ROOT}
        },
        /**
         * @brief test case for TWO_ROOT
         * 
         */
        {
            .coefficients = {4.0, 0.0, -49.0},
            .solution = {.x1= -3.500000, .x2 = 3.500000, .type = TWO_ROOT}
        },
        /**
         * @brief test case for NO_ROOT
         * 
         */
        {
            .coefficients = {4.0, 2.0, 2.0},
            .solution = { .type = NO_ROOT }
        },
        /**
         * @brief test case for EquationError
         * 
         */
        {
            .coefficients = {0.0, 0.0, 5.0},
            .solution = {.type = EquationError}
        }
};

/**
 * @brief This function run some test with given coefficients and solution tested.
 * 
 */

void RunTest() {

    for (unsigned i = 0; i < NUMBER_OF_TEST; ++i) {

        /**
         * @brief run the SolveEquation on those coefficients and check if the solutions match.
         * 
         */
        Solution solution = SolveEquation(tests[i].coefficients);

        if (tests[i].solution.type == solution.type) {

            switch (solution.type) {
                case NO_ROOT:
                    printf("Test %d passed !\n", i);
                    break;
                case ONE_ROOT:
                    if (isEqual(solution.x1, tests[i].solution.x1)) {

                        printf("Test %d passed !\n", i);
                    } else {

                        printf("Test %d failed !\n", i);
                    }

                    break;
                case ONE_DOUBLE_ROOT:
                    if (isEqual(solution.x1, tests[i].solution.x1)) {

                        printf("Test %d passed !\n", i);
                    } else {

                        printf("Test %d failed !\n", i);
                    }

                    break;
                case TWO_ROOT:
                    if (isEqual(solution.x1, tests[i].solution.x1) && isEqual(solution.x2, tests[i].solution.x2)) {

                        printf("Test %d passed !\n", i);
                    } else {

                        printf("Test %d failed !\n", i);
                    }

                    break;
                case INF_ROOT:
                    printf("Test %d passed !\n", i);

                    break;
                case EquationError:
                    printf("Test %d passed !\n", i);

                    break;
                default:
                    break;
            }
        } else {

            printf("Test %d failed !\n", i);
        }
    }
}