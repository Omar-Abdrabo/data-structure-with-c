#include "queue.h"

void creatQueue(queueType *pq) {
    pq->first = NULL;
    pq->rear =NULL;
    pq->Size = 0 ;
}

void append(EntryType e , queueType *pq) {
    QueueNode *pn = (QueueNode*) malloc(sizeof(QueueNode));
    pn->entry = e ;
    pn->next = NULL;
    if (!pq->rear)
        pq->first = pn;
    else
        pq->rear->next = pn ;
    pq->rear = pn ;
    pq->Size ++;
}

void remov(EntryType *pe, queueType *pq) {
    QueueNode *pn = pq->first;
    *pe = pn->entry;
    pq->first = pn->next;
    free(pn);
    if (!pq->first)
        pq->rear = NULL;
    pq->Size--;
}

int queueFull(queueType *pq) {
    return 0;
}

int queueEmpty(queueType *pq) {
    return !pq->Size;
}

int queueSize(queueType *pq) {
    return pq->Size;
}

void treaversQueue(queueType *pq , void (*pf)(EntryType e) ) {
    QueueNode *pn;
    for (pn = pq->first ; pn ; pn=pn->next)
        (*pf)(pn->entry);
}

void clearQueue(queueType *pq) {
    while (pq->first) {
        pq->rear = pq->first->next;
        free(pq->first);
        pq->first = pq->rear;
    }
    pq->Size = 0;
}






























