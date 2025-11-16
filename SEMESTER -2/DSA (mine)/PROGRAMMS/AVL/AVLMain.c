#include <stdio.h>
#include "AVLTREE.c"
int main()
{
  TNODE *root= NULL;
  int d, op;
  do
  {
    printf( "1. Insert Element \n2. Search Element \n3. Traverse\n4. Delete Element\n5. Minimum\n6. Maximum\n7.Exit\n");
    scanf("%d", &op);
    switch (op)
    {
      case 1: {
		 printf( "Enter element to insert ");
		 scanf("%d", &d);
		 root = AVLinsert(root, d);
		 break;
	  }
      case 2: {
		printf( "Enter element to search ");
		scanf("%d", &d);
		search(root, d);
		break;
	  }
	  
      case 3: {
		printf( "Preorder : ");
		preorder(root);
		printf("\nInorder : ");
		inorder(root);
		printf( "\nPostorder : ");
		postorder(root);
		printf("\n");
		break;
	  }
	  case 4: {
		printf( "Enter element to delete ");
		scanf("%d", &d);
		AVLdelete(root, d);
		break;
	  }
	  case 5: {
	  	d = AVLMinimum(root);
	  	printf("\nMinimum Element is %d.\n", d);
		break;
	  }
	  case 6: {
	  	d = AVLMaximum(root);
	  	printf("\nMaximum Element is %d.\n", d);
		break;
	  }
    }
  }
  while (op < 7);
}
