#include<bits/stdc++.h>
using namespace std;
bool check(){
int n;
cin>>n;
for(int i=0;i<n;i++){
    if(i&n==0)
    return true;
else
    return false;
}



}
 int main(){
 int t;
  cin>>t;
  for(int i=0;i<t;i++){
    if(check())
        cout<<"Anjali"<<endl;
    else
        cout<<"Vaibhavi"<<endl;
  }
 }
