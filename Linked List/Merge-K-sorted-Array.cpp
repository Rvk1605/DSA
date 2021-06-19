#include<bits/stdc++.h>
using namespace std;

class Trip{
public:
    int arrIndex;
    int eleIndex;
    int element;

    Trip(int arrInd,int eleInd,int ele){
    arrIndex =arrInd;
    eleIndex =eleInd;
    element = ele;
    }
};

class compare{
public:
    bool operator()(const Trip &a , const Trip &b){
    return a.element>b.element;
    }
};

vector<int> mergeKSortedArray(vector<vector<int>> v){
    vector<int> ans;
    priority_queue<Trip,vector<Trip>,compare> pq;

for(int i=0;i<v.size();i++){
    Trip t(i,0,v[i][0]);
    pq.push(t);
}

while(!pq.empty()){
    Trip temp=pq.top();
    pq.pop();
    ans.push_back(temp.element);
    temp.eleIndex++;
    if(temp.eleIndex<v[temp.arrIndex].size()){
        temp.element=v[temp.arrIndex][temp.eleIndex];
        pq.push(temp);
    }
}

return ans;
}

int main(){
    int k;
    cin>>k;
    vector<vector<int>> v;
    for(int i=0 ;i<k;i++){
        vector<int> temp;
        int n;
        cin>>n;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            temp.push_back(x);
        }
        v.push_back(temp);
    }
    vector<int> ans;
    ans=mergeKSortedArray(v);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
 }
