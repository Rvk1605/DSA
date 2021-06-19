#include<iostream>
using namespace std;
 int main(){
 int n,m;
 cin>>n>>m;
 int a[n][m];
 for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        cin>>a[i][j];
    }
 }

 int ans[n][m];


 for(int i=n-1;i>=0;i--){
    for(int j=m-1;j>=0;j--){
        if(i==n-1&&j==m-1){
            ans[i][j]=a[n-1][m-1];
        }
        else if(i==n-1){
            ans[i][j]=a[i][j]+ans[i][j+1];
        }
        else if(j==m-1){
            ans[i][j]=a[i][j]+ans[i+1][j];
        }
        else
            ans[i][j]=a[i][j]+min(ans[i+1][j],ans[i][j+1]);
    }
 }
 for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        cout<<ans[i][j]<<"   ";
    }
    cout<<endl;
 }
 cout<<ans[0][0]<<endl;

}
