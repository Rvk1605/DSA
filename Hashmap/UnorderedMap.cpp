#include<iostream>
#include <unordered_map>
#include <string>
using namespace std;
int main(){
  unordered_map<string,int> m;
  //insert
  pair<string ,int> p("abc",1);
  m.insert(p);
  m["def"]=2;

  //find or access
  cout<<m["abc"]<<endl;
  cout<<m.at("def")<<endl;
  //cout<<m.at("ghi")<<endl;  //Gives error as key does not exist
  cout<<m["ghi"]<<endl;      //If Key Not Present than creates the key will default value 0 and print it.

  //Check Presence of Key
  if(m.count("ghi")>0){ //Count either gives 0 or 1 for not presence and Present
    cout<<"Key Present"<<endl;
  }else{
    cout<<"aNot Present"<<endl;
  }

  //Erase an Element
  m.erase("ghi");
  if(m.count("ghi")>0){ //Count either gives 0 or 1 for not presence and Present
    cout<<"Key Present"<<endl;
  }else{
    cout<<"Not Present"<<endl;
  }
}
