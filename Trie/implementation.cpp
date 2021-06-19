#include<bits/stdc++.h>
using namespace std;
class TrieNode{
    public:
    char data;
    TrieNode** children;
    bool isTerminal;
    //Assume all data to be LowerCase 
    TrieNode(char data){
        this->data=data;
        children = new TrieNode*[26];
        for(int i=0;i<26;i++){
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie{
    TrieNode *root;
    public:
    Trie(){
        root = new TrieNode(NULL);//For Root Data Will Be NULL
    }


    void insertWord(TrieNode * root ,string word){
         //Base Case
         if(word.length()==0){
             root->isTerminal = true;
             return;
         }
        // for(int i=0;i<26;i++){
        //     if(word[0]==root->children[i]->data){
        //         string temp=word.substr(1);
        //         insert(temp);  
        //     }
        // }

        //This Calculation Could BE Optimised by just checking the specific index of the Word
        
        //Small Calculation

        int index= word[0]-'a';
        TrieNode *child;
        if(root->children[index]!=NULL){
            child= root->children[index]; //if the word already exist than just store it in a child variable
        }else{
            child=new TrieNode(word[0]);  //if Word Does Not Exist than create a new Node and add it to the root node.
            root->children[index]=child;
        }

        //Recursive Call
        string temp=word.substr(1);
        insertWord(child,temp);
    }

    void insert(string word){ //This Is For Naive User We can Directly call by Passing Root;
       insertWord(root,word);
    }

};


int main(){

}