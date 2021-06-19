#include<stdio.h>
#include<stdlib.h>
#define SIZE 100
int stack[SIZE];
int min=99999999;
int top=-1;
void push(int val)
{
  if(top==SIZE-1)
  {
    printf("Stack Overflow\n");
    return ;
  }
  else
  stack[++top]=val;
}
int pop()
{
  int val;
  if(top==-1)
  {
    printf("\nStack Underflow\n");
    val=-99999;
  }
  else
  val=stack[top--];
  if(val==min)
  min=99999999;
  return val;
}
void find_min()
{
  int val;
  if(top==-1)
  return;
  val=pop();
  if(val<min)
  min=val;
  find_min();
  push(val);
}
int main()
{
  int choice,n,data;
  printf("1.Push");
  printf("\n2.POP");
  printf("\n3.Get_min");
  printf("\n4.EXIT\n");
  while(n!=0)
  {
    printf("Enter your choice :");
    scanf("%d",&choice);
    switch(choice)
    {
      case 1:
      printf("Enter Data :");
      scanf("%d",&data);
      push(data);
      break;
      case 2:
      pop();
      break;
      case 3:
      find_min();
      printf("\nMin Value :%d\n",min);
      break;
      case 4:
      exit(0);
    }
    n--;
  }

}
