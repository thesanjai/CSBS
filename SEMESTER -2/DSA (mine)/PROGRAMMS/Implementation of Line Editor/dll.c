#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dlltype.h"

HEAD *createHead()
{
   HEAD *head = (HEAD *) malloc(sizeof(HEAD));
   head->start = head->end = NULL;
   head->LC = head->TWC = 0;
   return head;
}
void Append(HEAD *head, char line[100])
{
   int i, k, WC=0;
   char word[20];
   LINEHEAD *lh;
   NODE *last;
   NODE *nn;
   lh = (LINEHEAD *)malloc(sizeof(LINEHEAD));
   lh->P = lh->N =NULL;
   lh->first = NULL;
   lh->WC = 0;
   if (head->end == NULL){
      head->start = head->end = lh;   
      lh->P = lh;
      lh->N = lh;
   }
   else
   {
	    lh->P = head->end;
	    lh->N = head->end->N;	
	    head->end->N = lh;
	    head->end = lh;
	    head->start->P = lh;
   }
   
   i=0;
   while (line[i]!='\0'){
   	    k = 0;
        while (!isspace(line[i])) 
        {
        	word[k++]=line[i++];
        	if (line[i]=='\0') break;
		}
		word[k]='\0';
		(lh->WC)++;
		nn = (NODE*)malloc(sizeof(NODE));
		nn->next = nn->prev = NULL;
		strcpy(nn->word,word);
		if (lh->first == NULL)
		{
		   lh->first = nn;
		   nn->prev = nn->next = NULL;
		   last = nn;
		}
		else
		{
			nn->prev = last;
			last->next = nn;
			last = nn;
		}
	    while (isspace(line[i])) i++;
	}
	head->TWC += lh->WC;
	(head->LC)++;
 }

void Insert_At_Loc(HEAD *head, int loc, char line[100])
{
   int len, i, WC=0;
   char word[20];
   LINEHEAD *cur_line;
   NODE *nn, *last=NULL;
   int k;
   LINEHEAD *lh = (LINEHEAD *)malloc(sizeof(LINEHEAD));
   lh->P = lh->N = NULL;
   lh->first = NULL;
   lh->WC = 0;
   i=0;
   while (line[i]!='\0'){
   	    k = 0;
        while (!isspace(line[i])) 
        {
        	word[k++]=line[i++];
        	if (line[i]=='\0') break;
		}
		word[k]='\0';
		(lh->WC)++;
		nn = (NODE*)malloc(sizeof(NODE));
		nn->next = nn->prev = NULL;
		strcpy(nn->word,word);
		if (lh->first == NULL)
		{
		   lh->first = nn;
		   nn->prev = nn->next = NULL;
		   last = nn;
		}
		else
		{
			nn->prev = last;
			last->next = nn;
			last = nn;
		}
	    while (isspace(line[i])) i++;
	}
	if (loc==1){
	    lh->P = head->end;
	    lh->N = head->start;
	    head->start->P = lh;
	    head->end->N = lh;
		head->start = lh;
	}
	else{
  	    cur_line = head->start;
	    k=1;
	    while (k<loc-1 && cur_line->N!=head->start){
	    	cur_line = cur_line->N;
	    	k++;
	    }
	    lh->P = cur_line;
	    lh->N = cur_line->N;
	    cur_line->N->P = lh;
	    cur_line->N = lh;
	    if (head->end == cur_line)
	        head->end = lh;
	}
	head->TWC += lh->WC;
	(head->LC)++;
    return;
}

void Delete_At_Loc(HEAD *head, int loc)
{
   int i=1;
   LINEHEAD *cur_line;
   if (head->start == NULL){
   	 printf("\nEmpty Text.");
   	 return;
   }
   if (head->LC < loc)
   {
       printf("No such line exists in the text.");
       return;      
   }
   cur_line = head->start;
   while (cur_line != head->end && i < loc)
   {
        cur_line = cur_line->N;
        i++;
   }
   if (cur_line->P != head->end)
        cur_line->P->N = cur_line->N;
   else
        head->start = cur_line->N;  	//delete first node
   if (cur_line->N != head->start)
       cur_line->N->P = cur_line->P;
   else
       head->end = cur_line->P;			//delete last node
   head->LC--;
   head->TWC -= cur_line->WC;
   NODE *cur_word = cur_line->first;
   while (cur_word != NULL){
   	 NODE *t = cur_word;
   	 cur_word = cur_word->next;
   	 free(t);
   }
   free(cur_line);
   return;
}
void Find(HEAD *head, char word[])
{
	 int flag = 0, pos;
     LINEHEAD *cur_line;
     NODE *cur_word;
     int i = 1;
     if (head->start == NULL)
     {
         printf("\nEmpty text");
         return;
     }
      
      cur_line = head->start;   
      while (cur_line != head->end)
      {
      	 pos = 0;
         cur_word = cur_line->first;
         while (cur_word != NULL)
         {
         	 pos++;
             if (strcmp(cur_word->word, word) == 0)
             {
             	  flag = 1;
                  printf("\nOccurrence of %s is in Line - %d at position %d", word, i, pos);
             }
             cur_word = cur_word->next;
         }
         cur_line = cur_line->N;
         i++;
     }
     cur_word = head->end->first;
     pos = 0;
     while (cur_word != NULL)
     {
     	pos++;
        if (strcmp(cur_word->word, word) == 0)
        {
        	  flag = 1;
              printf("\nOccurrence of %s is in Line - %d at position %d", word, i, pos);
        }
        cur_word = cur_word->next;
     }
      if (!flag)
      	 printf("\n%s is not present in the text.", word);
}
void Display(HEAD *head)
{
   int i;
   LINEHEAD *lh = head->start;
   i=1;
   while (lh!= head->end){
   	 
     NODE *cur = lh->first;
     printf("\n%d. ", i);
     while (cur != NULL)
     {
        printf("%s ", cur->word);
        cur = cur->next;
     }
     i++;
     lh = lh->N;
   }
   NODE *cur = lh->first;
   printf("\n%d. ", i);
   while (cur != NULL)
   {
      printf("%s ", cur->word);
      cur = cur->next;
   }
   printf("\nNo. of lines = %d \nNo. of words = %d\n", head->LC, head->TWC);
}

