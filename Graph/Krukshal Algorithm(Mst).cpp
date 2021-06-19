#include<bits/stdc++.h>
using namespace std;

class Edge{
public:
int sv,ev,w;
};

bool compare(Edge e1,Edge e2){
    return(e1.w<e2.w);
}

int find_parent(int vertex,int *parent){
    if(parent[vertex]==vertex)
        return vertex;
    find_parent(parent[vertex],parent);
}

int main(){
    int v,e;
    cout<<"Enter No. of Vertex and Edges :";
    cin>>v>>e;
    Edge input[e],output[e];
    for(int i=0;i<e;i++){
        cout<<"Enter Starting Vertex , Ending Vertex , Weight :";
        cin>>input[i].sv>>input[i].ev>>input[i].w;
    }
    sort(input,input+e,compare);
    cout<<"\n--------------After Sorting----------------"<<endl;
    for(int i=0;i<e;i++)
    {
        cout<<input[i].sv<<" "<<input[i].ev<<" "<<input[i].w<<endl;
    }

    int parent[v];
    for(int i=0;i<v;i++){
        parent[i]=i;
    }
    int c=0,i=0,j=0,pv1,pv2;
    while(c!=v-1){
        Edge current=input[i++];
        pv1=find_parent(current.sv,parent);
        pv2=find_parent(current.ev,parent);
        parent[current.sv]=current.ev;
        if(pv1!=pv2){
            output[j++]=current;
            c++;
        }

    }
cout<<"-------------MST-------------"<<endl;
    for(int i=0;i<j;i++){
        cout<<output[i].sv<<" "<<output[i].ev<<" "<<output[i].w<<endl;
    }
}
