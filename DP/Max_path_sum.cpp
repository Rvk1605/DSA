// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maximumPath(int n,vector<vector<int>> mat )
    {
        vector<vector<int>> arr;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                arr[i][n-1-j]=mat[n-1-i][n-1-j];
            }
        }
        int sum=*max_element(arr[0].begin(),arr[0].end());
        int m=sum;
        for(int i=0;i<n;i++){
                int j;
            for(j=0;j<n;j++){
                if(arr[i][j]==m)
                    break;
            }
                if(j==0)
                    m=max(arr[i+1][j],arr[i+1][j+1]);
                else if(j==n-1){
                    m=max(arr[i+1][j],arr[i+1][j+1]);
                }
                else{
                m=max(arr[i+1][j],max(arr[i+1][j+1],arr[i+1][j-1]));
                }
        sum=sum+m;
        }
        cout<<sum<<endl;
}};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];

        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}  // } Driver Code Ends
