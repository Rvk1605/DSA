#include<iostream>
using namespace std;
int main(){
    int n;
     cin>>n;
     int arr[n];
     for(int i=0;i<n;i++){
         cin>>arr[i];
     }
     int profit=0,sum=0;
     for(int i=0,j=1;i<n,j<n;){
         if(arr[j]>arr[j-1]){
            profit=arr[j]-arr[i];
            j++;
         }else{
             sum+=profit;
             profit=0;
             i=j;
             j++;
         }
     }
     cout<<sum+profit<<endl;

}
