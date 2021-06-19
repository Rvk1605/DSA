#include<stdio.h>
#include<stdlib.h>
#define SIZE 1000005
int top=-1;
int stack[SIZE];
int max=0;
void push()
{
    int x;
    scanf("%d",&x);
    if(top==SIZE-1)
        return;
    else
    {
        stack[++top]=x;
    }
}

int pop()
{
    int val;
    if(top==-1)
        val =-999;
    else
    {
        val=stack[top--];
    }
    if(val==max)
    max=-9999;
    return val;
}

void find_max()
{
    int val;
    if(top==-1)
    return;
    else
    {
    val=pop();
    if(val>max)
    max=val;
    find_max();
    push(val);
    }
}

int main()
{
    int choice,n;
    scanf("%d",&n);
    while(n!=0)
    {
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            find_max();
            printf("%d\n",max);
            break;
          }
        n--;
    }
}
