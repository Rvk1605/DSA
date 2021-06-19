#include<bits/stdc++.h>
using namespace std;

int find_min_vertex(int *weight,bool *visited,int v){
    int min_vertex=-1;
    for(int i=0;i<v;i++){
        if(visited[i]==false&&(min_vertex==-1||weight[i]<weight[min_vertex])){
            min_vertex=i;
        }
    }
    return min_vertex;
}

void Prim(int **edges,int v){
    bool *visited= new bool[v];
    for(int i=0;i<v;i++){
        visited[i]=false;
    }

    int *parent= new int[v];
    for(int i=0;i<v;i++){
        parent[i]=0;
    }

    int *weight=new int[v];
    weight[0]=0;
    for(int i=1;i<v;i++){
        weight[i]=INT_MAX;
    }
    for(int i=0;i<v;i++){
        int min_vertex=find_min_vertex(weight,visited,v);
        visited[min_vertex]=true;
        for(int j=0;j<v;j++){
            if(edges[min_vertex][j]!=0&&visited[j]==false){
                parent[j]=min_vertex;
                weight[j]=edges[min_vertex][j];
            }
        }
    }
    for(int i=1;i<v;i++){
        cout<<i<<" "<<parent[i]<<endl;
    }

}

int main(){
int e,v;
cout<<"Enter no. of Vertex and Edges :";
cin>>v>>e;
int **edge = new int*[v];
for(int i=0;i<v;i++){
    edge[i]=new int[v];
    for(int j=0;j<v;j++){
        edge[i][j]=0;
    }
}

for(int i=0;i<e;i++){
        int sv,ev,w;
        cout<<"Enter Starting vertex , Ending vertex and Weight :";
        cin>>sv>>ev>>w;
        edge[sv][ev]=w;
        edge[ev][sv]=w;
    }
Prim(edge,v);
}
