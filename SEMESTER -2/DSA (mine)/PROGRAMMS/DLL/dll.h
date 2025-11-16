typedef struct dllnode{
   int data;
   struct dllnode *prev;
   struct dllnode *next;
}DLLNODE;

DLLNODE* createDLL();
void insertODLL(DLLNODE *head, int x);
void deleteODLL(DLLNODE *head, int x);
int searchODLL(DLLNODE *head, int x);
void display_FTOL(DLLNODE *head);
void display_LTOF(DLLNODE *head);
