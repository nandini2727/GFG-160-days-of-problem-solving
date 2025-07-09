#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};

bool isBST(Node* root) {
       Node* curr =root;
       Node *prev = nullptr;
       int prevValue=INT_MIN;
      while(curr !=nullptr){
          if(curr->left ==nullptr){
              if(curr->data<=prevValue){
                  return false;
              }
              prevValue=curr->data;
              curr=curr->right;
          }
          else{
              prev=curr->left;
              while(prev->right!=nullptr && prev->right!=curr){
                  prev=prev->right;
              }
              if(prev->right==nullptr){
                  prev->right=curr;
                  curr=curr->left;
              }
              else{
                  prev->right=nullptr;
                  if(curr->data <=prevValue)
                    return false;
                  prevValue=curr->data;
                  curr=curr->right;
              }
          }
      }
      return true;
}
int main() {
  
    // Create a sample binary tree
    //     10
    //    /  \
    //   5    20
    //        / \
    //       9   25

    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(20);
    root->right->left = new Node(9);
    root->right->right = new Node(25);

    if (isBST(root))
        cout << "True" << endl;
    else 
        cout << "False" << endl;

    return 0;
}