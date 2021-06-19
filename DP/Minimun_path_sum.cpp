 #include<bits/stdc++.h>
 using namespace std;

 int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        int arr[n][m];
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(i==n-1&&j==m-1)
                    arr[i][j]=grid[i][j];
                else if(i==n-1){
                    arr[i][j]=grid[i][j]+arr[i][j+1];
                }
                else if(j==m-1){
                    arr[i][j]=grid[i][j]+arr[i+1][j];
                }
                else{
                arr[i][j]=grid[i][j]+min(arr[i+1][j],arr[i][j+1]);
            }
            }
        }

        int ans=arr[0][0];
        return ans;
}

int main(){
vector<vector <int >> grid;
int n,m;
cin>>n>>m;
for(int i=0;i<n;i++){
    vector <int > v;
    for(int j=0;j<m;j++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    grid.push_back(v);
}
int ans=minPathSum(grid);
cout<<ans;
}
