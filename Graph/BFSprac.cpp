#include<bits/stdc++.h>
using namespace std;

void printBFS(int **edges,int sv, int vertex ,bool *visited){
   queue<int> q;
   q.push(sv);
   visited[sv]=true;
   while(!q.empty()){
    int temp=q.front();
    q.pop();
    cout<<temp<<endl;
    for(int i=0;i<vertex;i++){
        if(edges[temp][i]==1&&visited[i]==false){
            q.push(i);
            visited[i]=true;
        }
    }
   }
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
    printBFS(edges,0,v,visited);
 }


