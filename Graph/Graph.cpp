#include<bits/stdc++.h>
using namespace std;
//Depth First Search (We are Going into one direction very deeply)
void DFS(int vertex,int **edges,int sv,bool *visited)
{
    cout<<sv<<endl;
    visited[sv]=true;
    for(int i=0;i<vertex;i++)
    {
        if(i==sv)
            continue;
        if(edges[sv][i]==1)
        {
            if(visited[i])
                continue;
            DFS(vertex,edges,i,visited);
        }
    }
}

void BFS(int vertex,int **edges,int sv,bool visited[])
{
    queue<int > q;
    q.push(sv);
    visited[sv]=true;
    while(!q.empty())
    {
        int temp=q.front();
        q.pop();
        cout<<temp<<endl;
        for(int i=0;i<vertex;i++)
        {
            if(i==temp)
                continue;
            if(edges[temp][i]==1&&!visited[i])
            {
            q.push(i);
            visited[i]=true;
            }
        }
    }
}

int main()
{
    int vertex,e;
    cout<<"Enter No. Of Vertex :";
    cin>>vertex;
    cout<<"Enter No. of Edges :";
    cin>>e;
    int **edges=new int*[vertex];
    for(int i=0;i<vertex;i++)
    {
        edges[i]=new int[vertex];
        for(int j=0;j<vertex;j++)
            edges[i][j]=0;
    }

    int sv,ev;

    for(int i=0;i<e;i++)
    {
        cout<<"Enter Starting and Ending Vertex of an Edge :";
        cin>>sv>>ev;
        edges[sv][ev]=1;
        edges[ev][sv]=1;
    }

    bool visited[vertex];
    for(int i=0;i<vertex;i++)
        visited[i]=false;

    //DFS
    cout<<"DFS Traversal"<<endl;
    DFS(vertex,edges,0,visited);
    for(int i=0;i<vertex;i++)
        visited[i]=false;
    cout<<"BFS Traversal"<<endl;
    BFS(vertex,edges,0,visited);

    delete []visited;
    for(int i=0;i<vertex;i++)
        delete [] edges[i];
    delete []edges

}
