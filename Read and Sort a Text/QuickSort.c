//
// Created by Abdoulkader Haidara on 24.09.2021.
//

#include "QuickSort.h"


bool isSpecialChar(char* a) {

    int asciiValue = (int)(*a);

    if ((asciiValue >= CAPITAL_LETTER_START && asciiValue <= CAPITAL_LETTER_END)
            || (asciiValue >= MINUSCULE_LETTER_START && asciiValue <= MINUSCULE_LETTER_END)) {
        return false;
    }

    return true;
}

bool LeftToRight(Line a, Line b) {
    if (a.start == a.end) {
        return true;
    }

    if (b.start == b.end) {
        return false;
    }

    if (isSpecialChar(a.start)) {
        a.start = a.start + 1;
        return LeftToRight(a, b);
    } else if (isSpecialChar(b.start)) {
        b.start = b.start + 1;
        return LeftToRight(a, b);
    } else {
        if (tolower(*(a.start)) > tolower(*(b.start))) {
            return false;
        } else if (tolower(*(a.start)) < tolower(*(b.start))) {
            return true;
        } else {
            a.start = a.start + 1;
            b.start = b.start + 1;
            return LeftToRight(a, b);
        }
    }
}

bool RightToLeft(Line a, Line b) {
    if (a.start == a.end) {
        return true;
    }

    if (b.start == b.end) {
        return false;
    }

    if (isSpecialChar(a.end)) {
        a.end = a.end - 1;
        return RightToLeft(a, b);
    } else if (isSpecialChar(b.end)) {
        b.end = b.end - 1;
        return RightToLeft(a, b);
    } else {
        if (tolower(*(a.end)) > tolower(*(b.end))) {
            return false;
        } else if (tolower(*(a.end)) < tolower(*(b.end))) {
            return true;
        } else {
            a.end = a.end - 1;
            b.end = b.end - 1;
            return RightToLeft(a, b);
        }
    }
}

void Swap(Line* a, Line* b) {
    Line temp = *a;
    *a = *b;
    *b = temp;
}

long Partition(Line* array, long left, long right, bool (*comparator)(Line, Line)) {
    long pivot_index = left;
    long index = left;
    for (long i = left + 1; i < right; i++) {
        if (comparator(array[i], array[pivot_index])) {
            index++;
            Swap(&array[index], &array[i]);
        }
    }
    Swap(&array[index], &array[pivot_index]);
    return index;
}

void QuickSort(Line* array, long left, long right, bool (*comparator)(Line, Line)) {
    if (left < right) {
        long index = Partition(array, left, right, comparator);
        QuickSort(array, index + 1, right, comparator);
        QuickSort(array, left, index, comparator);
    }
}