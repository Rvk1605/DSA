#include<bits/stdc++.h>
using namespace std;

class Heap{
    public:
priority_queue<int> rightMax;
priority_queue<int,vector<int>,greater<int>> leftMin;

int size(){
    return rightMax.size()+leftMin.size();
}

void heapify(){
    if((leftMin.size()-rightMax.size())>1){
        if((leftMin.size()+rightMax.size())%2==0){
            while(leftMin.size()!=rightMax.size()){
                rightMax.push(leftMin.top());
                leftMin.pop();
            }
        }else{
             while(leftMin.size()-rightMax.size()!=1){
                rightMax.push(leftMin.top());
                leftMin.pop();
            }
        }
    }
    else
        return;
}

void insert(int data){
    leftMin.push(data);
    heapify();
}

int remove(){
    if(leftMin.size()==0&&rightMax.size()==0){
        cout<<"Heap is Empty"<<endl;
        return -1;
        }
    int ans;
  if(leftMin.size()==rightMax.size()){
      ans=rightMax.top();
      rightMax.pop();
  }else{
      ans=leftMin.top();
      leftMin.pop();
  }
  return ans;
}

void peek(){
      if(leftMin.size()==0&&rightMax.size()==0){
        cout<<"Underflow"<<endl;
        return;
        }
    if(leftMin.size()==rightMax.size()){
        cout<<rightMax.top()<<endl;
    }
    else{
        cout<<leftMin.top()<<endl;
    }
}

};

int main(){
    Heap h;
    string choice;
    while(true){
        cin>>choice;
        if(choice.compare("add")==0){
            int num;
            cin>>num;
            h.insert(num);
        }else if(choice.compare("remove")==0){
           int data= h.remove();
           if(data==-1){
               cout<<"Underflow"<<endl;
           }else{
               cout<<data<<endl;
           }
        }else if(choice.compare("peek")==0){
            h.peek();
        }else if(choice.compare("size")==0){
            cout<<h.size()<<endl;
        }else if(choice.compare("quit")==0){
            return 0;
        }
    }
    return 0;


}