#include<bits/stdc++.h>
using namespace std;

class Edges_weight{
    public:
int sv,ev,w;
};
int find_min_vertex(int *weight,bool *visited,int n){
    int m=-1;
    for(int i=0;i<n;i++){
            if(visited[i]==false&&(m==-1||weight[i]<weight[m]))
            m=i;
    }
    return m;
}
void prims(int **edges,int vertices,int sv,int *parent,bool *visited,int *weight){
             for(int j=0;j<vertices;j++){
                int temp=find_min_vertex(weight,visited,vertices);
                visited[temp]=true;
                for(int i=0;i<vertices;i++){
                if(edges[temp][i]!=0&&visited[i]==false)
                {
                    if(edges[temp][i]<weight[i])
                    weight[i]=edges[temp][i];
                    parent[i]=temp;
                }
            }
        }

    for(int i=1;i<vertices;i++){
        cout<<i<<" "<<parent[i]<<endl;
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

//Edges_weight weight[e];

for(int i=0;i<e;i++){
        int sv,ev,w;
        cout<<"Enter Starting Vertex, Ending Vertex , Weight:";
        cin>>sv>>ev>>w;
        edges[sv][ev]=w;
        edges[ev][sv]=w;

    /*weight[i].sv=sv;
    weight[i].ev=ev;
    weight[i].w=w;*/
}

cout<<"\n-------------Matrix--------------"<<endl;
for(int i=0;i<v;i++){
    for(int j=0;j<v;j++){
        cout<<edges[i][j]<<" ";
    }
    cout<<endl;
}

/*cout<<"\n-------Edges with weight-----------------"<<endl;
for(int i=0;i<v;i++){
    cout<<weight[i].sv<<" "<<weight[i].ev<<" "<<weight[i].w<<endl;
} */

bool *visited=new bool[v];
for(int i=0;i<v;i++){
    visited[i]=false;
}

int *wt=new int[v];
for(int i=0;i<v;i++){
    wt[i]=99999;
}

int *parent=new int[v];
for(int i=0;i<v;i++){
    parent[i]=-1;
}

prims(edges,v,0,parent,visited,wt);

}
