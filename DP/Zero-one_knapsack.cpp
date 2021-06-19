#include<iostream>
using namespace std;
int main(){
int n;
 cin>>n;
 int value[n];
 for(int i=0;i<n;i++){
    cin>>value[i];
 }
 int weight[n];
 for(int i=0;i<n;i++){
    cin>>weight[i];
 }
 int capacity;
 cin>>capacity;

 int ans[n+1][capacity+1];

 for(int i=0;i<n+1;i++){
    for(int j=0;j<capacity+1;j++){
        if(i==0||j==0){
            ans[i][j]=0;
        }
        else if(weight[i-1]<=j){
            {
                if(value[i-1]+ans[i-1][j-weight[i-1]]>ans[i-1][j]){
                    ans[i][j]=value[i-1]+ans[i-1][j-weight[i-1]];
                }
                else
                ans[i][j]=ans[i-1][j];
            }
        }
        else
            ans[i][j]=ans[i-1][j];
    }
 }

 cout<<ans[n][capacity];



}
