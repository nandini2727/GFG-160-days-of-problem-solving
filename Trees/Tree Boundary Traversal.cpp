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

 bool isLeaf(Node *node){
        return (node->left==nullptr && node->right==nullptr);
    }
    
void collectLeftBoundary(Node *root,vector<int> &res){
        if(root == nullptr)
            return;
        Node *curr=root;
        while(!isLeaf(curr)){
            res.push_back(curr->data);
                
            if(curr->left != nullptr)
                curr=curr->left;
            else
                curr=curr->right;
            
        }
    }
    
    void collectLeafNodes(Node *root,vector<int> &res){
        
        Node *curr=root;
        while(curr){
            if(curr->left==nullptr){
                if(curr->right==nullptr){
                    res.push_back(curr->data);
                }
                curr=curr->right;
            }
            else{
                Node *prev =curr->left;
                while(prev->right && prev->right != curr){
                    prev=prev->right;
                }
                if(prev->right == nullptr){
                    prev->right=curr;
                    curr=curr->left;
                }
                else{
                    if(prev->left == nullptr){
                        res.push_back(prev->data);
                    }
                    prev->right=nullptr;
                    curr=curr->right;
                }
            }
        }
        
    }
    
    void collectRightBoundary(Node *root,vector<int> &res){
         
         if(root == nullptr)
            return;
            
         Node *curr=root;
         vector<int> temp;
          while(!isLeaf(curr)){
        
            temp.push_back(curr->data);
            
            if(curr->right != nullptr)
                curr=curr->right;
            else
                curr=curr->left;
            
        }
        for(int i=temp.size()-1;i>=0;i--)
          res.push_back(temp[i]);  
    }
    
    vector<int> boundaryTraversal(Node *root) {
      vector<int> res;
      if(!root)
        return res;
        
      if(!isLeaf(root))
        res.push_back(root->data);
        
      collectLeftBoundary(root->left,res);
      
      collectLeafNodes(root,res);
      
      collectRightBoundary(root->right,res);
        
      return res;
    
        
    }
    
int main() {

    // Hardcoded Binary tree
    //        20
    //       /  \
    //      8    22
    //     / \     \
    //    4   12    25
    //       /  \
    //      10   14
    Node *root = new Node(20);
    root->left = new Node(8);
    root->right = new Node(22);
    root->left->left = new Node(4);
    root->left->right = new Node(12);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(14);
    root->right->right = new Node(25);

    vector<int> boundary = boundaryTraversal(root);

    for (int x : boundary)
        cout << x << " ";

    return 0;
}