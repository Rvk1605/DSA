#include<bits/stdc++.h>
using namespace std;
int find_subsequence_length(int *arr, int n){
    int output[n];
    output[0]=1;
    for(int i=0;i<n;i++){
        output[i]=1;
        for(int j=i-1;j>=0;j--){
            if(arr[j]>arr[i])
                continue;
            int ans=output[j]+1;
            if(ans>output[i])
                output[i]=ans;
        }
    }
    int max_sequence=0;
    for(int i=0;i<n;i++){
        if(output[i]>max_sequence)
            max_sequence=output[i];
    }
return max_sequence;

    }
 int main(){
    int n;
     cin>>n;
     int a[n];
     for(int i=0;i<n;i++){
        cin>>a[i];
     }
     cout<<find_subsequence_length(a,n)<<endl;
 }
