#include<stdio.h>
#include<stdlib.h>
struct arraystack
{
  int top;
  int *arr;
  int size;
};
struct arraystack* Create_stack()
{
  struct arraystack *n;
  n=(struct arraystack*)malloc(sizeof(struct arraystack));
  n->top=-1;
  n->size=10;
  n->arr=(int *)malloc(sizeof(int));
  return n;
}

void push(struct arraystack *stack ,int val)
{
  if(stack->top==stack->size-1)
  {
    printf("Stack IS Full\n");
    return;
  }
  else
  {
    stack->arr[++stack->top]=val;
  }
}

int pop(struct arraystack *stack)
{
  int val=-999;
  if(stack->top==-1)
  {
    printf("\nStack Is Empty\n");
  }
  else
  {
    val=stack->arr[stack->top--];
  }
  return val;
}

int main()
{
  struct arraystack *stack;
  stack=Create_stack();
  int size ;
  printf("Enter Size of array :");
  scanf("%d",&size);
  int a[size];
  for(int i=0;i<size;i++)
  scanf("%d",&a[i]);
  for(int i=0;i<size;i++)
  {
    for(int j=i+1;i<size;i++)
    {
      if(a[i]>stack->arr[stack->top]);
      {
        while(stack->arr[stack->top]<a[i])
        {
        printf("%d is NGE of %d\n",a[i],stack->arr[stack->top]);
        pop(stack);
        }
        push(stack,a[i]);
      }
    }
  }
  if(stack->top!=-1)
  {
    int val;
    while(stack->top!=-1)
    {
      val=pop(stack);
      printf("-1 is NGE of %d\n",val);
    }
  }
}
