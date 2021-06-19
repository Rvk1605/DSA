#include<iostream>
using namespace std;
int main(){
    int n;
     cin>>n;
    int denomination[n];
    for(int i=0;i<n;i++){
        cin>>denomination[i];
    }
    int amt;
    cin>>amt;
    int arr[amt+1];
    for(int i=0;i<amt+1;i++){
        arr[i]=0;
    }

    arr[0]=1;
    for(int j=1;j<amt+1;j++){
        for(int i=0;i<n;i++){
            if(j<denomination[i])
            continue;
            arr[j]=arr[j]+arr[j-denomination[i]];

        }
    }
    cout<<arr[amt];
 }
