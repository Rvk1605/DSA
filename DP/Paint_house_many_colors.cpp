#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    int arr[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    int ans[n][m];
    for(int i=0;i<m;i++){
        ans[0][i]=arr[0][i];
    }

    for(int i=1;i<n;i++){
        for(int j=0;j<m;j++){
                int min_ele=INT_MAX;
            for(int k=0;k<m;k++){
                if(k!=j){
                    if(min_ele>ans[i-1][k]){
                        min_ele=ans[i-1][k];
                    }
                }
            }
            ans[i][j]=min_ele+arr[i][j];
        }
    }
    int min_ele=INT_MAX;
for(int i=0;i<m;i++){
    if(ans[n-1][i]<min_ele)
        min_ele=ans[n-1][i];
}
cout<<min_ele<<endl;

}
