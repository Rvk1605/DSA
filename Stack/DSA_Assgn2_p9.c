#include<stdio.h>
#include<stdlib.h>
# define SIZE 100
int top=-1;
int stack[SIZE];
void push(int val)
{
  if(top==SIZE-1)
  {
    printf("\nStack IS FULL\n");
    return;
  }
  else
  {
    stack[++top]=val;
  }
}
int pop()
{
  int val=-1;
  if(top==-1)
  {
    printf("\nStack is Empty\n");
  }
  else
  {
    val=stack[top--];
  }
  return val;
}
int main()
{
  int n,area=0,index,temp;
  printf("\nEnter Size of Array :");
  scanf("%d",&n);
  int a[n];
  printf("Enter data :");
  for(int i=0;i<n;i++)
  scanf("%d",&a[i]);
  for(int i=0;i<n;i++)
  {
    if(top==-1||a[i]>a[stack[top]])
    push(i);
    else
    {
      if(a[i]<a[stack[top]])
      {
        while(stack[top]>a[i])
        {
          index=pop();
          if(top==-1)
          temp=a[index]*i;
          else
          temp=a[i]*(i-stack[top]-1);
          if(temp>area)
          area=temp;
        }
        push(i);
      }
    }
  }
  printf("Area : %d\n",area);
}
