// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution {
public:

    int find_parent(vector<int> v[],int e,int vertex ){
    int j=0;
    while(j<vertex){
        e=v[e][v[e].size()-1];
        j++;
    }
    return e;
    }
	bool isCycle(int v, vector<int>adj[]){
    for(int i=0;i<v;i++){
        if(find_parent(adj,i,v)==i){
            return true;
        }
    }
	    return false;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isCycle(V, adj);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}  // } Driver Code Ends
