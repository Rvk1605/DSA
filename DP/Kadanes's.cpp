#include<iostream>
using namespace std;
 int main(){
 int n;
  cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int sum,max=arr[0];
    for(int i=0;i<n;i++){
            sum=arr[i];
        for(int j=i+1;j<n;j++){
            sum=sum+arr[j];
            if(sum>max)
                max=sum;
        }
    }
    cout<<max;
 }
