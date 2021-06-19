#include<iostream>
using namespace std;
 int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int pivot;
    cin>>pivot;
    int i=0,j=0;
    for(;i<n;){
      if(arr[i]>pivot){
        i++;
      }
      else{
        cout<<"Swapping "<<arr[j]<<" and "<<arr[i]<<endl;
        int temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
        i++;
        j++;
      }
    }
    for(int i=0;i<n;i++){
      cout<<arr[i]<<" ";
    }

 }
