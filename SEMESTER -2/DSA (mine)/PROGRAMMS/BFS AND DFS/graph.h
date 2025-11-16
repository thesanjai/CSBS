typedef struct adjlist
{
   int adjver;
   struct adjlist *link;
}NODE;
typedef struct vtable
{
  char name[20];
  int nav;
  int visited;
  int type;
  union {
     int dist;
     int dfn;
  }m;
  int parent;
  NODE *adjptr;
}VERTEX;

void displayGraph(VERTEX G[], int n);
int loadGraph(VERTEX G[], char fname[]);
void BFS(VERTEX G[], int s, int n);
void DFS(VERTEX G[], int n);
void DFS_VISIT(VERTEX G[], int u);
