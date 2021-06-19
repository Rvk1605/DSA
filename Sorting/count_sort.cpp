#include <iostream>
using namespace std;
int main(){
  int n,min=9999,max=-1;
  cin>>n;
  int arr[n];
  for(int i=0;i<n;i++){
    cin>>arr[i];
    if(arr[i]<min){
      min=arr[i];
    }
    if(arr[i]>max){
      max=arr[i];
    }
  }
  int range=max-min+1;
  //finding frequency
  int freqarr[range];
  for(int i=0;i<range;i++){
    freqarr[i]=0;
  }

  for(int i=0;i<n;i++){
    int idx=arr[i]-min;
    freqarr[idx]++;
  }


  //prefix sum array

  for(int i=1;i<range;i++){
    freqarr[i]+=freqarr[i-1];
  }

  //finding answer in another array

  int ans[n];
  for(int i=n-1;i>=0;i--){
    int idx=freqarr[arr[i]-min]-1;
    ans[idx]=arr[i];
    freqarr[arr[i]-min]--;
  }



  for(int i=0;i<n;i++){
    cout<<ans[i]<<" ";
  }

}
