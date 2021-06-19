#include<bits/stdc++.h>
using namespace std;

void hasPath(int **edges,int vertex,int sv,bool *visited)
{
    cout<<sv<<endl;
    visited[sv]=true;
    for(int i=0;i<vertex;i++)
    {
        if(i==sv)
            continue;
        if(edges[sv][i]==1&&!visited[i])
        {
            hasPath(edges,vertex,i,visited);
        }
    }
}

void printBFS(int **edges,int vertex,int sv,bool *visited)
{
queue<int> q;
q.push(sv);
while(!q.empty())
{
    int temp=q.front();
    q.pop();
    cout<<temp<<endl;
    for(int i=0;i<vertex;i++)
    {
        if(edges[sv][i]==1&&visited[i]==false)
        {
            q.push(i);
            visited[i]=true;
        }
    }
}
}

void DFS(int **edges,int vertex)
{
    bool *visited=new bool[vertex];
    for(int i=0;i<vertex;i++)
        visited[i]=false;
    for(int i=0;i<vertex;i++)
    {
        if(visited[i]==false)
            hasPath(edges,vertex,i,visited);
    }
}

/*void BFS(int **edges,int vertex)
{
    vector <int> Path;
    bool *visited=new bool[vertex];
    for(int i=0;i<vertex;i++)
        visited[i]=false;
    for(int i=0;i<vertex;i++)
    {
        if(visited[i]==false)
            Path=Path_BFS(edges,vertex,i,visited);
    }
}
*/

int main()
{
    int n_v,n_e;
    cout<<"Enter no. of Vertex :";
    cin>>n_v;
    cout<<"Enter no. of Edges :";
    cin>>n_e;
    int **edges=new int*[n_v];
    for(int i=0;i<n_v;i++)
    {
        edges[i]=new int[n_v];
        for(int j=0;j<n_v;j++)
            edges[i][j]=0;
    }
    for(int i=0;i<n_e;i++)
    {
            int sv,ev;
            cout<<"Enter Starting and Ending Vertex : ";
            cin>>sv>>ev;
            edges[sv][ev]=1;
            edges[ev][sv]=1;
    }
    cout<<"DFS Traversal"<<endl;
    DFS(edges,n_v);
}
