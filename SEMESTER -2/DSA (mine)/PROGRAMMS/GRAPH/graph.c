
#include <stdio.h>
#include "graph.h"
#include <stdlib.h>

int constructGraph(VERTEX G[])
{
   int n, m, i, j, av;
   printf("\nEnter number of vertices: ");
   scanf("%d", &n);
   for (i=1; i<=n; i++){
      printf("\nEnter the name of the vertex: ");
      scanf("%s", G[i].name);
      printf("\nNo. of adjacent vertices of %s: ", G[i].name);
      scanf("%d", &G[i].nav);
      G[i].adjptr = NULL;
      NODE *T, *last;
      last = NULL;
      for (j=1; j<=G[i].nav; j++){
        printf("\nEnter the index of adjacent vertex - %d ", j);
        scanf("%d", &av);
        T = (NODE*) malloc(sizeof(NODE));
        T->adjver = av;
        T->link = NULL;
        if (last == NULL)
           G[i].adjptr = T;
        else
           last->link = T;
        last = T;
      }
   }   
   return n;
}
void displayGraph(VERTEX G[], int n)
{
   int i;
   NODE *temp; 
   printf("\n Name        Adjacent Vertices\n");
   for (i=1; i<=n; i++){
      printf("%s ", G[i].name);
      temp = G[i].adjptr;
      while (temp != NULL)
      {
         printf("--> %d", temp->adjver);
         temp = temp->link;
      }   
      printf("\n");
   }
   printf("\n--------------------------\n");
}

void storeGraph(VERTEX G[], int n, char fname[])
{
   int i;
   NODE *temp; 
   FILE *fp;
   fp = fopen(fname, "w");
   fprintf(fp, "%d\n", n);
   for (i=1; i<=n; i++){
      fprintf(fp, "%s ", G[i].name);
      fprintf(fp, "%d ", G[i].nav);
      temp = G[i].adjptr;
      while (temp != NULL)
      {
         fprintf(fp, " %d", temp->adjver);
         temp = temp->link;
      }   
      fprintf(fp,"\n");
   }
   fclose(fp);
}

int loadGraph(VERTEX G[], char fname[])
{
   int n, m, i, j, av;
   FILE *fp;
   fp = fopen(fname, "r");
   fscanf(fp, "%d", &n);
   for (i=1; i<=n; i++){
      fscanf(fp, "%s", G[i].name);
      fscanf(fp, "%d", &G[i].nav);
      G[i].adjptr = NULL;
      NODE *T, *last;
      last = NULL;
      for (j=1; j<=G[i].nav; j++){
        fscanf(fp, "%d", &av);
        T = (NODE*) malloc(sizeof(NODE));
        T->adjver = av;
        T->link = NULL;
        if (last == NULL)
           G[i].adjptr = T;
        else
           last->link = T;
        last = T;
      }
   }
   fclose(fp);   
   return n;
}

