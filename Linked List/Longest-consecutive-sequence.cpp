#include<bits/stdc++.h>
using namespace std;

void findLongest(vector<int> arr){
    unordered_map<int,bool> m;
    for(int i=0;i<arr.size();i++){
        m[arr[i]]=true;
    }

    for(int i=0;i<arr.size();i++){
        if(m[arr[i]-1]==true){
            m[arr[i]]=false;
        }
    }

    int c=0;
    int maxLeastRange=0;
    int maxMostRange = 0;

    for(auto i : m){
        int tempc=0;
        int tempSP=0;
        int tempEP=0;

        if(i.second==true){
            tempSP=i.first;
            int k=i.first;
            while(m.find(k)!=m.end()){
                k++;
                tempc++;
            }
            tempEP=k;
        }

        if(tempc>c){
            c=tempc;
            maxLeastRange=tempSP;
            maxMostRange=tempEP;
        }

    }
    for(int i=maxLeastRange;i<maxMostRange;i++){
        cout<<i<<endl;
    }
}

int main(){
     int n;
      cin>>n;
      vector<int> arr;
       for(int i=0;i<n;i++){
           int x;
           cin>>x;
           arr.push_back(x);
       }
    findLongest(arr);
 }
