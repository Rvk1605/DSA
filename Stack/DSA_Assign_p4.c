#include<stdio.h>
#include<stdlib.h>
struct node
{
  int f;
  int r;
  int size;
  int *arr;
};
struct arraystack
{
  int top;
  int size;
  int *arr;
};

struct arraystack* Create_stack(int cap)
{
  struct arraystack *n;
  n=(struct arraystack*)malloc(sizeof(struct arraystack));
  n->top=-1;
  n->size=cap;
  n->arr=(int *)malloc(sizeof(int));
  return n;
}
struct node* Create_Queue(int cap)
{
  struct node *n;
  n=(struct node *)malloc(sizeof(struct node));
  n->f=-1;
  n->r=-1;
  n->size=cap;
  n->arr=(int*)malloc(n->size*(sizeof(int)));
  return n;
}
void enqueue(struct node *Queue,int val)
{
    if(Queue->r==Queue->size-1)
    {
    printf("\nQueue is Full\n");
    return;
   }
   else
   {
     if(Queue->f==-1)
     Queue->f=0;
     Queue->arr[++Queue->r]=val;
   }
}
int dequeue(struct node *Queue)
{
  int val;
  if(Queue->r==-1||Queue->f>Queue->r)
  {
    printf("\nQueue is Empty\n");
    val=-999;
  }
  else
  {
    val=Queue->arr[Queue->f++];
  }
  return val;
}
void push(struct arraystack *stack,int val)
{
  if(stack->top==stack->size-1)
  {
    printf("\nStack Is Full");
    return;
  }
  else
  {
    stack->arr[++stack->top]=val;
  }
}
int pop(struct arraystack *stack)
{
  int val;
  if(stack->top==-1)
  {
    printf("\nStack is Empty");
    val=-999;
  }
  else
  {
    val=stack->arr[stack->top--];
  }
  return val;
}

struct node* reverse(struct node *Queue,int k)
{
int val,i;
  i=k;
  struct node *new;
  new=Create_Queue(Queue->size);
  struct arraystack *stack;
  stack=Create_stack(k);
  while(i!=0)
  {
    val=dequeue(Queue);
    push(stack,val);
    i--;
  }
  i=k;
  while(i!=0)
  {
    val=pop(stack);
    enqueue(new,val);
    i--;
  }
  while(Queue->f<=Queue->r)
  {
    enqueue(new,dequeue(Queue));
  }
  return new;
}

int main()
{
  int size ;
  struct node *Queue;
  printf("Enter Size of Queue :");
  scanf("%d",&size);
  Queue=Create_Queue(size);
  int k,choice,data,val;
  printf("1.enqueue");
  printf("\n2.Dequeue");
  printf("\n3.Reverse");
  printf("\nEXIT\n");
  while(1)
  {
  printf("\nEnter your choice :");
  scanf("%d",&choice );
  switch(choice)
  {
    case 1:
    printf("Enter Data :");
    scanf("%d",&data);
    enqueue(Queue,data);
    break;
    case 2:
    val=dequeue(Queue);
    if(val!=-999)
    printf("%d is Popped\n",val);
    break;
    case 3:
    printf("Enter K :");
    scanf("%d",&k);
    Queue=reverse(Queue,k);
    break;
    case 4:
    exit(0);
  }
}
}
