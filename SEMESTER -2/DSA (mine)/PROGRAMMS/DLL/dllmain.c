#include "dll.h"
#include <stdio.h>
int main(){
  int op, x, pos;
  DLLNODE *head;
  head = createDLL();
  do{
    printf("1-Insert, 2-Delete, 3-Search, 4-Display First to Last, 5-Dispplay Last to First, 6-Exit");
    scanf("%d", &op);
    switch(op){
      case 1: printf("\nEnter the element to insert: ");
              scanf("%d", &x);
              insertODLL(head,x);
              break;
      case 2: printf("\nEnter the element to delete: ");
              scanf("%d", &x);
              deleteODLL(head,x);
              break;
      case 3: printf("\nEnter the element to search: ");
              scanf("%d", &x);
              pos = searchODLL(head,x);
              if (pos != -1)
                 printf("\nThe element %d found at position - %d", x, pos);
              else
                 printf("\nThe element %d is not found", x);
              break;
      case 4: display_FTOL(head);
              break;
      case 5: display_LTOF(head);
              break; 
    }
  }while (op < 6);
  return 0;
}
