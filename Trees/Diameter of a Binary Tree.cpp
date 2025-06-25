#include<iostream>
#include<bits/stdc++.h>
using namespace std;


class Node {
public:
    int data;
    Node *left, *right;
    Node(int x) {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};

int diametercal(Node *root,int &res){
        if(root==nullptr){
            return 0;
        }
        int lheight=diametercal(root->left,res);
        int rheight=diametercal(root->right,res);
        
        res=max(res,lheight+rheight);
        
        return 1+ max(lheight,rheight);
    }
    
int diameter(Node* root) {
    int res=0;
    diametercal(root,res);
    return res;
}

int main() {

    // Constructed binary tree is
    //          5
    //        /   \
    //       8     6
    //      / \   /
    //     3   7 9
    Node* root = new Node(5);
    root->left = new Node(8);
    root->right = new Node(6);
    root->left->left = new Node(3);
    root->left->right = new Node(7);
  	root->right->left = new Node(9);
    cout << diameter(root) << endl;
  
    return 0;
}