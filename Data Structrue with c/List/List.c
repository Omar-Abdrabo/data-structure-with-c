#include "List.h"

void createList(listType *pl) {
    pl->Size = 0 ;
}

void insertElement (int pos ,EntryType e,listType *pl) {
    int i;
    for (i = pl->Size ; i >= pos ; i--)
        pl->entry[i+1] = pl->entry[i];
    pl->entry[pos] = e;
    pl->Size++;
}

void deleteElement (int pos , EntryType *pe , listType *pl) {
    int c ;
    *pe = pl->entry[pos];
    for (c = pos ; c < pl->Size ; c++)
        pl->entry[c] = pl->entry[c+1];
    pl->Size--;
}

int listEmpty(listType *pl) {
    return !pl->Size;
}

int listFull(listType *pl) {
    return pl->Size == MAXLIST ;
}

int listSize(listType *pl) {
    return pl->Size;
}

void destroyList(listType *pl) {
   pl->Size = 0 ;
}

void treaversList(listType *pl , void (*pf) (EntryType e) ) {
    int i ;
    for (i = 0 ; i < pl->Size ; i++)
        (*pf) (pl->entry[i] );
}

void retrieveElement (int pos ,EntryType *pe , listType *pl)  {
        *pe = (*pl).entry[pos];
}

void replaceElement(int pos , EntryType *pe , listType *pl) {
    pl->entry[pos] = *pe ;
}






















