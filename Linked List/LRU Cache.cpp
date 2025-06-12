#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Node{
    int key;
    int value;
    Node *next;
    Node *prev;
    
    Node(int key,int value){
        this->key=key;
        this->value=value;
        next=nullptr;
        prev=nullptr;
    }
};

class LRUCache {
  private:
    int capacity;
    unordered_map<int,Node*> cache;
    Node* head;
    Node* tail;
  public:
    LRUCache(int cap) {
        capacity=cap;
        head = new Node(-1,-1);
        tail=new Node(-1,-1);
        head->next=tail;
        tail->prev=head;
        
    }

    int get(int key) {
    
        if(cache.find(key)==cache.end())    
            return -1;
        Node *node=cache[key];
        removeNode(node);
        addNode(node);
        return node->value;
        
    }
    void put(int key, int value) {
        if(cache.find(key)!=cache.end()){
            Node *oldNode=cache[key];
            removeNode(oldNode);
            delete oldNode;
        }
        Node *newNode=new Node(key,value);
        cache[key]=newNode;
        addNode(newNode);
        if(cache.size()>capacity){
            Node *nodeDelete=tail->prev;
            cache.erase(nodeDelete->key);
            removeNode(nodeDelete);
            delete nodeDelete;
        }
    }
    void addNode(Node* node){

        node->prev=head;
        node->next=head->next;
        head->next=node;
        node->next->prev=node;
    }
    void removeNode(Node *node){
        Node *prevNode=node->prev;
        Node *nextNode=node->next;
        prevNode->next=nextNode;
        nextNode->prev=prevNode;

    }
};
 int main(){
    LRUCache cache(2);
  
    cache.put(1, 1); 
    cache.put(2, 2);
    cout << cache.get(1) << endl;
    cache.put(3, 3);
    cout  << cache.get(2) << endl;
    cache.put(4, 4);
    cout << cache.get(1) << endl;
    cout << cache.get(3) << endl;
    cout << cache.get(4) << endl;

    return 0;
}