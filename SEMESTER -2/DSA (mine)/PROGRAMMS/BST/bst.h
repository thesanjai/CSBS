typedef struct treenode{
    int data;
    struct treenode *lchild;
    struct treenode *rchild;
}NODE;

NODE* insertBST(NODE *root, int x);
int searchBST(NODE *root, int x, int count);
NODE* deleteBST(NODE *root, int x);
void preorder(NODE* T);
void inorder(NODE* T);
void postorder(NODE *T);
int Minimum(NODE *root);
int Maximum(NODE *root);
