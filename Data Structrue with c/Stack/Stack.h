
#define MAXSTACK 5

typedef char EntryType;

typedef struct {
    int top ;
    EntryType entry [MAXSTACK] ;
}stackType;

void creatStack (stackType*);
void push (EntryType  , stackType *);
int stackFull (stackType*);
void pop (EntryType* , stackType*);
int stackEmpty (stackType *);
void stackTop (EntryType* , stackType*);
int stackSize (stackType*);
void clearStack (stackType*);

