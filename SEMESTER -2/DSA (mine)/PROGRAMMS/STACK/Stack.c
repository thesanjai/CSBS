#include <stdlib.h>
#include <stdio.h>
#include "StackType.h"

static Stack sta;

void createStack(int n){
    sta.S = (Element *)calloc(sizeof(Element),n);
    sta.MAX_SIZE = n;
    sta.top = -1;
}

int isFull(){
    if (sta.top >= sta.MAX_SIZE)
        return 1;
    else
        return 0;
}

int isEmpty(){
    if (sta.top == -1)
        return 1;
    else
        return 0;
}

void push(Element x){
     if (isFull()){
        printf("\nStack is full. Cannot insert");
     }
     else{
        sta.top = sta.top+1;
        sta.S[sta.top] = x;
     }
}

Element pop(){
    if (isEmpty())
       return -1;
    else{
      Element x = sta.S[sta.top];
      sta.top--;
      return x;
    }
}

Element peek(){
    if (isEmpty())
       return -1;
    else
      return sta.S[sta.top];
}

void multipush(char fname[]){
    Element x;
    FILE *fp = fopen(fname, "r");
    while (!feof(fp)){
       fscanf(fp, "%d", &x);
       if (!feof(fp))
           push(x);
    }
    fclose(fp);
}

void multipop(char fname[], int m){
    Element x;
    FILE *fp = fopen(fname, "w");
    int count = 0;
    while (!isEmpty() && count < m){
       x = pop();
       fprintf(fp, "%d ", x);
       count++;
    }
    fclose(fp);
}
