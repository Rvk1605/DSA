#include<bits/stdc++.h>
using namespace std;

bool printDFS(int **edges,int vertex,bool *visited,int v1,int v2)
{
    if(v1==v2)
        return true;
    visited[v1]=true;
    for(int i=0;i<vertex;i++)
    {
        if(i==v1)
            continue;
        if(edges[v1][i]==1&&visited[i]==false)
            {
                return printDFS(edges,vertex,visited,i,v2);
            }
    }
    return false;
}

int main()
{
    int v,e;
    cout<<"Enter no. of Vertex :";
    cin>>v;
    cout<<"Enter no. of Edges :";
    cin>>e;
    int **edges=new int*[v];
    for(int i=0;i<v;i++)
    {
        edges[i]=new int[v];
        for(int j=0;j<v;j++)
        edges[i][j]=0;
    }

    for(int i=0;i<e;i++)
    {
        int sv,ev;
        cout<<"Enter Starting and Ending Vertex :";
        cin>>sv>>ev;
        edges[sv][ev]=1;
        edges[ev][sv]=1;
    }

    int v1,v2;
    cout<<"Enter v1,v2 :";
    cin>>v1>>v2;

    bool *visited=new bool[v];
    for(int i=0;i<v;i++)
        visited[i]=false;


    if(printDFS(edges,v,visited,v1,v2))
        cout<<"Has Path"<<endl;
    else
        cout<<"Has No Path "<<endl;


}
