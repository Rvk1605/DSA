#include <iostream>
#include<string>
using namespace std;

char arr[]={' ','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
void printEncoding(string str, string asf){
    if(str[0]=='0'){
        return;
    }
    if(str.length()==0){
        cout<<asf<<endl;
        return;
    }
    string s1=str.substr(1);
     printEncoding(s1,asf+arr[str[0]-'0']);

    if(str[0]=='1'&&str.length()>1){
        string s2=str.substr(2);
        printEncoding(s2,asf+arr[(str[0]-'0')*10+(str[1]-'0')]);
    }

    if(str[0]=='2'&&str.length()>1){
        if(str[1]-'0'<=6){
        string s2=str.substr(2);
        printEncoding(s2,asf+arr[(str[0]-'0')*10+(str[1]-'0')]);
        }
    }
}

int main(){
    string str;
    cin>>str;
    printEncoding(str,"");

}
