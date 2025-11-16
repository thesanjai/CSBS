#include <stdio.h>
#include <stdlib.h>
#include "AVL.h"

int height(TNODE *t)
{
    if (t == NULL)
	  return 0;
    else
    {
	 int hl = height(t->lchild);
	 int hr = height(t->rchild);
	 t->height = hl >= hr ? hl+1 : hr+1;
	 return t->height;
    }
}

int getBalanceFactor(TNODE *t)
{
    if (t == NULL)
	  return 0;
    else
	  return height(t->lchild) - height(t->rchild);
}

TNODE* AVLinsert(TNODE *root, int x)
{
    if (root == NULL)
    {
	  TNODE *T = (TNODE *) malloc(sizeof(TNODE));
	  T->data = x;
	  T->height = 1;
	  T->lchild = NULL;
	  T->rchild = NULL;
	  return T;
    }
    if (root->data > x)
	 	root->lchild = AVLinsert(root->lchild, x);
    else if (root->data < x)
		root->rchild = AVLinsert(root->rchild, x);
    else
    {
	 printf( "Duplicate keys. Can't Insert\n" );
	 return root;
    }
    root->height = height(root);
    int bf = getBalanceFactor(root);
    if (bf == 2 && root->lchild->data > x)
	    return rightRotate(root);
	else if (bf == 2 && root->lchild->data < x)
    {
	   root->lchild = leftRotate(root->lchild);
	   return rightRotate(root);
    }
    else if (bf == -2 && root->rchild->data < x)
	    return leftRotate(root);
    else if (bf == -2 && root->rchild->data > x)
    {
	  root->rchild = rightRotate(root->rchild);
	  return leftRotate(root);
    }
    return root;
}

void search(TNODE *root, int x)
{
    int count = 0;
    if (root == NULL)
    {
	 printf( "Empty AVL tree.\n");
	 return;
    }
    TNODE *temp=root;
    while (temp != NULL)
    {
	  count++;
	  if (temp->data > x)
	     temp = temp->lchild;
	  else if (temp->data < x)
	     temp = temp->rchild;
	  else
	  {
	     printf( "The element is found after %d comparisons.\n", count );
	     return;
	  }
    }
    printf( "The element is not found.\n");
}

TNODE* AVLdelete(TNODE *root, int x)
{
	if (root == NULL)
	{
		printf("\nElement not found. Cannot delete.\n");
		return NULL;
	}
	else if (root->data > x)
		root->lchild = AVLdelete(root->lchild, x);
	else if (root->data < x)
		root->rchild = AVLdelete(root->rchild, x);
	else if (root->lchild == NULL)
	    return root->rchild;	
	else if (root->rchild == NULL)
	    return root->lchild;
	else
	{
		int insucc = AVLMinimum(root->rchild);
		root->data = insucc;
		root->rchild = AVLdelete(root->rchild, insucc);
	}
	return root;
}

int AVLMinimum(TNODE *root)
{
	TNODE *t = root;
	while (t->lchild != NULL)
	    t = t->lchild;
	return t->data;
}

int AVLMaximum(TNODE *root)
{
	TNODE *t = root;
	while (t->rchild != NULL)
	    t = t->rchild;
	return t->data;
}

TNODE* leftRotate(TNODE *t)
{
       printf( "Left Rotate on : %d\n", t->data);
       TNODE *y = t->rchild;
       t->rchild = y->lchild;
       y->lchild = t;
       t->height = height(t);
       y->height = height(y);
       return y;
}

TNODE* rightRotate(TNODE *t)
{
       printf( "Right Rotate on : %d\n", t->data);
       TNODE *y = t->lchild;
       t->lchild = y->rchild;
       y->rchild = t;
       t->height = height(t);
       y->height = height(y);
       return y;
}

void preorder(TNODE *temp)
{
    if (temp != NULL)
    {
	  printf( "%d ", temp->data);
	  preorder(temp->lchild);
	  preorder(temp->rchild);
    }
}
void inorder(TNODE *temp)
{
    if (temp != NULL)
    {
	  inorder(temp->lchild);
	  printf( "%d ", temp->data);
	  inorder(temp->rchild);
    }
}
void postorder(TNODE *temp)
{
    if (temp != NULL)
    {
	  postorder(temp->lchild);
	  postorder(temp->rchild);
	  printf( "%d ", temp->data);
    }
}

