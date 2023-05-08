#include <stdlib.h>;
typedef int EntryType ;

typedef struct queuenode {
    EntryType entry;
    struct queuenode *next;
}QueueNode;

typedef struct {
    QueueNode *first;
    QueueNode *rear;
    int Size;
}queueType;



void creatQueue (queueType *pq);
void append (EntryType e , queueType *pq);
void remov (EntryType *pe , queueType *pq) ;
int queueFull (queueType *pq);
int queueEmpty (queueType *pq);
void treaversQueue (queueType *pq , void (*pf) (EntryType e) );
int queueSize (queueType *pq);
void clearQueue (queueType *pq);
