#include<stdio.h>
#define SIZE 100
int top=-1;
char stack[SIZE];
void push(char c)
{
  if(top==SIZE-1)
    return ;
  else
    stack[++top]=c;
}

char pop()
{
  char val;
  if(top==-1)
    return '\0';
  else
    {
      val=stack[top--];
    }
    return val;
}

int check()
{
  int c=0;
  char s[1000],temp=NULL;
  scanf("%s",s);
  for(int i=0;i<strlen(s);i++)
  {
    if(i==0)
    push(s[i]);
    else
    {
      temp=pop();
      if(temp=='('||temp=='{'||temp=='[')
      {
        c++;
        continue;
      }
      else
      {
      push(temp);
      push(s[i]);
      }
    }
  }
  printf("%d %d\n",c,top);
  if(top==-1)
  return 1;
  else
  return 0;
}

int main()
{a
  int t;
  scanf("%d",&t);
  int a[t];
  for(int i=0;i<t;i++)
  {
    a[i]=check();
  }
  for(int i=0;i<t;i++)
  {
    if(a[i]==1)
    printf("YES\n");
    else
    printf("NO\n");
  }
}
