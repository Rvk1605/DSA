#include<bits/stdc++.h>
using namespace std;
int main()
{
  string s;
  getline(cin,s);
  vector <char> ch;
  for(int i=0;i<s.size()-1;i++)
  {
    for(int j=i+1;j<s.size();j++)
    {
      if(s[i]==s[j])
      for(int k=0;k<ch.size();k++)
      {
        if(ch[k]!=s[i])
        ch.push_back(s[i]);
      }
    }
  }
  for(int i=0;i<ch.size();i++)
  cout<<ch[i];
}
