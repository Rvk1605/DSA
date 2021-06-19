#include<iostream>
using namespace std;

int quickSelect(int arr[],int lo,int high,int k){
  if(lo>=high){
    return -1;
  }
    int pivot=arr[high];
    cout<<"pivot -> "<<pivot<<endl;
    int i=0,j=0;
    while(i<=high){
        if(arr[i]>pivot){
            i++;
        }
        else{
            cout<<"Swapping "<<arr[i]<<" and "<<arr[j]<<endl;
            int temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
            i++;
            j++;
        }
    }
    int pivot_index;
    for(int i=lo;i<=high;i++){
        if(arr[i]==pivot){
        pivot_index=i;
        break;
        }
    }

    cout<<"pivot index -> "<<pivot_index<<endl;
    if(pivot_index==k){
        return arr[pivot_index];
    }
    else if(pivot_index<k){
        quickSelect(arr,pivot_index+1,high,k);
    }
    else{
        quickSelect(arr,lo,pivot_index-1,k);
    }
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int k;
    cin>>k;
    int ans=quickSelect(arr,0,n-1,k-1);
    cout<<ans<<endl;
}
