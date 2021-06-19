#include<bits/stdc++.h>
using namespace std;

int find_parent(int vertex,int *parent){
    if(parent[vertex]==vertex)
        return vertex;
    find_parent(parent[vertex],parent);
}

bool has_cycle(int **edges,int vertex,pair<int,int> p[],int e){
    int *parent=new int[vertex];
    for(int i=0;i<vertex;i++){
        parent[i]=i;
    }
    for(int i=0;i<e;i++){
                int pv1=find_parent(p[i].first,parent);
                int pv2=find_parent(p[i].second,parent);
                if(pv1==pv2)
                    return true;

                parent[p[i].first]=p[i].second;
            }

     return false;
}

int main(){
     int v,e;
     cout<<"Enter No. of Vertex and Edges :";
     cin>>v>>e;
     pair<int,int> p[e];
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
        p[i]=make_pair(sv,ev);
        edges[sv][ev]=1;
        edges[ev][sv]=1;
     }


    if(has_cycle(edges,v,p,e))
        cout<<"Has Cycle"<<endl;
    else
        cout<<"No Cycle"<<endl;

    return 0;

}

