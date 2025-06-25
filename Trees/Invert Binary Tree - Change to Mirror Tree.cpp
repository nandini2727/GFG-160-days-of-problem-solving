#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int x) {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};

void mirror(Node* node) {
    if(node == nullptr)
        return;
    Node *temp=node->left;
    node->left=node->right;
    node->right=temp;
    
    mirror(node->left);
    mirror(node->right);
}


// Print tree as level order
void levelOrder(Node *root) {
    if (root == nullptr) {
      	cout << "N ";
      	return ;
    }

    queue<Node*> qq;
    qq.push(root);

    while (!qq.empty()) {
        Node *curr = qq.front();
        qq.pop();

        if (curr == nullptr) {
            cout << "N ";
            continue;
        }
        cout << (curr->data) <<  " ";
        qq.push(curr->left);
        qq.push(curr->right);
    }
}

int main() {

    // Input Tree:
    //       1
    //      / \
    //     2   3
    //    / \
    //   4   5
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    mirror(root);
  
    // Mirror Tree:
    //       1
    //      / \
    //     3   2
    //        / \
    //       5   4
    levelOrder(root);

    return 0;
}