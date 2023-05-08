#include "queue.h"

void creatQueue (queueType *pq){
    pq->first = 0;
    pq->rear = -1;
    pq->Size = 0 ;
}

void append (EntryType e ,queueType *pq) {
    pq->rear = (pq->rear + 1) % MAXQUEUE ;
    pq->entry[pq->rear] = e ;
    pq->Size ++ ;
}

void remov (EntryType *pe , queueType *pq) {
    *pe = pq->entry[pq->first];
    pq->first = (pq->first + 1) % MAXQUEUE;
    pq->Size --;
}

int queueFull (queueType *pq) {
    return pq->Size == MAXQUEUE;
}

int queueEmpty(queueType *pq) {
    return !pq->Size ;
}

void treaversQueue (queueType *pq , void (*pf) (EntryType e) ) {
    int pos , c ;
    for (pos = pq->first , c = 0 ; c < pq->Size ; c++) {
        (*pf) (pq->entry[pos]);
        pos = (pos+1 ) % MAXQUEUE ;
    }
}

int queueSize(queueType *pq) {
    return pq->Size;
}

void clearQueue(queueType *pq) {
    pq->first = 0;
    pq->rear = -1;
    pq->Size = 0;
}































