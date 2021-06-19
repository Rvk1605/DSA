#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"Enter No. of Intervals :";
    cin>>n;
    int intervals[n][2];
    for(int i=0;i<n;i++){
        for(int j=0;j<2;j++){
            cin>>intervals[i][j];
        }
    }
    int arr[n*2];
    int k=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<2;j++){
            arr[k++]=intervals[i][j];
        }
    }

    for(int i=0;i<n*2-1;i++){
        if(arr[i]>=arr[i+1]){
            arr[i]=-9999;
            arr[i+1]=-9999;
        }
    }
    for(int i=0;i<n*2;i++){
        if(arr[i]!=-9999){
            cout<<arr[i]<<endl;
        }
    }
}

