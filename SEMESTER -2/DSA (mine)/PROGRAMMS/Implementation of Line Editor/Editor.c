#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Editor.h"
#include "dll.c"
#define MAX_LEN 80

HEAD *Read_From_File(char filename[])
{
   int i;
   char line[100];
   FILE *fp = fopen(filename, "r");
   HEAD *head = createHead();
   do
   {
      fgets(line, MAX_LEN, fp);
      if (!feof(fp))
         Append(head, line);
   }
   while (!feof(fp)); 
   fclose(fp);
   return head;
}

void Save_To_File(HEAD *head, char filename[])
{
   int i;
   FILE *fp = fopen(filename, "w");
   LINEHEAD *cur = head->start;
   while (cur != head->end)
   {
   	  NODE *cur_word = cur->first;
   	  while (cur_word != NULL){
		 fprintf(fp, "%s ", cur_word->word);
		 cur_word = cur_word->next;
      }
      cur = cur->N;
      fprintf(fp, "\n");
   }
   NODE *cur_word = cur->first;
   while (cur_word != NULL){
      fprintf(fp, "%s ", cur_word->word);
      cur_word = cur_word->next;
   }
   fprintf(fp,"\n");
   fclose(fp);
}

