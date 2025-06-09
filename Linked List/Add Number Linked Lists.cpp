#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node *next;
    Node(int val) {
        data = val;
        next = nullptr;
    }
};
 Node* trimmingZeros(Node *head){
      while(head->next !=nullptr && head->data == 0){
          head=head->next;
      }
      return head;
  }
  Node* reverse(Node* head){
      Node* prev=nullptr;
      Node* nextNode=nullptr;
      Node* curr=head;
      while(curr !=nullptr){
          nextNode=curr->next;
          curr->next=prev;
          prev=curr;
          curr=nextNode;
      }
      return prev;
  }
  int findLength(Node* head){
        int count=0;
        Node* curr=head;
        while(curr !=nullptr){
            curr=curr->next;
            count++;
        }
        return count;
  }
    Node* addTwoLists(Node* num1, Node* num2) {
        num1=trimmingZeros(num1);
        num2=trimmingZeros(num2);
        int carry=0;
        int len1=findLength(num1);
        int len2 =findLength(num2);
        if(len1<len2)
            return addTwoLists(num2,num1);
        num1=reverse(num1);
        num2=reverse(num2);
        Node* res =num1;
        while(num2 !=nullptr || carry!=0)
        {
            num1->data+=carry;
            if(num2 != nullptr){
                num1->data+=num2->data;
                num2=num2->next;
            }
            carry=num1->data/10;
            num1->data%=10;
            if(num1->next==nullptr && carry !=0){
                num1->next=new Node(0);
            }
            num1=num1->next;
        }
        return reverse(res);
    }

    void printList(Node *head) {
    Node *curr = head;
    while (curr != nullptr) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << "\n";
}

    int main() {

    // Creating first linked list: 1 -> 2 -> 3
    // (represents 123)
    Node *num1 = new Node(1);
    num1->next = new Node(2);
    num1->next->next = new Node(3);

    // Creating second linked list: 9 -> 9 -> 9
    // (represents 999)
    Node *num2 = new Node(9);
    num2->next = new Node(9);
    num2->next->next = new Node(9);

    Node *sum = addTwoLists(num1, num2);
    printList(sum);

    return 0;
}