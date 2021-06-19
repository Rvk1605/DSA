#include<bits/stdc++.h>
using namespace std;
class Heap{
    public:
    vector<int> heap;

    int getSize(){
        return heap.size();
    }

    bool isEmpty(){
        if(heap.size()==0){
            return true;
        }
        return false;
    }

    //Max Heap
    void upHeapify(){
        int childIndex = heap.size()-1;
       
        while(childIndex>0){
            int parentIndex=(2*childIndex-1)/2;
            if(heap[childIndex]>heap[parentIndex]){
                int temp=heap[childIndex];
                heap[childIndex]=heap[parentIndex];
                heap[parentIndex]=temp;
            }else{
                break;
            }
            childIndex=parentIndex;
            parentIndex=(2*childIndex-1)/2;
        }
    }

   // Max Heap
    void downHeapify(){
        int parentIndex=0;
        int leftChildIndex  = 2*parentIndex+1;
        int rightChildIndex = 2*parentIndex+2;
        while(leftChildIndex<=heap.size()){
            int minChildIndex ;
            if(heap[leftChildIndex]>heap[rightChildIndex])
                minChildIndex=leftChildIndex;
            else{
                minChildIndex=rightChildIndex;
            }

            if(heap[minChildIndex]>heap[parentIndex]){
                int temp=heap[minChildIndex];
                heap[minChildIndex]=heap[parentIndex];
                heap[parentIndex]=temp;
            }
            parentIndex=minChildIndex;
            leftChildIndex  = 2*parentIndex+1;
            rightChildIndex = 2*parentIndex+2;
        }
    }

    int getMax(){
        if(heap.size()==0){
            return -1;
        }
        return heap[0];
    }

    void insert(int data){
        heap.push_back(data);
        upHeapify();
    }

    int removeMax(){
        if(heap.size()==0){
            cout<<"Heap is Empty"<<endl;
            return -1;
        }
        int ans=heap[0];
        heap[0]=heap[heap.size()-1];
        heap.pop_back();
        downHeapify();
        return ans;
    }
};

int main(){
    Heap h;
    int n;
    cout<<"Enter no. of Elements :";
    cin>>n;
    int x;
    for(int i=0;i<n;i++){
        cout<<"Enter Element : "<<endl;
        cin>>x;
        h.insert(x);
    }
    cout<<"Size :"<<h.getSize()<<endl;
    cout<<"Top :"<<h.getMax()<<endl;
    while(!h.isEmpty()){
        cout<<"Top :"<<h.getMax()<<endl;
        cout<<"Removed :"<<h.removeMax()<<endl;
    }
}
