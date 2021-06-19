#include<iostream>
#define SIZE 1000
using namespace std;
int top=-1;
int stack[SIZE];
void check()
{
  int n,m,x,c1=0,c2=0,sum1=0,sum2=0;
  cin>>n>>m>>x;
  int a[n],b[m];
  for(int i=0;i<n;i++)
  {
    cin>>a[i];
    sum1=sum1+a[i];
    if(sum1<x)
      c1++;
  }
  for(int i=0;i<m;i++)
  {
    cin>>b[i];
    sum2=sum2+b[i];
    if(sum2<x)
    c2++;

  }
  cout<<c1+c2;
}

int main()
{
  int t;
  cin>>t;
  for(int i=0;i<t;i++)
  check();
}
