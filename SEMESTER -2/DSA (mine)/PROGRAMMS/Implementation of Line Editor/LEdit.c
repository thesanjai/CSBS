#include <stdio.h>
#include "Editor.c"
#define MAX_LEN 80
int main()
{
   int op;
   int lcount=0, lno;
   char line[100], filename[25], word[25], rword[25];
   char *t;
   HEAD *head=NULL;
   do
   {
      printf("\n1. New File\n2. Read from file\n3. Save to file\n4. Display Contents");
      printf("\n5. Insert a new line\n6. Find word\n7. Delete a line"); 
      printf("\nEnter your option: ");
      scanf("%d", &op);
      switch(op)
      {
         case 1: getchar();
                 head = createHead();
                 lcount = 0;
         	     do
         	     {
         	         printf("\n%d. ",++lcount);
                         if (gets(line)!= NULL)
                         {
                              if (strcmp(line, "END")==0)
                                 break;
                              Append(head, line);
                         }
         	     }
         	     while (!feof(stdin));
       		     break;
        case 2:  printf("\nEnter filename :  ");
                 scanf("%s", filename);
                 head = Read_From_File(filename);
                 break;
        case 3:  if (head != NULL)
       		     {
       		         printf("\nEnter filename :  ");
                     scanf("%s", filename);
                     Save_To_File(head, filename);
                 }
                 break;
        case 4:  if (head != NULL)
       		     {
       		       printf("\nCurrent contents : \n");
        	       Display(head);
        	     }
        	     break;
        case 5: if (head != NULL)
       		    {
       		       printf("Enter the line number : ");
        	       scanf("%d", &lno);
        	       getchar();
        	       printf("Enter the text to insert : ");
        	       if (gets(line) != NULL)
        	           Insert_At_Loc(head, lno, line);
        	    }
        	    break;
       case 6:  if (head != NULL)
       		    {
       		        printf("Enter the word to search : ");
                    scanf("%s", word);
        	        Find(head, word);
        	    }
        	    break;
       case 7:  if (head != NULL)
       		    {
       		        printf("Enter the line number to delete : ");
                    scanf("%d", &lno);
        	        Delete_At_Loc(head,lno);
        	    }        	
        	    break;    
      }
  }
  while(op <= 7);
  return 0;
}
