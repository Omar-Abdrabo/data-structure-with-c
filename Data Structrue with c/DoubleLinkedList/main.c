#include <stdio.h>
#include <stdlib.h>

#include "List.h"

void display (EntryType e) {
    printf("Element Is < %d >\n",e);
}

int main()
{
    int i = 1 ;
    listType l;
    createList(&l);
    EntryType c; int pos;
    while(i==1)
    {
        printf("Enter element OR 0 to EXIT : ");scanf("%d",&c);
        if (c != 0) {
            printf("Enter position to insert Element in(0-Size) :: ");scanf("%d",&pos);
            insertElement(pos, c ,&l);
        }else {break;}
    }
    treaversList(&l,&display);
    while(i == 1)
    {
        printf("Enter position to delete Element in(0-Size) or -1 to EXIT :: ");scanf("%d",&pos);
        if (pos != -1) {
            deleteElement(pos, &c ,&l);
            printf("Element deleted < %d >\n",c);

        }else {break;}
    }
    treaversList(&l,&display);

    return 0;
}
