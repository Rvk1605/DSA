#include<iostream>
using namespace std;
 int main(){
 int n;
  cin>>n;
  int zero[n+1];
  int one[n+1];
  zero[0]=0;
  one[0]=0;
  zero[1]=1;
  one[1]=1;
  for(int i=2;i<n+1;i++)
  {
      zero[i]=one[i-1];
      one[i]=zero[i-1]+one[i-1];
  }
  cout<<one[n]+zero[n];

 }
