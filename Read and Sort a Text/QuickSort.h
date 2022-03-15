//
// Created by Abdoulkader Haidara on 24.09.2021.
//

#ifndef FILEREADER_QUICKSORT_H
#define FILEREADER_QUICKSORT_H

#include <stdbool.h>
#include <ctype.h>

struct Line {
    char* start;
    char* end;
};

typedef struct Line Line;

enum SpecialChar {
    CAPITAL_LETTER_START = 65,
    CAPITAL_LETTER_END = 90,
    MINUSCULE_LETTER_START = 97,
    MINUSCULE_LETTER_END = 122
};

bool isSpecialChar(char* a);

bool LeftToRight(Line a, Line b);

bool RightToLeft(Line a, Line b);

void QuickSort(Line* array, long left, long right, bool (*comparator)(Line, Line));

#endif //FILEREADER_QUICKSORT_H
