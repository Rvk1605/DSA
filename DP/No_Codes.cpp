#include<iostream>
using namespace std;

int check(int *arr,int size){
if(size==1)
   return 1;
if(size==0){
    return 1;
}
int output=check(arr,size-1);
if(arr[size-2]*10+arr[size-1]<=26){
    output+=check(arr,size-2);
}
return output;
}
 int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
   cout<< check(a,n);
 }
