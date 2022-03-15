#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>


struct Stack {
    long* data;
    long size;
    long capacity;
};

typedef struct Stack Stack;

void stackCtor(Stack* stack, int capacity) {
    assert(stack);
    assert(stack->data == NULL);
    stack->capacity = capacity > 0 ? capacity : 1;
    stack->data = malloc(capacity * sizeof(long));
    stack->size = 0;
}

bool stackPush(Stack* stack, int value) {

    assert(stack);
    assert(stack->data);

    if (stack->size < stack->capacity) {
        stack->data[stack->size++] = value;
    } else {

        stack->data = realloc(stack->data, stack->capacity * 2);
        stack->capacity *= 2;
        stack->data[stack->size++] = value;
    }

    return true;
}

long stackPop(Stack* stack) {

    assert(stack);
    assert(stack->data);
    assert(stack->size > 0);

    long value = stack->data[--stack->size];

    if (stack->size < (stack->capacity / 2)) {
        stack->capacity /= 2;
        stack->data = realloc(stack->data, stack->capacity);
    }

    return value;
}

void stackDtor (Stack* stack) {
    assert(stack);
    assert(stack->data);
    free(stack->data);
    stack->data = NULL;
    stack->size = 0;
    stack->capacity = 0;
}

int main() {
    Stack st = {};
    stackCtor (&st, 2);
    stackPush(&st, 2);
    stackPush(&st, 3);
    stackPush(&st, 4);
    long x = stackPop(&st);
    stackDtor(&st);
    return 0;
}