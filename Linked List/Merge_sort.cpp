#include<iostream>
using namespace std;
int * mergeSort(int arr[],int low,int high){
    if(low==high){
        return arr;
    }
   int mid=(low+high)/2;

    int *aar1 = mergeSort(arr,0,mid);
    int *arr2 = mergeSort(arr,mid+1,high);
    //Merge arr1 and arr2

    int ans[high-low];
    int j=0,k=0,i=0;
    while(j<mid&&k<high){
        if(arr1[j]<arr2[k]){
            ans[i]=arr1[j];
            j++;
        }else{
            ans[i]=arr2[k];
            k++;
        }
        i++;
    }
    if(j!=mid){
        while(j!=mid){
            ans[i]=arr1[j];
            j++;
            i++;
        }
    }else if(k!=high){
        while(k!high){
            ans[i]=arr2[k];
            i++;
            k++;
        }
    }
    return ans;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    mergeSort(arr,0,n);
}
