#include "Stack.h"

void creatStack (stackType *ps) {
    ps->top = 0 ;
}

void push (EntryType e , stackType *ps) {
    ps->entry [ps->top++] = e ;
}

int stackFull(stackType *ps) {
    return ps->top == MAXSTACK ;
}

void pop (EntryType *pe , stackType *ps) {
    *pe = ps->entry[--ps->top];
}

int stackEmpty (stackType *ps) {
    return ps->top == 0 ;
}

void stackTop (EntryType *pe , stackType *ps) {
    *pe = ps->entry[ps->top-1];
}

int stackSize (stackType *ps) {
    return ps->top ;
}

void clearStack(stackType *ps) {
    (*ps).top = 0 ;
}





















