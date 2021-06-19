#include<iostream>
#include "map.h"
using namespace std;
int main(){
  ourmap<int> m;
  for(int i=0;i<10;i++){
    char c = '0'+i;
    string key = "abc";
    key = key + c;
    int value = i+1;
    m.insert(key,value);
  }
  cout<<m.size()<<endl;
  return 0;
}
