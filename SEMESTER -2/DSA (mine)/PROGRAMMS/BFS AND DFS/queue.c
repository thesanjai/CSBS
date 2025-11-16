#include "queuetype.h"
#include<stdio.h>
#include<stdlib.h>

struct queue Q;

void createqueue(int n)
{
  Q.s=(element*)calloc(sizeof(element),n);
  Q.length=n;
  Q.rear=Q.front=-1;
}

int isFull()
{
  if(Q.rear>=Q.length)
       return 1;
  else 
       return 0;
}

int isEmpty()
{
   if(Q.rear== -1)
      return 1;
    else
      return 0;
}

void enqueue(element x)
{
  if(isFull()){
     printf("\n queue overflows");
  }
  else{
     Q.rear=Q.rear+1;
     Q.s[Q.rear]=x;
        if(Q.front==-1)
             Q.front=0;
      }
}

element dequeue()
{
   if(isEmpty())
   {
      printf("\n queue underflows");
   }
   else{
        element x=Q.s[Q.front];
       if (Q.front==Q.rear)
           Q.front=Q.rear=-1;
       else
           Q.front=Q.front+1;
       return x;
    }
}
       



 
