#include<Iostream>
using namespace std;
int main()
{
  string s;int flag=0;
  cin>>s;
  for(int i=0;i<s.size()/2;i++)
  {
    if(s[i]!=s[s.size()-1-i])
    {
      flag=1;
      break;
    }
  }
  if(flag==1)
  cout<<"Not Pallindrome\n";
  else
  cout<<"Pallindrome";
}
