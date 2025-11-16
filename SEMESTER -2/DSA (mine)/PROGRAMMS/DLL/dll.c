#include "dll.h"
#include <stdio.h>
#include <stdlib.h>

DLLNODE* createDLL(){
    DLLNODE *head;
    head = (DLLNODE *)malloc(sizeof(DLLNODE));
    head->data = 0;
    head->prev = head->next = NULL;    // head->next is used to store address of first node. head->prev is used to store the address of last node
    return head;
}    

void insertODLL(DLLNODE *head, int x){
    DLLNODE *T = (DLLNODE *)malloc(sizeof(DLLNODE));
    T->data = x;
    T->prev = T->next = NULL;
    if (head->next == NULL){
       head->prev = head->next = T;
       head->data++;
       return;
    }
    if (head->next->data > x){
       T->next = head->next;
       head->next->prev = T;
       head->next = T;
       head->data++;
       return;
    }
    DLLNODE *p = head->next;
    while (p->next != NULL && p->next->data < x)
        p = p->next;
    if (p->next == NULL){
       T->prev = head->prev;
       head->prev->next = T;
       head->prev = T;  
    }
    else{
       T->next = p->next;
       T->prev = p;
       p->next = T;
       T->next->prev = T;
    }
    head->data++;
}
void deleteODLL(DLLNODE *head, int x){
   DLLNODE *p = head->next;
   while (p != NULL && p->data < x)
       p = p->next;
   if (p == NULL || p->data > x){
      printf("\nElement not found. Cannot delete");
      return;
   }
   if (p->prev != NULL)
      p->prev->next = p->next;
   else
      head->next = p->next;
   if (p->next != NULL)
      p->next->prev = p->prev;
   else
      head->prev = p->prev;
   head->data--;
   free(p);
}

int searchODLL(DLLNODE *head, int x){
   int count = 1;
   DLLNODE *p = head->next;
   while (p != NULL && p->data < x){
       count++;
       p = p->next;
   }
   if (p == NULL || p->data > x)
      return -1;
   else
      return count;   
}

void display_FTOL(DLLNODE *head){
   DLLNODE *p = head->next;
   printf("\nDisplaying elements from first to last\n");
   while (p != NULL){
        printf("%d\t", p->data);
        p = p->next;
   }
}

void display_LTOF(DLLNODE *head){
   DLLNODE *p = head->prev;
   printf("\nDisplaying elements from last to first\n");
   while (p != NULL){
        printf("%d\t", p->data);
        p = p->prev;
   }
}
