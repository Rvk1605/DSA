#include<iostream>
#include<unordered_map>
#include<string>
#include <vector>
using namespace std;

 int main(){
   unordered_map<string,int> m;
   m["abc"]=1;
   m["def"]=2;
   m["ghi"]=3;
   m["jkl"]=4;
   m["lmn"]=5;
   m["opq"]=6;
   m["rst"]=7;
   m["uvw"]=8;

   //Iterator
   unordered_map<string,int>::iterator it=m.begin();
   while(it!=m.end()){
     cout<<"Key :"<<it->first<<" ";
     cout<<"Value :"<<it->second<<endl;
     it++;
   }
   //Result will not be in ordered

   //Iterator in find
   unordered_map<string ,int>::iterator it1 =m.find("abc");
   if(it1==m.end()){
     cout<<"Not Found"<<endl;
   }else{
     cout<<"Found and Removed"<<endl;
   }

   //Iterator in Erase Function

   m.erase(it1);
   //m.erase(it1+4 ; This is not valid for Unordered map as the next data is not known to us
   it=m.begin();
   while(it!=m.end()){
     cout<<"Key :"<<it->first<<" ";
     cout<<"Value :"<<it->second<<endl;
     it++;
   }


   //For Vectors
   vector<int> v;
   v.push_back(1);
   v.push_back(2);
   v.push_back(3);
   v.push_back(4);
   v.push_back(5);
   v.push_back(6);

   vector<int> ::iterator vit=v.begin();
   while(vit!=v.end()){
     cout<<*vit<<endl;
     vit++;
   }

   vit=v.begin();
   v.erase(vit,vit+3);
   cout<<"After Erasing From Vector"<<endl;
   vit=v.begin();
   while(vit!=v.end()){
     cout<<*vit<<endl;
     vit++;
   }

 }
