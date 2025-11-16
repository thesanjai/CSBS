#include <stdio.h>
typedef struct node
{
   int data;
   int height;
   struct node *lchild;
   struct node *rchild;
}TNODE;

int height(TNODE *t);
int getBalanceFactor(TNODE *t);
TNODE* AVLinsert(TNODE *t, int x);
TNODE* AVLdelete(TNODE *t, int x);
void search(TNODE* temp, int x);
TNODE* leftRotate(TNODE *t);
TNODE* rightRotate(TNODE *t);
void preorder(TNODE *t);
void inorder(TNODE *t);
void postorder(TNODE *t);
int AVLMinimum(TNODE *root);
int AVLMaximum(TNODE *root);
