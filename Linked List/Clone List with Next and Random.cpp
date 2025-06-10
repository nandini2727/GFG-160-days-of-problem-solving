#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *next, *random;
    Node(int x) {
        data = x;
        next = random = NULL;
    }
};

Node* cloneLinkedList(Node* head) {
    if (head == NULL) {
        return NULL;
    }
    Node *curr= head;
        while(curr!=NULL){
            Node* newNode=new Node(curr->data);
            newNode->next=curr->next;
            curr->next=newNode;
            curr=newNode->next;
        }
        curr=head;
        while(curr!=NULL){
            if(curr->random != NULL){
                curr->next->random=curr->random->next;
            }
            curr=curr->next->next;
        }
        Node* cloneHead=head->next;
        curr=head;
        Node* cloneCurr = curr->next;
        while(cloneCurr->next!=NULL){
            curr->next=curr->next->next;
            cloneCurr->next=cloneCurr->next->next;
            curr=curr->next;
            cloneCurr=cloneCurr->next;
        }
        curr->next=NULL;
        
        return cloneHead;
}


// Function to print the linked list
void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << "(";
      	if(head->random)
          	cout << head->random->data << ")";
      	else 
          	cout << "null" << ")";
        
      	if(head->next != NULL)
          	cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
  
    // Creating a linked list with random pointer
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->random = head->next->next;
    head->next->random = head;
    head->next->next->random = head->next->next->next->next;
    head->next->next->next->random = head->next->next;
    head->next->next->next->next->random = head->next;
  
    // Print the original list
    cout << "Original linked list:\n";
    printList(head);
  
    // Function call
    Node* clonedList = cloneLinkedList(head);
  
    cout << "Cloned linked list:\n";
    printList(clonedList);
  
    return 0;
}