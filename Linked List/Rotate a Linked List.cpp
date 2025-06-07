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
  Node* rotate(Node* head, int k) {
        if(k==0 || head==nullptr)
            return head;
        Node *temp=head;
        int len=1;
        while(temp->next !=nullptr){
            temp=temp->next;
            len++;
        }
        k%=len;
        if(k==0)
            return head;
        temp->next=head;
        for(int i=1;i<=k;i++){
            temp=temp->next;
        }
        head=temp->next;
        temp->next=nullptr;
        return head;
    }

    
void printList(Node *node) {
    while (node != nullptr) {
        cout << " " << node->data;
        node = node->next;
    }
}
    int main() {

       // Create a hard-coded linked list:
    // 10 -> 20 -> 30 -> 40
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
  
    head = rotate(head, 6);
    printList(head);
    return 0;
}