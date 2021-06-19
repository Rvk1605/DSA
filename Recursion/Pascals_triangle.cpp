#include <iostream>
#include <vector>
using namespace std;

vector<int> getRow(int n){
  if(n==0){
    vector<int> v;
    v.push_back(1);
    return v;
  }
    if(n==1){
      vector<int> v;
      v.push_back(1);
      v.push_back(1);
      return v;
    }
    vector<int> temp=getRow(n-1);
    vector<int> ans;
    ans.push_back(1);
    for(int i=0;i<temp.size()-1;i++){
      ans.push_back(temp[i]+temp[i+1]);
    }
    ans.push_back(1);
    return ans;
}

int main(){
  int n;
  cin>>n;
  vector<int> v=getRow(n);
  for(int i=0;i<v.size();i++){
    cout<<v[i]<<" ";
  }
}
