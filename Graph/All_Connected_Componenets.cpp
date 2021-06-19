#include<bits/stdc++.h>
using namespace std;
vector<int> find_components(int **edges,int vertex,int sv,bool *visited)
{
    vector<int> v;
    queue <int> q;
    q.push(sv);
    visited[sv]=true;
    while(!q.empty())
    {
        int temp=q.front();
        q.pop();
        v.push_back(temp);
    for(int i=0;i<vertex;i++)
    {
        if(i==temp)
            continue;
        if(edges[temp][i]==1&&visited[i]==false)
        {
            q.push(i);
            visited[i]=true;
        }
    }
    }
    return v;
}

int main()
{
    int e,v;
    cout<<"Enter No. of Edges :";
    cin>>e;
    cout<<"Enter No. of Vertex :";
    cin>>v;
    int **edges=new int*[v];
    for(int i=0;i<v;i++)
    {
        edges[i]=new int[v];
        for(int j=0;j<v;j++)
        {
            edges[i][j]=0;
        }
    }
    for(int i=0;i<e;i++)
    {
        int sv,ev;
        cout<<"Enter Starting and ending Vertex :";
        cin>>sv>>ev;
    }
    bool *visited=new bool[v];
    for(int i=0;i<v;i++)
        visited[i]=false;

    vector<vector<int>> ans;
    for(int i=0;i<v;i++)
    {
        if(visited[i]==false)
        {
         ans.push_back(find_components(edges,v,i,visited));
        }
    }

    for(int i=0;i<ans.size();i++)
    {
        for(int j=0;j<ans[i].size();j++)
        {
            cout<<ans[i][j]<<" ";
        }

    }
}
