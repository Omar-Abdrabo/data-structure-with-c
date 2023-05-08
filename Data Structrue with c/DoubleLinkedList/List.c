#include "List.h"
#include <stdlib.h>

void createList(listType *pl) {
    pl->Size = 0;
    pl->currentPos = 0 ;
    pl->current = NULL;
}

void insertElement(int pos , EntryType e ,listType *pl) {
    ListNode *pn = (ListNode *) malloc(sizeof(ListNode));

    pn->entry =e;
    pn->next =NULL;
    pn->previous =NULL;

    if (pl->current == NULL) {
        pl->current = pn ;
    } else if (pos == pl->Size){
        for (;pl->currentPos != pos-1; pl->currentPos++)
            pl->current = pl->current->next;
       pn->previous = pl->current;
       pl->current->next = pn ;
    } else if(pos == 0){
        for (;pl->currentPos != 0 ; pl->currentPos--)
            pl->current  = pl->current->previous;
        pn->next = pl->current;
        pl->current->previous = pn;
    } else if (pl->currentPos >= pos) {
        for (;pl->currentPos != pos-1 ; pl->currentPos--)
            pl->current  = pl->current->previous;
        pn->next = pl->current->next;
        pn->previous = pl->current;
        pl->current->next->previous = pn;
        pl->current->next = pn;
    } else if (pl->currentPos < pos) {
        for (;pl->currentPos != pos-1; pl->currentPos++)
            pl->current = pl->current->next;
        pn->next = pl->current->next;
        pn->previous = pl->current;
        pl->current->next->previous = pn;
        pl->current->next = pn;
    }
    pl->current = pn ;
    pl->currentPos = pos;
    pl->Size ++ ;
}

void treaversList(listType *pl , void (*pf) (EntryType e) ) {
    ListNode *q = pl->current;
    for (int i = pl->currentPos; i != 0 ; i--)
        q  = q->previous;
    while(q){
        if (q != NULL){
            (*pf) (q->entry);
            q = q->next;
        }else {break;}
        }
 }

void deleteElement(int pos , EntryType *pe , listType *pl) {
    ListNode *temp;
    if (pl->currentPos == pos){
        temp = pl->current;
    } else if (pos == pl->Size) {
        for (;pl->currentPos != pos; pl->currentPos++)
            pl->current = pl->current->next;
        temp = pl->current;
        pl->current->previous->next = NULL;
    }else if (pos == 0) {
        for (;pl->currentPos != pos ; pl->currentPos--)
            pl->current  = pl->current->previous;
        temp = pl->current;
        pl->current->next->previous = NULL;
    } else if (pl->currentPos > pos) {
        for (;pl->currentPos != pos ; pl->currentPos--)
            pl->current  = pl->current->previous;
        temp = pl->current;
        pl->current->next->previous = pl->current->previous;
        pl->current->previous->next = pl->current->next;
    } else if (pl->currentPos < pos) {
        for (;pl->currentPos != pos; pl->currentPos++)
            pl->current = pl->current->next;
        temp = pl->current;
        pl->current->next->previous = pl->current->previous;
        pl->current->previous->next = pl->current->next;
    }
    if (pl->current->next != NULL){
        pl->current = pl->current->next;
        pl->currentPos = pos;
    }else if (pl->current->previous != NULL){
        pl->current = pl->current->previous;
        pl->currentPos = pos-1;
    }else {
        pl->current = NULL;
        pl->currentPos = 0;
        }
    *pe = temp->entry;
    free(temp);
    pl->Size--;

}






























//
//void insertElement(int pos , EntryType e , listType *pl) {
//    int i ;
//    //ListNode *temp;
//    ListNode *pn = (ListNode *) malloc(sizeof(ListNode));
//    pn->entry = e;
//    pn->next = NULL;
//    pn->previous = NULL;
//    if (pos == 0 && pl->current == NULL) {
//        pl->current = pn;
//        pn->next = NULL;
//        pn->previous =NULL;
//        pl->currentPos = 0;
//    } else if (pos <= pl->currentPos ) {
//        for (i = pl->currentPos ; i == pos ; i-- )
//            pl->current = pl->current->previous ;
//        pn->next = pl->current->next;
//        pn->previous = pl->current;
//        if (pl->current->previous != NULL)
//            pl->current->previous->next = pn;
//        pl->current->previous = pn;
//
//    } else if(pos > pl->currentPos) {
//        for (i = pl->currentPos ; i == pos ; i++ )
//            pl->current = pl->current->next ;
//        pn->next = pl->current->next;
//        pn->previous = pl->current;
//        if (pl->current->previous != NULL)
//            pl->current->previous->next = pn;
//        pl->current->previous = pn;
//    }
//    pl->current->next = pn;
//    pl->currentPos = pos;
//    pl->Size++;
//}
//
//void deleteElement(int pos , EntryType *pe , listType *pl) {
//    int i = pl->currentPos ;
//    ListNode *temp;
//    if (pos > pl->currentPos) {
//        for ( ; i != pos-1 ; i++)
//            pl->current = pl->current->next;
//        temp = pl->current->next;
//        pl->current->next = pl->current->next->next;
//        pl->current->next->next->previous = pl->current->next->previous;
//        *pe = temp->entry;
//        free(temp);
//    } else  {
//        for (; i != pos+1 ; i--)
//            pl->current = pl->current->previous;
//        temp = pl->current->previous;
//        pl->current->previous = temp ->previous ;
//        temp ->previous ->next = temp ->next;
//        *pe = temp->entry;
//        free(temp);
//    }
//
//    pl->Size--;
//}
//
// void treaversList(listType *pl , void (*pf) (EntryType e) ) {
//    ListNode *q;
//    for (q = pl->current ; q ; q = q->next )
//        (*pf) (q->entry);
// }
//


//if (pos <= pl->currentPos)
//if (pos < pl->currentPos ) {
//        for (i = pl->currentPos ; i > pos ; i-- )
//            pl->current = pl->current->previous ;
//        temp = pl->current;
//        *pe = pl->current->entry;
//        pl->current->previous->next = pl->current->next;
//        pl->current->next->previous = pl->current->previous;
//        free(temp);
//
//    } else if(pos >= pl->currentPos) {
//        for (i = pl->currentPos,temp = pl->current ; i < pos ; i++ )
//            pl->current = pl->current->next ;
//        temp = pl->current;
//        *pe = pl->current->entry;
//        pl->current->previous->next = pl->current->next;
//        pl->current->next->previous = pl->current->previous;
//        free(temp);
//    }
//





