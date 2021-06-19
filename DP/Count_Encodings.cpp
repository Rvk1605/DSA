#include<iostream>
using namespace std;
int main(){
string s;
cin>>s;
 int arr[s.length()];
 arr[0]=1;
 for(int i=1;i<s.length();i++){
    if(s[i]=='0'&&s[i-1]=='0'){
        arr[i]=0;
    }
    else if(s[i]!='0'&&s[i-1]=='0'){
                arr[i]=arr[i-1];
    }
    else if(s[i]=='0'&&s[i-1]!='0'){
        if(s[i-1]=='1'||s[i-1]=='2'){
            if(i>=2)
                arr[i]=arr[i-2]; //As This IS i-2 so If String length is 2 than it will give out of bound error for checking two digit strings
            else
                arr[i]=1;
        }

        else
            arr[i]=0;//greater than 26
    }
    else{

            if((s[i-1]=='1'||s[i-1]=='2')&&(s[i]=='0'||s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6')){
                arr[i]=arr[i-1];
                if(i>=2)
                arr[i]+=arr[i-2]; //As This IS i-2 so If String length is 2 than it will give out of bound error for checking two digit strings
                else
                    arr[i]+=1;
            }
            else
                arr[i]=arr[i-1];

    }
 }
 cout<<arr[s.length()-1];
}
