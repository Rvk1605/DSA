#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 100
char stack[SIZE];
int top=-1;
void push(char val)
{
  if(top==SIZE-1)
  {
    printf("\nStack IS Full");
    return;
  }
  else
    stack[++top]=val;
}

char pop()
{
  char val;
  if(top==-1)
  {
    printf("\nStack is Empty\n");
    val='\0';
  }
  else
    val=stack[top++];
  return val;
}
int max(int n,int m)
{
  if(n>m)
  return n;
  else
  return m;
}

int find_length(char *s)
{
  char temp;
  int c=0;
  for(int i=0;i<strlen(s);i++)
  {
    if(i==0||s[i]=='(')
    {
      push(s[i]);
    }
    else
    {
      temp=pop();
      if(top!=-1)
      c=max(c,top+1);
      else
      push(temp);
    }
  }
  return c;
}

int main()
{
  int len;
  char s[100];
  printf("Enter A String :");
  scanf("%s",s);
  len=find_length(s);
  printf("\nLength of Longest Parathesis Substring :%d",len);
}
