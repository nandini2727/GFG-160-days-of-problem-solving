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


 int kthSmallest(Node *root, int k) {
        int cnt =0;
        Node *curr =root;
        while(curr!=nullptr){
            if(curr->left ==nullptr){
                cnt++;
                if(cnt == k) return curr->data;
                curr=curr->right;
            }
            else{
                Node *pre = curr->left;
                while(pre->right !=nullptr && pre->right != curr)
                    pre=pre->right;
                if(pre->right == nullptr){
                    pre->right=curr;
                    curr=curr->left;
                }
                else{
                    pre->right=nullptr;
                    cnt++;
                    if(cnt==k) return curr->data;
                    curr=curr->right;
                }
            }
            
        }
        return -1;
        
    }

    int main() {
    
    // Binary search tree
    //      20
    //    /   \
    //   8     22
    //  / \
    // 4   12
    //    /  \
    //   10   14
    Node* root = new Node(20);
    root->left = new Node(8);
    root->right = new Node(22);
    root->left->left = new Node(4);
    root->left->right = new Node(12);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(14);
    int k = 3;

    cout << kthSmallest(root, k) << endl;
    return 0;
}