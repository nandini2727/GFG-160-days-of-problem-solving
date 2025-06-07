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
  Node* sortedMerge(Node* head1, Node* head2) {
        if(head1 ==nullptr)
            return head2;
        else if(head2 == nullptr)
            return head1;
        Node *dummy=new Node(-1),*curr=dummy;
        while(head1 !=nullptr &&head2 != nullptr){
            if(head1->data <=head2->data){
                curr->next =head1;
                head1=head1->next;
            }
            else{
                curr->next =head2;
                head2=head2->next;
            }
            curr=curr->next;
        }
        if(head1 ==nullptr)
            curr->next=head2;
        else if (head2 ==nullptr )
            curr->next=head1;
        return dummy->next;

    }
void printList(Node *node) {
    while (node != nullptr) {
        cout << " " << node->data;
        node = node->next;
    }
}
 int main() {
  
    // First linked list: 5 -> 10 -> 15
    Node* head1 = new Node(5);
    head1->next = new Node(10);
    head1->next->next = new Node(15);

    // Second linked list: 2 -> 3 -> 20
    Node* head2 = new Node(2);
    head2->next = new Node(3);
    head2->next->next = new Node(20);

    Node* res = sortedMerge(head1, head2);
    printList(res);

    return 0;
}