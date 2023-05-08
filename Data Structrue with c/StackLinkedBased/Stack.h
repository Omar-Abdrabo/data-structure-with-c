#include <stdlib.h>

typedef char EntryType;

typedef struct stacknode {
    EntryType entry;
    struct stacknode *next;
}StackNode;

typedef struct {
    StackNode *top;
    int Size;
}stackType;

void creatStack (stackType*);
void push (EntryType  , stackType *);
int stackFull (stackType*);
void pop (EntryType* , stackType*);
int stackEmpty (stackType *);
void stackTop (EntryType* , stackType*);
int stackSize (stackType*);
void clearStack (stackType*);
void traversStack (stackType* , void (*pf) (EntryType) ) ;
