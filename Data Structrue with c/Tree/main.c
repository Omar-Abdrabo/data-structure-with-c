#include <stdio.h>
#include <stdlib.h>
#include "Tree.h"

void display (EntryType e) {
    printf("Element Is < %d >\n",e.key);
}

int main()
{
    Tree t;
    Tree2 t2;
    EntryType e;
    KeyType k ;

    creatTree(&t);

    if (treeEmpty(&t))
        printf("Tree Empty\n");
    int i = 1;
    while (i) {
        //printf("Enter the info :: ");scanf("%d",&e.info);
        printf("Enter the key :: ");scanf("%d",&e.key);
        insertTreeItr(&t,&e);
        printf("0 to exit 1 to insert  itr ::");scanf("%d",&i);
    }
    i=1;
    while (i) {
        //printf("Enter the info :: ");scanf("%d",&e.info);
        printf("Enter the key :: ");scanf("%d",&e.key);
        insertTreeRec(&t,&e);
        printf("0 to exit 1 to insert rec ::");scanf("%d",&i);
    }

    printf("The size of the tree is :: %d\n",treeSizeRec(&t));
    inOrderRec(&t,&display);
    printf("Enter the key to search for rec : ");scanf("%d",&k);
    if( findElementRec(&t,&e,k))
        printf("Element found\n info is %d  \t key is %d \n",e.info,e.key);
    else
        printf("Element not found \n ");

    printf("Enter the key to search for itr : ");scanf("%d",&k);
    if( findElementItr(&t,&e,k))
        printf("Element found\n info is %d  \t key is %d \n",e.info,e.key);
    else
        printf("Element not found \n ");

    printf("Enter the key to delete for itr : ");scanf("%d",&k);
    if(deleteElementItr(&t,k))
        printf("Element deleted \n");
    else
        printf("Element not deleted \n");

    printf("Enter the key to delete for itr : ");scanf("%d",&k);
    if(deleteElementItr(&t,k))
        printf("Element deleted \n");
    else
        printf("Element not deleted \n");

    printf("The size of the tree is :: %d\n",treeSizeRec(&t));
    inOrderRec(&t,&display);

    clearTree(&t);
    if (treeEmpty(&t))
        printf("Tree Empty\n");

    return 0;
}
