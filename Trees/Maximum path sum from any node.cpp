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

 int maxSumutil(Node *root,int &res){
        if(!root)
            return 0;
        int l=max(0,maxSumutil(root->left,res));
        int r=max(0,maxSumutil(root->right,res));
        
        res=max(res,l+r+root->data);
        
        return root->data+max(l,r);
    }
    int findMaxSum(Node *root) {
        int res =root->data;
        
        maxSumutil(root,res);
        
        return res;
        
    }


int main() {
  	
	// Representation of input binary tree:
    //            10
    //           /  \
    //          2    10
    //         / \     \  
    //        20  1    -25
  	//                 /  \
  	//				  3	   4
    Node* root = new Node(10);
    root->left = new Node(2);
    root->right = new Node(10);
    root->left->left = new Node(20);
    root->left->right = new Node(1);
    root->right->right = new Node(-25);
    root->right->right->left = new Node(3);
    root->right->right->right = new Node(4);

    cout << findMaxSum(root);
    return 0;
}