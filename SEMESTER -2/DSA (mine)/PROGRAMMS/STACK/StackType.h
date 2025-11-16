typedef int Element;
typedef struct stack
{
   int MAX_SIZE;
   int top;
   Element* S;
}Stack;
void createStack(int n);
int isFull();
int isEmpty();
void push(Element x);
Element pop();
Element peek();
void multipush(char fname[]);
void multipop(char fname[], int m);
