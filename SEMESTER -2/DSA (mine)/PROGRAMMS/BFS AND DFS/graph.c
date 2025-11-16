
#include <stdio.h>
#include "graph.h"
#include "queuetype.h"
#include <stdlib.h>

int time;
void displayGraph(VERTEX G[], int n)
{
   int i;
   NODE *temp; 
   printf("\n Name   Visited  Distance  Parent     Adjacent Vertices\n");
   for (i=1; i<=n; i++){
      printf("%s\t", G[i].name);
      printf("%d\t", G[i].visited);
      if (G[i].type == 1)
           printf("%d\t", G[i].m.dist);
      else
           printf("%d\t", G[i].m.dfn);
      printf("%d\t", G[i].parent);
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

void BFS(VERTEX G[], int s, int n)
{
   int i, u, v;
   NODE *temp;
   for (i=1; i<=n; i++)
   {
       G[i].type = 1;
       G[i].visited = 0;
       G[i].parent = -1;
       G[i].m.dist = 9999;
   }
   G[s].visited = 1;
   G[s].m.dist = 0;
   createqueue(n+2);
   enqueue(s);
   while (!isEmpty())
   {
      u = dequeue();
      temp = G[u].adjptr;
      while (temp != NULL)
      {
         v = temp->adjver;
         if (G[v].visited == 0)
         {
            printf("\n %d --> %d", u, v);
            G[v].visited = 1;
            G[v].m.dist = G[u].m.dist + 1;
            G[v].parent = u;
            enqueue(v);
         }
         temp = temp->link;
      }
   }
}
void DFS(VERTEX G[], int n)
{
   int i;
   NODE *temp;
   for (i=1; i<=n; i++)
   {
       G[i].type = 2;
       G[i].visited = 0;
       G[i].parent = -1;
       G[i].m.dfn = 9999;
   }
   time = 0;
   for (i=1; i<=n; i++)
   {
     if (G[i].visited == 0)
     {
        DFS_VISIT(G, i);
     }
   }
   
}
void DFS_VISIT(VERTEX G[], int u)
{
   int v;
   NODE *temp;
   time++;
   G[u].visited = 1;
   G[u].m.dfn = time;
   temp = G[u].adjptr;
   while (temp != NULL)
   {
      v = temp->adjver;
      if (G[v].visited == 0)
      {
         G[v].parent = u;
         printf("\n %d --> %d", u, v);
         DFS_VISIT(G, v);
      }
      temp = temp->link;
   }
}

