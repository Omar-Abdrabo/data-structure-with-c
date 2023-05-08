#include "Stack2.h"

void creatStack (stackType *ps) {
    (*ps)[0] = 0 ;
}

void push (int e, stackType *ps) {
    (*ps)[ ++(*ps)[0] ] = e;
}

void pop (int *pe , stackType *ps) {
    *pe = (*ps)[  (*ps)[0]-- ];
}

int stackEmpty(stackType *ps) {
    return (*ps) [0] == 0 ;
}

int stackFull(stackType *ps) {
    return (*ps) [0] == MAX - 1 ;
}

