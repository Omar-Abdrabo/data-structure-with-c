#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int main()
{
        int i = 0;
        queueType q;
        creatQueue(&q);

        EntryType x  ;
        while ( !queueFull(&q) ) {
            printf("Enter value to add OR 0 to Exit: ");scanf("%d",&x);
            if (x!=0){
                append(x,&q);
                i++;
            }else {break;}

        }

        printf("Size of queue IS : %d\n",queueSize(&q));

        EntryType out ;
        int c = 0;
        while (c < i){
            remov(&out , &q);
            printf("Element removed < %d > \n",out);
            c++;
        }

        if (queueEmpty(&q))
            printf("Queue Is empty\n");

       while ( !queueFull(&q) ) {
            printf("Enter value to add OR 0 to Exit: ");scanf("%d",&x);
            if (x!=0){
                append(x,&q);
                i++;
            }else {break;}

        }

        printf("Size of queue IS : %d\n",queueSize(&q));
        clearQueue(&q);
        if (queueEmpty(&q))
            printf("Queue Is empty\n");
          printf("Size of queue IS : %d\n",queueSize(&q));






    return 0;
}
