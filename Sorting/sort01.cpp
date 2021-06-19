#include<iostream>
using namespace std;
int main(int argc, char const *argv[]) {
  int n;
  cin >> n;
  int arr[n];
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  int i=0,j=0;
  while(i<n){
    if(arr[i]>0){
      i++;
    }
    else{
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
  return 0;
}
