#include<bits/stdc++.h>
using namespace std;
int main()
{
  string s1,s2,temp;
  int flag;
  cin>>s1>>s2;
  temp=s1+s1;
  flag=temp.find(s2);
  if(flag==-1)
  cout<<"NO"<<endl;
  else
  cout<<"YES"<<endl;
  }
