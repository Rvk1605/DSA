#include<stdio.h>
#include<stdlib.h>
#define SIZE 100
int top1=-1;
int top2=-1;
int stack1[SIZE];
int stack2[SIZE];
void pushA(int val)
{
  if(top1==SIZE-1)
  {
    printf("\nStack Is Full\n");
    return;
  }
  else
  {
    stack1[++top1]=val;
  }
}

void pushB(int val)
{
  if(top2==SIZE-1)
  {
    printf("\nStack Is Full\n");
    return;
  }
  else
  {
    stack2[++top2]=val;
  }
}

int popA()
{
  int val;
  if(top1==-1)
  {
    printf("stack is Empty\n");
    val=-999;
  }
  else
  {
    val=stack1[top1--];
  }
  return val;
}

void Copy()
{
  int val;
  if(top1==-1)
  return;
  else
  {
    val=popA();
    Copy();
    pushA(val);
    pushB(val);
  }
}

void view_stack2()
{
  int val;
  if(top2==-1)
  return;
  val=popB();
  printf("%d\n",val);
  view_stack2();
  pushB(val);
}
void view_stack1()
{
  int val;
  if(top1==-1)
  return;
  val=popA();
  printf("%d\n",val);
  view_stack1();
  pushA(val);
}

int main()
{
  int choice,val,data;
  printf("1.Push in Stack1");
  printf("\n2.Copy From Stack1 to Stack2");
  printf("\n3.View_stack1");
  printf("\n4.View_stack2");
  printf("\n5.EXIT\n");
  while(1)
  {
    printf("\nEnter Your Choice :");
    scanf("%d",&choice);
    switch(choice)
    {
      case 1:
      printf("\nEnter Data :");
      scanf("%d",&data);
      pushA(data);
      break;
      case 2:
      Copy();
      break;
      case 3:
      if(top1==-1)
        printf("\nStack1 Empty\n");
      else
        view_stack1();
      break;
      case 4:
      if(top2==-1)
      printf("\nStack2 Empty\n");
      else
      view_stack2();
      break;
      case 5:
      exit(0);
      default:
      printf("\nInvalid Choice \n");
    }
  }
}
