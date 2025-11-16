#include "bst.h"
#include <stdio.h>
#include <stdlib.h>

NODE* insertBST(NODE *root, int x)
{
   if (root == NULL)
   {
      NODE *T = (NODE *)malloc(sizeof(NODE));
      T->data = x;
      T->lchild = T->rchild = NULL;
      return T;
   }
   else if (root->data > x)
      root->lchild = insertBST(root->lchild, x);
   else if (root->data < x)
      root->rchild = insertBST(root->rchild, x);
   else
      printf("\nDuplicate Element. Cannot insert");
   return root;
}

int searchBST(NODE *root, int x, int count)
{
  count++;
  if (root == NULL)
   {
      return -1;
   }
   else if (root->data > x)
      return searchBST(root->lchild, x, count);
   else if (root->data < x)
      return searchBST(root->rchild, x, count);
   else
      return count;
}

NODE* deleteBST(NODE *root, int x)
{
   if (root == NULL)
      printf("\nElement not present in the BST.");
   else if (root->data > x)
      root->lchild = deleteBST(root->lchild, x);
   else if (root->data < x)
      root->rchild = deleteBST(root->rchild, x);
   else if (root->lchild == NULL)
      return root->rchild;
   else if (root->rchild == NULL)
      return root->lchild;
   else
   {
      int insucc = Minimum(root->rchild);
      root->data = insucc;
      root->rchild = deleteBST(root->rchild, insucc);
   }
   return root;
}

void preorder(NODE* T)
{
   if (T!=NULL)
   {
      printf("%d,  ", T->data);
      preorder(T->lchild);
      preorder(T->rchild);
   }

}
void inorder(NODE* T)
{
   if (T!=NULL)
   {
      inorder(T->lchild);
      printf("%d,  ", T->data);
      inorder(T->rchild);
   }
}
void postorder(NODE *T)
{
   if (T!=NULL)
   {
      postorder(T->lchild);
      postorder(T->rchild);
      printf("%d,  ", T->data); 
   }
}
int Minimum(NODE *root)
{
   NODE *T=root;
   while (T->lchild != NULL)
      T = T->lchild;
   return T->data;
}

int Maximum(NODE *root)
{
   NODE *T=root;
   while (T->rchild != NULL)
      T = T->rchild;
   return T->data;
}

