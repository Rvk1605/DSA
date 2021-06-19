#include<stdio.h>
#include<stdlib.h>
#define SIZE 100
int f=-1;int r=-1;
int Queue[SIZE];
void enqueue(int val)
{
  if(r==SIZE-1)
  {
    printf("Queue is Full\n");
    return;
  }
  else
  {
    Queue[++r]=val;
  }
}

int dequeue()
{
  int val;
  if(r==-1)
  {
    printf("\nQueue is Empty\n");
    val=-9999;
  }
  else
  {
    val=Queue[++f];
  }
  return val;
}
void display()
{
  for(int i=0;i<=r;i++)
  printf("%d\n",Queue[i]);
}
void reverse()
{
  int val;
  if(f==r)
  {f=-1;
    r=-1;
  return;
}
  else
  {
    val=dequeue();
    reverse();
    enqueue(val);
  }
}
int main()
{
  int choice,data,val;
  printf("1.enqueue");
  printf("\n2.Dequeue");
  printf("\n3.Reverse");
  printf("\n4.Display");
  printf("\n5.Exit");
  while(1)
  {
    printf("\nEnter your choice :");
    scanf("%d",&choice);
    switch(choice)
    {
      case 1:
      printf("\nEnter Data :");
      scanf("%d",&data);
      enqueue(data);
      break;
      case 2:
      val=dequeue();
      if(val!=-999)
      printf("%d is Popped\n",val);
      break;
      case 3:
      reverse();
      break;
      case 4:
      display();
      break;
      case 5:
      exit(0);
    }
  }
}
