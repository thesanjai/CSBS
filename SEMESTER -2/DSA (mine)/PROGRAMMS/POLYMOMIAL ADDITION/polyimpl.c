#include <stdio.h>
#include <stdlib.h>
#include "poly.h"

POLY createPoly(){
  POLY P;
  int n, i, e; 
  float c; 
  P.first = P.last = NULL;
  printf("\nEnter the number of non-zero terms: ");
  scanf("%d", &n);
  for (i=0; i<n; i++){
     printf("\nEnter the coef and exp of the term %d", i);
     scanf("%f%d",&c, &e);
     insertOrder(&P, c, e);
  }
  return P;
}

void insertOrder(POLY *P, float c, int e){
   NODE *T = (NODE*)malloc(sizeof(NODE));
   T->coef = c;
   T->exp = e;
   T->link = NULL;
   if (P->first == NULL){
      P->first = P->last = T;
      return;
   }
   if (P->first->exp < e){
      T->link = P->first;
      P->first = T;
      return;
   }
   NODE *prev = P->first;
   while (prev->link != NULL && prev->link->exp > e)
        prev = prev->link;
   if (prev->link == NULL){
      prev->link = T;
      P->last = T;
   }
   else {
      T->link = prev->link;
      prev->link = T;
   }
}

void insertAtLast(POLY *P, float c, int e){
   NODE *T = (NODE*)malloc(sizeof(NODE));
   T->coef = c;
   T->exp = e;
   T->link = NULL;
   if (P->last == NULL)
      P->first = P->last = T;
   else {
      P->last->link = T;
      P->last = T;
   }
}

POLY addPoly(POLY P, POLY Q){
   POLY R;
   NODE *t1, *t2;
   R.first = R.last = NULL;
   t1 = P.first;
   t2 = Q.first;
   while (t1 != NULL && t2 != NULL) {
      if (t1->exp > t2->exp){
         insertAtLast(&R, t1->coef, t1->exp);
         t1 = t1->link;
      }
      else if (t1->exp < t2->exp) {
         insertAtLast(&R, t2->coef, t2->exp);
         t2 = t2->link;
      }
      else {
         float c = t1->coef + t2->coef;
         if (c != 0)
            insertAtLast(&R, c, t1->exp);
         t1 = t1->link;
         t2 = t2->link;
      }
   }
   while (t1 != NULL){
      insertAtLast(&R, t1->coef, t1->exp);
      t1 = t1->link;
   }
   while (t2 != NULL){
      insertAtLast(&R, t2->coef, t2->exp);
      t2 = t2->link;
   }
   return R;
}
void displayPoly(POLY P){
   NODE *temp = P.first;
   while (temp != NULL){
        printf("[%5.2f, %d] -> ", temp->coef, temp->exp);
        temp = temp->link;
   }
   printf("\n");
}
void deletePoly(POLY P){
   NODE *T;
   NODE *temp = P.first;
   while (temp != NULL){
        T = temp;
        temp = temp->link;
        free(T);
   }
}
