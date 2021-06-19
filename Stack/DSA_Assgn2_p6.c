#include<stdio.h>
#include<stdlib.h>
#define SIZE 10
int f1=-1,f2=SIZE;
int r1=-1,r2=SIZE;
int Queue[SIZE];
void enqueueA(int val)
{
  if(r1==SIZE-1||r1+1==r2)
  {
    printf("\nQueue is Full");
    return;
  }
  else
  {
    if(f1==-1)
    f1=0;
    Queue[++r1]=val;
  }
}

void enqueueB(int val)
{
  if(r2-1==r1||r2==0)
  {
    printf("\nQueue is Full");
    return;
  }
  else
  {
    if(f2==SIZE);
    f2=SIZE-1;
    Queue[--r2]=val;
  }
}

int dequeueA()
{
  int val;
  if(f1>r1)
  {
    printf("Queue is Empty\n");
    val=-999;
  }
  else
  {
    val=Queue[++f1];
  }
  return val;
}

int dequeueB()
{
  int val;
  if(f2<r2)
  {
    printf("\nQueue is Empty\n");
    val=-999;
  }
  else
  {
    val=Queue[--f2];
  }
  return val;
}

int main()
{
  int choice,data,val;
  printf("1.Enqueue in A");
  printf("\n2.Enqueue in B");
  printf("\n3.Dequeue from A");
  printf("\n4.Dequeue from B");
  printf("\n5.EXIT");
  while(1)
  {
    printf("\nEnter Your choice :");
    scanf("%d",&choice);
    switch(choice)
    {
      case 1:
      printf("\nEnter Data :");
      scanf("%d",&data);
      enqueueA(data);
      break;
      case 2:
      printf("\nEnter Data:");
      scanf("%d",&data);
      enqueueB(data);
      break;
      case 3:
      val=dequeueA();
      if(val!=-999)
      printf("%d",val);
      break;
      case 4:
      val=dequeueB();
      if(val!=-999)
      printf("%d",val);
      break;
      case 5:
      break;
    }
  }
}
