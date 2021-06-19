#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *next;
    Node(int data){
        this->data=data;
        next=NULL;
        }
};

class linkedlist{
    public:
    Node *head;

    linkedlist(){
    head=NULL;
    }

    void print(){
    if(head==NULL)
        cout<<"List Is Empty"<<endl;
    Node *temp;
    temp=head;
    while(temp!=NULL){
        cout<<temp->data<<endl;
        temp=temp->next;
    }
    }

    void insert_front(int data){
        Node *temp=new Node(data);
        if(head==NULL){
            head=temp;
            return;
        }
        temp->next=head;
        head=temp;
    }

    Node* reverse_list(Node *head){
    if(head==NULL||head->next==NULL)
        return head;

    Node *temp=reverse_list(head->next);
    head->next->next=head;
    head->next=NULL;
    return temp;
    }
};

int main(){
    linkedlist ll;
    int n;
    cout<<"Enter No. of Elements :";
    cin>>n;
    for(int i=0;i<n;i++){
            int x;
        cin>>x;
        ll.insert_front(x);
    }
    ll.print();
    ll.head=ll.reverse_list(ll.head);
    ll.print();

    return 0;
}
