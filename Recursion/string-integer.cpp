#include <bits/stdc++.h>
using namespace std;
int getInt(string s){
  if(s.length()==1){
    return s[0]-'0';
  }
  int temp=s[0]-'0';
  string s1=s.substr(1);
  int ans=getInt(s1);
  int l=s1.size();
  cout<<"temp:"<<temp<<endl;
  cout<<"Ans :"<<ans<<endl;
  cout<<"Length :"<<l<<endl;
  int res=temp*pow(10,l)+ans;
  cout<<"Res :"<<res<<endl;
  return res;
}

int main(){
  string s;
  cin>>s;
  cout<<getInt(s);
}
