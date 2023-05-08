#include "List.h"
#include <stdlib.h>

void createList(listType *pl) {
    pl->head = NULL;
    pl->Size = 0;
}

void insertElement(int pos , EntryType e , listType *pl) {
    int i;
    ListNode *temp;
    ListNode *pn = (ListNode *) malloc(sizeof(ListNode));
    pn->entry = e ;
    pn->next = NULL;
    if (pos == 0) {
        pn->next = pl->head;
        pl->head = pn;
    } else {
       for (temp= pl->head , i = 0 ; i < pos-1 ;i++)
            temp = temp->next;
        pn->next  = temp->next;
        temp->next = pn;
    }
    pl->Size++;
}

void deleteElement(int pos ,EntryType *pe ,listType *pl) {
    int i;
    ListNode *q , *temp;
    if (pos == 0 ) {
        *pe = pl->head->entry;
        temp = pl->head;
        pl->head =  temp->next;
        free(temp);
    } else {
        for (q = pl->head, i = 0; i < pos-1 ; i++)
            q = q->next;
        *pe = q->next->entry;
        temp = q->next;
        q->next = q->next->next ;
        free(temp);
    }
    pl->Size--;
}

int listFull(listType *pl) {
    return 0;
}

int listEmpty(listType *pl) {
    return !pl->Size;
}

 int listSize(listType *pl) {
    return pl->Size ;
 }

 void destroyList(listType *pl) {
    ListNode *q;
    while (pl->head) {
        q = pl->head->next;
        free(pl->head);
        pl->head = q;
    }
    pl->Size = 0;
 }

 void treaversList(listType *pl , void (*pf) (EntryType e) ) {
    ListNode *q;
    for (q = pl->head ; q ; q = q->next )
        (*pf) (q->entry);
 }

 void retrieveElement(int pos , EntryType *pe , listType *pl) {
    int i ;
    ListNode *q;
    for (i = 0 , q = pl->head ; i < pos ; i++ ) {
        q = q->next;
    }
    *pe = q->entry;
 }

 void replaceElement(int pos , EntryType *e , listType *pl) {
    int i ;
    ListNode *q;
    for (i = 0 , q = pl->head ; i < pos ; i++ ) {
        q = q->next;
    }
    q->entry = *e ;
 }



















