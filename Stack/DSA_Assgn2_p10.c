#include<stdio.h>
#include<stdlib.h>
void TOH(int n,char beg,char aux,char end)
{
  if(n>=1)
  {
    TOH(n-1,beg,end,aux);
    printf("Disk%d is moved from %c to %c\n",n,beg,end);
    TOH(n-1,aux,beg,end);
  }
}
int main()
{
  int d;
  printf("Enter No. Of disk :");
  scanf("%d",&d);
  char rod1='A',rod2='B',rod3='C';
  TOH(d,rod1,rod2,rod3);
}
