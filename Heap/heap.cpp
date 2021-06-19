#include<bits/stdc++.h>
using namespace std;

class PriorityQueue{
vector<int> pq;

public:
    int getSize(){
    return pq.size();
    }

    bool isEmpty(){
    if(pq.size()==0){
        return true;
    }
    return false;
    }

    int getMin(){
    if(isEmpty()){
        return -1;
    }
    return pq[0];
    }


    void upheapify(int childIndex){
        while(childIndex>0){
        int parentIndex=(childIndex-1)/2;
        if(pq[childIndex]<pq[parentIndex]){
            int temp=pq[childIndex];
            pq[childIndex]=pq[parentIndex];
            pq[parentIndex]=temp;
        }else{
            break;
        }
        childIndex=parentIndex;
        parentIndex=(childIndex-1)/2;
        }
    }

    void insert(int ele){
        pq.push_back(ele);
        upheapify(pq.size()-1);
    }

    void display(){
    for(int i=0;i<pq.size();i++){
        cout<<pq[i]<<endl;
    }
    }


    void downHeapify(){
        int parentIndex= 0;
        int leftChildIndex =2*parentIndex+1;
        int rightChildIndex=2*parentIndex+2;

        while(leftChildIndex < pq.size()){

            int minIndex=parentIndex;
            if(pq[minIndex] > pq[leftChildIndex])
            minIndex=leftChildIndex;

            if(pq[minIndex]>pq[rightChildIndex])
            minIndex=rightChildIndex;

            int temp=pq[minIndex];
            pq[minIndex]=pq[parentIndex];
            pq[parentIndex]=temp;

            parentIndex = minIndex;
            leftChildIndex=2*parentIndex+1;
            rightChildIndex=2*parentIndex+2;
        }
    }


    int removeMin(){
        if(isEmpty()){
            cout<<"HEAP Is Empty"<<endl;
            return -1;
        }
        int ans=pq[0];

        pq[0]=pq[pq.size()-1];

        pq.pop_back();

        downHeapify();
        return ans;
    }

};

int main(){
PriorityQueue p;
p.insert(100);
p.insert(10);
p.insert(15);
p.insert(4);
p.insert(17);
p.insert(21);
p.insert(67);

cout<<p.getSize()<<endl;
cout<<p.getMin()<<endl;

p.display();

while(!p.isEmpty()){
    cout<<p.removeMin()<<" ";
}


}
