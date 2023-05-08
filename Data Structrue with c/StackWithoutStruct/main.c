#include <stdio.h>
#include <stdlib.h>

#include "Stack2.h"

int main()
{
    stackType s ;
    int x ;
    creatStack(&s);
    if (stackFull(&s))
        printf("Stack is full \n");
    while (!stackFull(&s)) {
        printf("Enter Value :: ");
        scanf("%d",&x);
        push(x,&s);
    }
    if (stackFull(&s))
        printf("Stack is full \n");

    if (stackEmpty(&s))
        printf("Stack is empty \n");
    while (!stackEmpty(&s)) {
        pop(&x,&s);
        printf("<<  %d  >> IS POPED \n",x);
    }
    if (stackEmpty(&s))
        printf("Stack is empty \n");


    system("pause");

    return 0;
}
