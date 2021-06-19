#include<bits/stdc++.h>
using namespace std;

bool Is_connected(int **edges,int vertex,int sv,bool *visited)
{
    queue<int> q;
    q.push(sv);
    visited[sv]=true;
    while(!q.empty())
    {
        int temp=q.front();
        q.pop();
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
    for(int i=0;i<vertex;i++)
    {
        if(visited[i]==false)
            return false;
    }
    return true;

}

int main()
{
    int e,v;
    cout<<"Enter no. of Edges :";
    cin>>e;
    cout<<"Enter no. of Vertex :";
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
        cout<<"Enter Starting and Ending Vertex :";
        cin>>sv>>ev;
        edges[sv][ev]=1;
        edges[ev][sv]=1;
    }
    bool *visited=new bool[v];
    for(int i=0;i<v;i++)
    {
        visited[i]=false;
    }

    if(Is_connected(edges,v,0,visited))
        cout<<"Graph is Connected"<<endl;
    else
        cout<<"Graph is Not Connected"<<endl;
    delete []visited;
    for(int i=0;i<v;i++)
        delete edges[i];
    delete []*edges
}
