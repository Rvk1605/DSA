#include<iostream>
using namespace std;
int main(){
  int n;
  cin>>n;
  int arr[n];
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  int max=0,smax=0;
  int i=0,j=1,profit=0;
  while(j<n){
    if(arr[j]>arr[i]){
      profit=arr[j]-arr[i];
      if(profit>max){
        smax=max;
        max=profit;
      }
      if(profit>smax&&profit<max){
        smax=profit;
      }
    }
    else{
      if(arr[j]<arr[i])
      i=j;
    }
    j++;
  }
  cout<<smax+max+profit<<endl;
}
