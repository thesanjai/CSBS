typedef int element;
typedef struct queue 
{
  int rear;
  int length;
  int front;
  element* s;
}queue;//datatype of stack

void createqueue(int n);
int isFull();
int isEmpty();
void enqueue(element x);
element dequeue();


