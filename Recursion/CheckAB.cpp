#include<bits/stdc++.h>
using namespace std;

bool checkAB(char *s){
    if(s[0]==NULL)
        return true;
    if(s[0]=='a'){
        checkAB(s+1);
    }
    else if(s[0]=='b'){
        if(s[1]=='b')
            checkAB(s+2);
        else
            return false;
    }
}

int main(){
char *s=new char[1000];
cin>>s;
if(s[0]=='a'){
    if(checkAB(s))
        cout<<"True"<<endl;
    else
        cout<<"False"<<endl;
}
else
    cout<<"False"<<endl;
}
