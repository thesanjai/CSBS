#include "bst.h"
#include <stdio.h>
int main()
{
   NODE *root = NULL;
   int op, x, count;
   do
   {
     printf("\n1. Insert, 2. Delete, 3. Traversal, 4. Search, 5. Minimum, 6. Maximum, 7. Exit\n");
     scanf("%d", &op);
     switch (op)
     {
        case 1: printf("\nEnter element to insert: ");
                scanf("%d", &x);
                root = insertBST(root, x);
                break;
        case 2: printf("\nEnter element to delete: ");
                scanf("%d", &x);
                root = deleteBST(root, x);
                break;
        case 3: printf("\nPreorder Traversal:\n");
                preorder(root);
                printf("\nInorder Traversal:\n");
                inorder(root);
                printf("\nPostorder Traversal:\n");
                postorder(root);
                break;
        case 4: printf("\nEnter element to search: ");
                scanf("%d", &x);
                count = searchBST(root, x, 0);
                if (count != -1)
                    printf("\nNo. of comparisons required = %d\n", count);
                else
                    printf("\nElement not found in the BST\n");
                break;
        case 5: x = Minimum(root);
                printf("\nMinimum = %d", x);
                break;
        case 6:x = Maximum(root);
                printf("\nMaximum = %d", x);
                break;
     }
   }
   while(op < 7);
   return 0;
}
