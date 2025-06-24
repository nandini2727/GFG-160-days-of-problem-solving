#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *left, *right;

    // Constructor to initialize a new node
    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

 int height(Node* node) {
       queue<Node *> q;
       int depth=0;
       int curr_level=0;
        q.push(node);
        while(!q.empty()){
            int len =q.size();
            for(int i=0;i<len;++i){
                Node *temp=q.front();
                q.pop();
                if(temp-> left !=nullptr)
                    q.push(temp->left);
                if(temp->right != nullptr)
                    q.push(temp->right);
            }
            curr_level++;
            depth++;
        }
        return depth-1;
    }

    int main() {
  
    // Representation of the input tree:
    //     12
    //    /  \
    //   8   18
    //  / \
    // 5   11
    Node *root = new Node(12);
    root->left = new Node(8);
    root->right = new Node(18);
    root->left->left = new Node(5);
    root->left->right = new Node(11);
    
    cout << height(root);
    
    return 0;
}