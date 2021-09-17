//
// Created by Abdoulkader Haidara on 17.09.2021.
//

#include "Test.h"
#include "Coefficients.h"
#include "Solution.h"
#include "RootType.h"
#include <stdio.h>
#include "SolveEquation.h"
#include "Compare.h"

const static unsigned NUMBER_OF_TEST = 6;

const static Coefficients testCases[NUMBER_OF_TEST] = {
    {0.0, 0.0, 0.0}, // test case for INF_ROOT
    {0.0, 2.0, -1.0}, // test case for ONE_ROOT
    {1.0, 2.0, 1.0}, // test case  for ONE_DOUBLE_ROOT
    {4.0, 0.0, -49.0}, // test case for TWO_ROOT
    {4.0, 2.0, 2.0}, // test case for NO_ROOT
    {0.0, 0.0, 5.0} // test case for EquationError
};

const static Solution testSolutions[NUMBER_OF_TEST] = {
    {.type = INF_ROOT}, // test case for INF_ROOT
    {.x1 = 0.500000, .type = ONE_ROOT}, // test case for ONE_ROOT
    {.x1 = -1.000000, .type = ONE_DOUBLE_ROOT}, // test case  for ONE_DOUBLE_ROOT
    {.x1= -3.500000, .x2 = 3.500000, .type = TWO_ROOT}, // test case for TWO_ROOT
    {.type = NO_ROOT}, // test case for NO_ROOT
    {.type = EquationError} // test case for EquationError
};

// This function run some test with given coefficients and solution tested.
// Then run the SolveEquation on those coefficients and check if the solutions match.

void RunTest() {

    for (unsigned i = 0; i < NUMBER_OF_TEST; ++i) {
        Solution solution = SolveEquation(testCases[i]);
        if (testSolutions[i].type == solution.type) {

            switch (solution.type) {
                case NO_ROOT:
                    printf("Test %d passed !\n", i);
                    break;
                case ONE_ROOT:
                    if (isEqual(solution.x1, testSolutions[i].x1)) {

                        printf("Test %d passed !\n", i);
                    } else {

                        printf("Test %d failed !\n", i);
                    }

                    break;
                case ONE_DOUBLE_ROOT:
                    if (isEqual(solution.x1, testSolutions[i].x1)) {

                        printf("Test %d passed !\n", i);
                    } else {

                        printf("Test %d failed !\n", i);
                    }

                    break;
                case TWO_ROOT:
                    if (isEqual(solution.x1, testSolutions[i].x1) && isEqual(solution.x2, testSolutions[i].x2)) {

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