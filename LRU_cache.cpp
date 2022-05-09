#include<bits/stdc++.h>
using namespace std;

class DoublyLL{
public:
    int data;
    DoublyLL *prev;
    DoublyLL *next;
    DoublyLL(){}
    DoublyLL(int val){
        data = val;
        prev = NULL;
        next = NULL;
    }
};

DoublyLL* insertAtFront(DoublyLL *head,int n){
    // cout<<"Inserting at Front"<<endl;
    DoublyLL *node = new DoublyLL(n);
    if(head == NULL){
        head = node;
    }else{
        node->next = head;
        head->prev = node;
        head = node;
    }
    return head;
}

DoublyLL* removeBack(DoublyLL *head){
    // cout<<"Removing From Back"<<endl;
    if(head == NULL){
        return head;
    }else if(head->next == NULL){
        free(head);
        head=NULL;
    }else{
        DoublyLL *ptr = head;
        while(ptr->next!=NULL){
            ptr = ptr->next;
        }
        ptr->prev->next = NULL;
        ptr->prev = NULL;
        free(ptr);
    }
    return head;
}

void removeAtPosition(DoublyLL *ptr){
    // cout<<"Removing From Position"<<endl;
    if(ptr==NULL){
        return;
    }else if(ptr->prev == NULL && ptr->next==NULL){
        free(ptr);
        ptr = NULL;
    }else if(ptr->prev!=NULL && ptr->next ==NULL){
        ptr->prev->next = NULL;
        ptr->prev = NULL;
        free(ptr);
    }else{
        ptr->prev->next = ptr->next;
        ptr->next->prev = ptr->prev;
        ptr->prev = NULL;
        ptr->next = NULL;
        free(ptr);
    }
}

DoublyLL * find(DoublyLL *head,int n){
    // cout<<"Searching LL"<<endl;
    if(head == NULL){
        return NULL;
    }
    while(head!=NULL){
        if(head->data == n){
            // cout<<"Element Found"<<endl;
            return head;
        }
        head=head->next;
    } 
    // cout<<"Returning NULL"<<endl;
    return NULL;
}

void printLL(DoublyLL *ptr){
    DoublyLL * p = ptr;
    while(p!=NULL){
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}

class LRUCache{
    DoublyLL * start;
    int no_frame ;
    int page_count ;
public:
    LRUCache(int n){
        start = NULL;
        no_frame = n;
        page_count = 0;
    }
    void insertPage(int num){
        if(page_count==0){
            start = insertAtFront(start,num);
        }else{
            DoublyLL *ptr = find(start,num);
            if(ptr!=NULL){
                // cout<<"Element Found in Cache"<<endl;
            }
            if(ptr == NULL){
                if(page_count == no_frame){
                    removeBack(start);
                    start = insertAtFront(start,num);
                }else{
                    start = insertAtFront(start,num);
                }
            }else{
                removeAtPosition(ptr);
                start = insertAtFront(start,num);
            }
        }
        if(page_count<4){
            page_count++;
        }
        printLL(start);
    }
};

int main(){
    vector<int> v = {7,0,1,2,0,3,0,4,2,3,0,3,2,1,2,0,1};
    LRUCache obj(4);
    for(int i=0;i<v.size();i++){
        obj.insertPage(v[i]);
    }
    return 0;
}