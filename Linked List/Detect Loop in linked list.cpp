#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


bool detectLoop(Node* head) {
    int pos=1,flag=0;
    Node* slow=head;
    Node* fast=head;
    while(slow && fast && fast->next){
        slow=slow->next;
        fast=fast->next->next;
        
        if(slow==fast){
            slow=head;
            flag=1;
            break;
        }
        
    }
    if(!flag)
        return 0;
    while(slow !=fast){
        slow=slow->next;
        fast=fast->next;
        pos++;
    }
    return pos;
    
}

int main() {

    // Create a hard-coded linked list:
    // 1 -> 3-> 4
    Node* head = new Node(1);
    head->next = new Node(3);
    head->next->next = new Node(4);
  
	// Create a loop
    head->next->next->next = head->next;

    if (detectLoop(head))
        cout << "true";
    else
        cout << "false";

    return 0;
}