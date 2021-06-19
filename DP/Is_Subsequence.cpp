#include<bits/stdc++.h>
using namespace std;
int main(){
string s1,s2;
cin>>s1;
cin>>s2;
int i=0,j=0,c=0;
for(;i<s2.length();i++){
    if(s1[j]==s2[i]){
        j++;
        c++;
    }
}
if(c==s1.length())
    cout<<true;
else
    cout<<false;
}
