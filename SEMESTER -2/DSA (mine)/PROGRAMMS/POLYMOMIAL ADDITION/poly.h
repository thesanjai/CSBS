typedef struct node{
   float coef;
   int exp;
   struct node *link;
}NODE;
typedef struct {
   NODE *first;
   NODE *last;
}POLY;
POLY createPoly();
void insertOrder(POLY *P, float c, int e);
void insertAtLast(POLY *P, float c, int e);
POLY addPoly(POLY P, POLY Q);
void displayPoly(POLY P);
void deletePoly(POLY P);
