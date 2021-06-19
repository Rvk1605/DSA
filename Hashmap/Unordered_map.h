#include<iostream>
using namespace std;

template <typename V>
class Node{

  string key;
  V value;
  Node *next;

  Node(string key, V value){
    this.key=key;
    this.value=value;
    next=NULL;
  }

  ~Node(){
    delete next;
  }
};

template <typename V>
class mymap{
  Node<V> ** buckets;//Pointer Pointing to BUcket Array
  int bucketsize;
  int count;

  mymap(int size){
    count=0;
    bucketsize=size;
    buckets=new Node<v>*[bucketsize];
    for(int i=0;i<bucketsize;i++){
      busckets[i]= NULL;
    }
  }

  ~mymap(){
    for(int i=0;i<bucketsize;i++){
      delete [] buckets;
    }
  }

  int size(){
    return count;
  }

private:
  int getBucketIndex(string key){
    int hashCode=0;
    int currentCoeff=1;
    for(int i=0;i<key.length();i++){
      hashCode+=key[i]*currentCoeff;
      hashCode=hashCode% bucketsize;
      currentCoeff=currentCoeff*29;
      currentCoeff=currentCoeff%bucketsize;
    }
    return hashCode%bucketsize;
  }

  void rehash(){
    mymap <V>* temp=buckets;
    buckets=new Node<V>* [2*bucketsize];
    int oldBucketSize = bucketsize;
    bucketsize = 2* bucketsize;
    count=0;
    for(int i=0;i<oldBucketSize;i++){
      Node <V>* head=temp[i];
      while(head!=NULL){
        string key=head->key;
        int value=head->value;
        insert(key,value);
        head=head->next;
      }
    }

    for(int i=0;i<oldBucketSize;i++){
      Node <V>* head=temp[i];
      delete head;
    }
    delete [] temp;
  }

public:
  void remove(string key){
  int bucketIndex =getBucketIndex(key);
  mymap<V>* head = buckets[bucketIndex];
  mymap<V>* prev = NULL;
  while(head!=NULL){
    if(head->key==key){
      if(prev==NULL){
        buckets[bucketIndex]=head->next;
      }else{
        prev->next=head->next;
      }
      head->next=NULL;
      V value=head->value;
      delete head;
      count--;
      cout<<"Value"<<value<<"For Key :"<<key<<"Deleted Successfully"<<endl;
      return;
    }
    prev=head;
    head=head->next;
  }
  cout<<"Key Not Found"<<endl;
  return;
  }

  V getValue(string key){
    int bucketIndex = getBucketIndex(key);
    mymap <V>* head = buckets[bucketIndex];
    while(head!=NULL){
      if(head->key==key){
        return head->value;
      }
      head=head->next;
    }
    return 0;
  }

  V insert(string key,int value){
      int bucketIndex = getBucketIndex(key);
      mymap <V>* head = buckets[bucketIndex];
      //first Search if key exits or Not
      while(head!=NULL){
        if(head->key==key){
          head->key=key;
          head->value=value;
          return;
        }
        head=head->next;
      }
      head = buckets[bucketIndex];
      Node <v>* newNode = new Node<v>(key,value);
      newNode->next=head;
      buckets[bucketIndex]=newNode;
      count++;

      double loadFactor = (1.0*count)/bucketsize;
      if(loadFactor>0.7){
        rehash();
      }
  }
};
