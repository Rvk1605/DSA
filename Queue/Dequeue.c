#include<stdio.h>
#include<stdlib.h>
#define SIZE 10
int Queue[SIZE];
int f=0,r=-1;
void insert_left(int val)
{
  if(r%SIZE==f)
  {
    printf("\nQueue Is Full");
    return;
  }
  else
  {
    r=(r+1)%SIZE;
    Queue[r]=val;
  }
}

void insert_right(int val)
{
  if((f==0&&r==SIZE-1))
  {
    printf("Queue Is Full\n");
  }
  else if(f==-1&&r==-1)
  {
    f=0;r=0;
  }
  else if(f==0)
  {
    f=SIZE-1;
  }
  else
  f=f-1;
  Queue[f]=val;
}

int delete_left()
{
  int val=-999;
  if(f==r)
  {
    printf("Queue is Empty\n");
  }
  else
  {
    val=Queue[++f];
  }
  return val;
}

int main()
{
  int choice,data,val;
  printf("1.Insert at Left");
  printf("\n2.Insert at Right");
  printf("\nDelete At Left");
  printf("\n4.EXIT\n");
  while(1)
  {
    printf("\nEnter Your Choice :");
    scanf("%d",&choice);
    switch(choice)
    {
      case 1:
      printf("Enter data :");
      scanf("%d",&data);
      insert_right(data);
      break;
      case 2:
      printf("Enter data :");
      scanf("%d",&data);
      insert_left(data);
      break;
      case 3:
      val=delete_left();
      if(val!=-999)
      printf("%d IS Popped\n");
      break;
      case 4:
      exit(0);
    }
  }
}
