#include<bits/stdc++.h>
using namespace std;


void Path_finder(int **edges,int vertex,int sv,int ev,bool *visited,vector <int> &v)
{
    unordered_map<int,int> m;
    m[ev]=-1;
    queue <int> q;
    q.push(sv);
    visited[sv]=true;
    int temp;
    while(!q.empty())
    {
        int temp=q.front();
        q.pop();
        for(int i=0;i<=vertex;i++)
        {

            if(i==temp)
                continue;
            if(edges[temp][i]==1&&visited[i]==false)
            {
                q.push(i);
                m[i]=temp;
                visited[i]=true;
            }
        }
        if(m[ev]!=-1)
            break;
    }

    int t=m[ev];
    v.push_back(ev);
    while(1)
    {
        v.push_back(t);
        t=m[t];
        if(t==sv)
            break;
    }
    v.push_back(sv);
}

int main()
{
    int e,v;
    cout<<"Enter No. of Vertex :";
    cin>>v;
    cout<<"Enter No. of Edges :";
    cin>>e;
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
        cout<<"Enter starting and ending Vertex :";
        cin>>sv>>ev;
        edges[sv][ev]=1;
        edges[ev][sv]=1;
    }

    bool *visited=new bool[v];
    for(int i=0;i<v;i++)
        visited[i]=false;
    vector <int> ans;
    Path_finder(edges,v,0,6,visited,ans);
    cout<<"Path"<<endl;
    for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<" ";
}
