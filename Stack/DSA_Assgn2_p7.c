#include<stdio.h>
#include<stdlib.h>
#define SIZE 10
int stack[SIZE];
int push(int size,int top,int val)
{
  if(top==size)
  {
    printf("Stack IS Full\n");;
  }
  else
  {
    stack[top++]=val;
  }
  return top;
}

int pop(int top,int min)
{
  int val;
  if(top==min)
  {
    printf("\nStack is Empty\n");
  }
  else;
  {
    val=stack[top--];
    printf("%d is Popped ",val);
  }
  return top;
}

int peek(int top,int min)
{
  if(top==min)
  printf("\nStack IS Empty\n");
  else
  printf("%d\n",stack[top]);
}

int main()
{
  int k,temp=0,choice,data,val,num,min;
  printf("\nEnter k :");
  scanf("%d",&k);
  int top[k];
  for(int i=0;i<k;i++)
  {
    top[i]=temp;
    temp=temp+SIZE/k;
  }
  for(int i=0;i<k;i++)
  printf("%d\n",top[i]);
  printf("\n1.PUSH ");
  printf("\n2.POP");
  printf("\n3.PEEP");
  printf("\n4.EXIT\n");
  while(1)
  {
  printf("\nEnter your choice : ");
  scanf("%d",&choice);
  switch(choice)
  {
    case 1:
    printf("Enter Stack no :");
    scanf("%d",&num);
    if(num>k)
    {
    printf("Satck not Present\n");
    break;
    }
    printf("Enter Data :");
    scanf("%d",&data );
    top[num-1]=push((top[num]-top[num-1]),top[num-1],data);
    break;
    case 2:
    printf("Enter Stack no :");
    scanf("%d",&num);
    if(num>k)
    {
    printf("Satck not Present\n");
    break;
    }
    min=((num-1)*(SIZE/k))-1;
    top[num-1]=pop(min,top[num-1]);
    break;
    case 3:
    printf("Enter Stack NO :");
    scanf("%d",&num);
    if(num>k)
    {
    printf("Stack not Present\n");
    break;
    }
    min=((num-1)*(SIZE/k))-1;
    peek(top[num-1],min);
    case 4:
    exit(0);
  }
}
}
