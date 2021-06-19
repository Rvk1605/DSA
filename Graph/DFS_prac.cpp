#include<bits/stdc++.h>
using namespace std;

void printDFS(int **edges,int sv, int vertex ,bool *visited){
    visited[sv]=true;
    cout<<sv<<endl;
    for(int i=0;i<vertex;i++){
        if(edges[sv][i]==1&&visited[i]==false){
            printDFS(edges,i,vertex,visited);
        }
    }
    return;
}

int main(){
     int v,e;
     cout<<"Enter No. of Vertex and Edges :";
     cin>>v>>e;
     int **edges=new int*[v];
     for(int i=0;i<v;i++){
        edges[i]=new int[v];
        for(int j=0;j<v;j++){
            edges[i][j]=0;
        }
     }

     for(int i=0;i<e;i++){
        int sv,ev;
        cout<<"Enter Starting and Ending Vertex :";
        cin>>sv>>ev;
        edges[sv][ev]=1;
        edges[ev][sv]=1;
     }

     bool *visited=new bool[v];
     for(int i=0;i<v;i++){
        visited[i]=false;
     }
    printDFS(edges,0,v,visited);
 }

