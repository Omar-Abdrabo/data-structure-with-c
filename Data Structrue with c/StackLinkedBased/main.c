#include <stdio.h>
#include <stdlib.h>

#include "Stack.h"

void display (EntryType e) {
    printf("Entry is :: %c\n", e);
}

int main()
{

    stackType s ;
    EntryType element;

    creatStack(&s);

    if (stackEmpty(&s))
        printf("Stack is EMPTY\n");
    int i = 0;
    while (i < 4)
    {
        printf("Enter value to push :: ");
        scanf("%c",&element);getc(stdin);
        push(element , &s);
        i++;
    }
    traversStack(&s , &display);
    clearStack(&s);
    printf("THE size of stack is ::  %d \n",stackSize(&s) );
    i = 0;
    while (i < 4)
    {
        printf("Enter value to push :: ");
        scanf("%c",&element);getc(stdin);
        push(element , &s);
        i++;
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
