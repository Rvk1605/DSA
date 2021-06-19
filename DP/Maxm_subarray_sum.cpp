#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int best=-99999,sum=0;
    for(int i=0;i<n;i++){
        if(sum<0){
            sum=arr[i];
        }
        else{
            sum+=arr[i];
        }
        if(sum>best){
            best=sum;
        }
    }
    cout<<best;
}
