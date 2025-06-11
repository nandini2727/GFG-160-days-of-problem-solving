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

void removeLoop(Node* head) {
        Node *slow=head;
        Node *fast=head;
        while(fast && fast->next){
        
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast)
                break;
            
        }
        if(slow==fast){
            slow=head;
                if(slow==fast){
                    while(fast->next!=slow)
                        fast=fast->next;
                }
                else{
                    while(slow->next !=fast->next){
                        slow=slow->next;
                        fast=fast->next;
                    }
                }
            
            fast->next=nullptr;
        }
        
    }

    
void printList(Node *curr) {
    while (curr != nullptr) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}
int main() {
  

    Node *head = new Node(1);
    head->next = new Node(3);
    head->next->next = new Node(4);
  
	// Create a loop
    head->next->next->next = head->next;

    removeLoop(head);
    printList(head);

    return 0;
}