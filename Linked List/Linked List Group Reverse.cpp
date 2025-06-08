#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node *next;

    Node(int new_data) {
        data = new_data;
        next = nullptr;
    }
};
  Node *reverseKGroup(Node *head, int k) {
        if(head ==nullptr)
            return head;
        Node* newHead=nullptr;
        Node* curr=head;
        Node* tail=nullptr;
        while(curr !=nullptr){
            Node* groupHead=curr;
            Node* prev = nullptr;
            Node* nextNode = nullptr;
            int count=0;
            while(curr !=nullptr && count<k){
                nextNode = curr->next;
                curr->next = prev;
                prev=curr;
                curr=nextNode;
                count++;
            }
            if(newHead==nullptr)
                newHead =prev;
            if(tail != nullptr)
                tail->next=prev;
            tail=groupHead;
            
        }
        return newHead;   
    }
void printList(Node *node) {
    while (node != nullptr) {
        cout << " " << node->data;
        node = node->next;
    }
}
 int main() {
  
    // First linked list: 5 -> 10 -> 15
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    head = reverseKGroup(head, 3);
    printList(head);

    return 0;
}