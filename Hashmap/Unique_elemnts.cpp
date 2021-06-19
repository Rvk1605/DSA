#include <iostream>
#include<unordered_map>
#include<vector>
using namespace std;

vector<int> getUnique(int arr[],int n){
  unordered_map<int ,bool> m;
  vector<int> ans;
  for(int i=0;i<n;i++){
  if(m[arr[i]]==false){
    m[arr[i]]=true;
    ans.push_back(arr[i]);
  }
  }
  return ans;
}

int main(){
  int n;
  cin>>n;
  int arr[n];
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  vector<int> ans=getUnique(arr,n);
  for(int i=0;i<ans.size();i++){
    cout<<ans[i]<<endl;
  }
}
