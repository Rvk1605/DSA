#include<bits/stdc++.h>
using namespace std;
 int main(){
 int n;
  cin>>n;
  int stair[n];
  for(int i=0;i<n;i++){
    cin>>stair[i];
  }


  int arr[n];
  for(int i=0;i<n;i++){
    arr[i]=0;
  }

  arr[n-1]=0;
  for(int i=n-1;i>=0;i--){
    int m=INT_MAX;
    for(int j=1;j<=stair[i]&&i+j<=n;j++){
        if(stair[i]!=0){
            m=min(arr[j],m);
        }
    }
    if(m!=INT_MAX){
        arr[i]=1+m;
    }
    else
        arr[i]=0;
  }

  cout<<arr[0];
 }
