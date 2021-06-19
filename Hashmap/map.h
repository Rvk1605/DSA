//using Seperate Chaining
#include<string>
using namespace std;


//This is NOde OF Linked List Structure
template<typename V>
class MapNode{
public:
  string key;
  V value;
  MapNode* next;

  MapNode(string key,V value){
    this->key = key;
    this->value = value;
    next = NULL;
  }
  ~MapNode (){
    delete next;
  }
};


template<typename V>
class ourmap{
  MapNode<V>** buckets;//Pointer Pointing to BUcket Array
  int count;
  int numBuckets;
public:
  ourmap(){
    count=0;
    numBuckets=5;
    buckets = new MapNode<V>*[numBuckets] ;
    for(int i=0;i<numBuckets;i++){
      buckets[i]=NULL;
    }
  }

  ~ourmap(){
    for(int i=0;i<numBuckets;i++){
      delete buckets[i];
    }
    delete [] buckets;
  }

  int size(){
    return count;
  }

private:
int getBucketIndex(string key){
  int hashCode=0;
  int currentCoeff=1;
  for(int i=key.length();i>=0;i--){
    hashCode+=key[i]*currentCoeff;
    hashCode = hashCode % numBuckets;//To Decrese its Size to bring in range
    currentCoeff = currentCoeff * 37;//multiplied with prime number
    currentCoeff=currentCoeff % numBuckets; //To decrease its size to bring it in range
  }
  return hashCode % numBuckets;
}

void rehash(){
  MapNode <V> ** temp = buckets;
  buckets= new MapNode<V>*[2 * numBuckets];
  for(int i=0;i<2*numBuckets;i++){
    buckets[i]=NULL;
  }
  int oldBucketCount = numBuckets;
  numBuckets *= 2;
  count=0;
  //Now we will traverse the old bucket array one by one and insert it in coresponding new bucket Array
  for(int i=0;i<oldBucketCount;i++){
    MapNode<V>* head=temp[i];
    while(head!=NULL){
      string key = head->key;
      V value = head->value;
      insert(key,value);//inserted in new Bucket Array
      head=head->next;
    }
  }
  //After Inserting the value We Will Delete The Old BUcket Array with all  its pointers
  for(int i=0;i<oldBucketCount;i++){
    MapNode<V>* head = temp[i];
    delete head;
  }
  delete [] temp;
}

public:

  double getLoadFactor(){
    return (1.0*count)/numBuckets;
  }

  V getValue(string key){
    int bucketIndex=getBucketIndex(key);
    MapNode<V>* head = buckets[bucketIndex];
    while(head!=NULL){
      if(head->key==key){
        return head->value;
      }
      head=head->next;
    }
    return 0;
  }

  void insert(string key,V value){
    int bucketIndex=getBucketIndex(key);//if key already exist than update its value
    MapNode<V>* head = buckets[bucketIndex];
    while(head != NULL){
      if(head->key == key){
        head->value=value;
        return;
      }
      head=head->next;
    }
    head = buckets[bucketIndex];
    MapNode<V>* node = new MapNode<V>(key,value);
    node->next = head;
    buckets[bucketIndex] = node;
    count++;

    //Optimization Using Rehashing

    double loadFactor = (1.0*count)/numBuckets;//1.0 is multiplie to make it in double as it is integer
    if(loadFactor>0.7){
      rehash();
    }
  }

  V remove(string key){
     int bucketIndex=getBucketIndex(key);
     MapNode<V>* head = buckets[bucketIndex];
     MapNode<V>* prev=NULL;//This will be used to delete the node
     while(head!=NULL){
       if(head->key==key){
         if(prev==NULL){//if first node is to be removed
           buckets[bucketIndex]=head->next;
         }else{
         prev->next=head->next;
       }
       head->next=NULL;
       V value= head->value;
       delete head;
       count--;
       return value;
       }
       prev=head;
       head=head->next;
     }
     return 0; //Invalid Value to be returned
  }

};
