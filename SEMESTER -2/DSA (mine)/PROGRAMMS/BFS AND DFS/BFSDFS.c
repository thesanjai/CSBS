#include <stdio.h>
#include "graph.h"
#include <stdlib.h>

int main()
{
   VERTEX G[20];
   int n,op;
   do{
   printf("\n1-Load graph, 2-BFS, 3-DFS, 4-display graph, 5-Exit ");
   scanf("%d",&op);
   switch(op){
      case 1:n=loadGraph(G,"graph.txt");
             break;
      case 2:BFS(G, 1, n);
             break;
      case 3:DFS(G, n);
             break;
      case 4:displayGraph(G,n);
             break;
   }
   }while (op < 5);
   return 0;
}
