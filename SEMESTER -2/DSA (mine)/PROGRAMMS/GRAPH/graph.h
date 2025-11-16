typedef struct adjlist
{
   int adjver;
   struct adjlist *link;
}NODE;
typedef struct vtable
{
  char name[20];
  int nav;
  NODE *adjptr;
}VERTEX;
int constructGraph(VERTEX G[]);
void displayGraph(VERTEX G[], int n);
void storeGraph(VERTEX G[], int n, char fname[]);
int loadGraph(VERTEX G[], char fname[]);
