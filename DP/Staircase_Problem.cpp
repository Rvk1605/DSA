#include<iostream>
using namespace std;
int find_ans(int *arr,int n){
if(n==0||n==1)
    return 1;
if(n==2)
    return 2;
if(arr[n-1]>0)
    return arr[n];
int ans=find_ans(arr,n-1)+find_ans(arr,n-2)+find_ans(arr,n-3);
if(arr[n]==0)
arr[n]=ans;
return ans;
}

int main(){
int n;
 cin>>n;
 int a[n];
 for(int i=0;i<n;i++){
    a[i]=0;
 }
 int ans=find_ans(a,n);
 cout<<ans<<endl;
}
