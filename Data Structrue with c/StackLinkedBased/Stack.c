#include "Stack.h"


void creatStack(stackType *ps) {
    ps->top = NULL;
    ps->Size = 0;
}

void push(EntryType e , stackType *ps) {
    StackNode *pn = (StackNode *)malloc(sizeof(StackNode));
    pn->entry = e ;
    pn->next = ps->top;
    ps->top = pn ;
    ps->Size ++ ;
}

void pop(EntryType *pe , stackType *ps) {
    StackNode *pn = ps->top;
    *pe = ps->top->entry ;
    ps->top = ps->top->next;
    free(pn);
    ps->Size--;
}

int stackFull (stackType *ps) {
    return 0;
}

int stackEmpty(stackType *ps) {
    return ps->top == NULL;
}

void stackTop (EntryType *pe, stackType *ps) {
    *pe = ps->top->entry ;
}

int stackSize (stackType *ps){
    return ps->Size;
}

void clearStack(stackType *ps) {
    StackNode *pn = ps->top;
    while (pn){
        ps->top = ps->top->next ;
        free(pn);
        pn = ps->top;
    }
    ps->Size = 0;
}

void traversStack(stackType *ps , void (*pf) (EntryType)) {
        StackNode *pn = (*ps).top ;
        while (pn) {
            (*pf) (pn->entry);
            pn = pn->next;
        }
}




















