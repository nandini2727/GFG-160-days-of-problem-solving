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


  bool dfs(Node *root,int target , unordered_set<int> &st){
        if(root == nullptr)
            return false;
        if(st.find(target - root->data) != st.end())
            return true;
        st.insert(root->data);
        
        return dfs(root->left,target,st)|| dfs(root->right,target,st);
    }
    bool findTarget(Node *root, int target) {
        unordered_set<int> st;
        return dfs(root, target, st);
    }

    
int main(){
    // Constructing the following BST:
    //         7
    //        / \
    //       3   8
    //      / \   \
    //     2   4   9

    Node *root = new Node(7);
    root->left = new Node(3);
    root->right = new Node(8);
    root->left->left = new Node(2);
    root->left->right = new Node(4);
    root->right->right = new Node(9);

    int target = 12;

    // Check if there are two elements in the BST
    // that added to "target"
    if (findTarget(root, target))
        cout << "True\n";
    else
        cout << "False\n";

    return 0;
}