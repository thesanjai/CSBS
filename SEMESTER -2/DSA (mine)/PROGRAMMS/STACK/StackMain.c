#include "StackType.h"
#include <stdio.h>

int main(){
   int op, m;
   Element x;
   char fname[25];
   createStack(20);
   do
   {
      printf("\n1-Push, 2-Pop, 3-Peek, 4-Multipush, 5-Multipop, 6-Exit\n");
      scanf("%d", &op);
      switch(op){
         case 1: printf("\nEnter the element to push: ");
                 scanf("%d", &x);
                 push(x);
                 break;
         case 2: x = pop();
                 if (x != -1)
                    printf("\nThe element popped is: %d", x);
                 else
                    printf("\nStack empty. Cannot delete");
                 break;
         case 3: x=peek();
                 if (x != -1)
                    printf("\nThe top most element in stack is: %d", x);
                 else
                    printf("\nStack empty. Cannot retrieve");
                 break;
         case 4: printf("\nEnter the name of file containing elements to push: ");
                 scanf("%s", fname);
                 multipush(fname);
                 break;
         case 5: printf("\nEnter the name of file to pop the elements: ");
                 scanf("%s", fname); 
                 printf("\nEnter the number of elements to pop: ");
                 scanf("%d", &m);
                 multipop(fname, m);
                 break;             
      }
   }while (op < 6);
   return 0;
}
