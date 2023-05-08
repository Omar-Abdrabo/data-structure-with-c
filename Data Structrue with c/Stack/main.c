#include <stdio.h>
#include <stdlib.h>

#include "Stack.h"

int main()
{

    stackType s ;
    EntryType element;

    creatStack(&s);

    if (stackEmpty(&s))
        printf("Stack is EMPTY\n");
    while (!stackFull(&s))
    {
        printf("Enter value to push :: ");
        scanf("%c",&element);getc(stdin);
        push(element , &s);

    }
     if (stackFull(&s))
        printf("Stack is FULL\n");

    printf("THE size of stack is ::  %d \n",stackSize(&s) );

    while (!stackEmpty(&s))
    {
        pop(&element , &s);
        printf(" <<  %c  >>  IS POPED\n",element);
    }

    printf("THE size of stack is ::  %d \n",stackSize(&s) );

    return 0;
}
