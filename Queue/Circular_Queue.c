#include<stdio.h>
#include<stdlib.h>
struct Queue{
  int data;
  int size;
  int f;
  int r;
  int *arr;
};

struct Queue *Create_Queue(int cap)
{
  struct Queue *n;
  n=(struct Queue*)malloc(sizeof(struct Queue));
  n->f=0;
  n->r=0;
  n->size=cap+1;
  n->arr=(int *)malloc(sizeof(int));
  return n;
}

void enqueue(struct Queue *q,int val)
{
  if((q->r+1)%q->size==q->f)
  {
    printf("\nQueue Is Full\n");
    return;
  }
  else
  {
    q->r=(q->r+1)%q->size;
    q->arr[q->r]=val;
  }
}

int dequeue(struct Queue *q)
{
  int val=-999;
  if(q->r==q->f)
  {
    printf("\nQueue Is Empty\n");
  }
  else
  {
    q->f=(q->f+1)%q->size;
    val=q->arr[q->f];
  }
  return val;
}

int main()
{
  int choice,data,size,val;
  struct Queue *q;
  printf("\nEnter Size :");
  scanf("%d",&size);
  q=Create_Queue(size);
  printf("1.Enqueue");
  printf("\n2.Dequeue");
  printf("\n3.Exit\n");
  while(1)
  {
    printf("\nEnter Your Choice :");
    scanf("%d",&choice);
    switch(choice)
    {
      case 1:
      printf("Enter Data :");
      scanf("%d",&data);
      enqueue(q ,data);
      break;
      case 2:
      val=dequeue(q);
      if(val!=-999)
      printf("%d is POpped\n",val);
      break;
      case 3:
      exit(0);
    }
  }
}
