#include<bits/stdc++.h>
using namespace std;
class compare{
public:
    bool operator()(const int &a,const int &b){
    return a>b;
    }
};
int main(){
    set<int ,compare> s;
    s.insert(34);
    s.insert(53);
    s.insert(3);
    s.insert(23);
    s.insert(34);
    for(auto i:s){
        cout<<i<<" "<<endl;
    }
}
