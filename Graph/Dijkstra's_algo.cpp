#include<bits/stdc++.h>
using namespace std;

int find_min_distance_vertex(int *distance,bool *visited,int v){
    int m=-1;
    for(int i=0;i<v;i++){
        if(visited[i]==false&&(m==-1||distance[i]<distance[m]))
            m=i;
    }
    return m;
}

void Dijkstra(int **edges,int v){
    bool visited[v];
    for(int i=0;i<v;i++){
        visited[i]=false;
    }
    int distance[v];
    distance[0]=0;
    for(int i=1;i<v;i++){
        distance[i]=INT_MAX;
    }

    int s,e;
    cout<<"Vertices :";
    for(int i=0;i<v;i++){
        cout<<i<<" ";
    }
    cout<<"\nEnter Starting and Ending Point from above Vertices :";
    cin>>s>>e;
    for(int i=0;i<v;i++){
        int min_vertex=find_min_distance_vertex(distance,visited,v);
        visited[min_vertex]=true;
        for(int j=0;j<v;j++){
            if(edges[min_vertex][j]!=0&&visited[j]==false){
                int dist=distance[min_vertex]+edges[min_vertex][j];
                if(distance[j]>dist)
                    distance[j]=dist;
            }
        }
    }
for(int i=1;i<v;i++){
    cout<<"Shortest Distance b/w 0 ----> "<<i<<" = "<<distance[i]<<endl;
}
}
 int main(){
 int e,v;
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
    int sv,ev,w;
    cout<<"Enter Starting vertex , Ending Vertex and Weight :";
    cin>>sv>>ev>>w;
    edges[sv][ev]=w;
    edges[ev][sv]=w;
 }

 Dijkstra(edges,v);
 }
