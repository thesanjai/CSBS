#include <stdio.h>
#include "graph.h"
int main(){
   VERTEX G[20];
   int n, op;
   do{
      printf("\n1-Construct Graph 2-Display Graph, 3-Store Graph, 4-Load Graph");
      scanf("%d", &op);
      switch (op){
          case 1: n = constructGraph(G);
                  break;
          case 2: displayGraph(G, n);
                  break;
          case 3: storeGraph(G,n, "graph.txt");
                  break;
          case 4: n = loadGraph(G, "graph.txt");
                  break;
      }
   }while (op < 5);
   return 0;
}

