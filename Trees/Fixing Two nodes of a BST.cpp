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

void inorderTraversal(Node *root,Node * &first,Node * &middle,Node * &last,Node * &prev){
        if(root ==nullptr)
            return;
        inorderTraversal(root->left,first, middle,last,prev);
        
        if(prev && root->data < prev->data){
            if(!first){
                first=prev;
                middle =root;
            }
            else{
                last = root;
            }
        }
        prev=root;
        inorderTraversal(root->right,first, middle,last,prev);
    }
    void correctBST(Node* root) {
        Node *first =nullptr  , *middle =nullptr,*last =nullptr,*prev =nullptr;
        inorderTraversal(root,first, middle, last,prev);
        
        if(first && last)
            swap(first->data,last->data);
        else if(first && middle)
            swap(first->data,middle->data);
    }

// Print tree as level order
void printLevelOrder(Node *root) {
    if (root == nullptr) {
        cout << "N ";
        return;
    }

    queue<Node *> qq;
    qq.push(root);
    int nonNull = 1;

    while (!qq.empty() && nonNull > 0) {
        Node *curr = qq.front();
        qq.pop();

        if (curr == nullptr) {
            cout << "N ";
            continue;
        }
        nonNull--;

        cout << (curr->data) << " ";
        qq.push(curr->left);
        qq.push(curr->right);
        if (curr->left)
            nonNull++;
        if (curr->right)
            nonNull++;
    }
}
int main(){
  
    // Constructing the tree with swapped nodes
    //       6
    //     /  \
    //    10   2
    //   / \  / \
    //  1  3 7  12
    // Here, 10 and 2 are swapped
  
    Node *root = new Node(6);
    root->left = new Node(10);
    root->right = new Node(2);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->right = new Node(12);
    root->right->left = new Node(7);

    correctBST(root);
    printLevelOrder(root);
 
    return 0;
}