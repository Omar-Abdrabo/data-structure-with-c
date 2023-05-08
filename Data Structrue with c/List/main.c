#include <stdio.h>
#include <stdlib.h>

#include "List.h"

void display (EntryType e) {
    printf("Element Is < %d >\n",e);
}

int main()
{
    listType l;

    createList(&l);
    EntryType c; int pos;
    while( !listFull(&l))
    {
        printf("Enter element OR 0 to EXIT : ");scanf("%d",&c);
        if (c != 0) {
            printf("Enter position to insert Element in(0-Size) :: ");scanf("%d",&pos);
            insertElement(pos, c ,&l);
        }else {break;}
    }
    printf("Your list is ::\n");
    treaversList(&l,&display);
    printf("List size is : %d\n",listSize(&l));

    EntryType out ;
    while( !listEmpty(&l))
    {
        printf("Enter position to delete Element from(0-Size) OR -1 toEXIT :: ");scanf("%d",&pos);
        if (pos != -1) {
            deleteElement(pos, &out ,&l);
            printf("Deleting done < %d  >\n ",out);
        }else {break;}
    }
    printf("Your list is ::\n");
    treaversList(&l,&display);
    printf("List size is : %d\n",listSize(&l));

    printf("Enter position to retrieve element from ::" ); scanf("%d",&pos);
    retrieveElement(pos,&out,&l);
    printf("Element retrieved < %d >\n",out);
    printf("Your list is ::\n");
    treaversList(&l,&display);
    printf("List size is : %d\n",listSize(&l));

    printf("Enter position to replace element from ::" ); scanf("%d",&pos);
    printf("Enter New Element : ");scanf("%d",&out);
    replaceElement(pos,&out, &l);
    printf("Your list is ::\n");
    treaversList(&l,&display);
    printf("List size is : %d\n",listSize(&l));

    destroyList(&l);
    treaversList(&l,&display);
    printf("List size is : %d\n",listSize(&l));



    return 0;
}

























