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

 int sumKutils(Node *node,int k,int currSum,unordered_map<int,int> &map){
        if(node==nullptr)
            return 0;
        currSum+=node->data;
        int preCount=0;
        if(currSum==k)
            preCount++;
        preCount+=map[currSum-k];
        map[currSum]++;
        
        preCount+=sumKutils(node->left,k,currSum,map);
        preCount+=sumKutils(node->right,k,currSum,map);
        
        map[currSum]--;
        
        return preCount;
    }
    int sumK(Node *root, int k) {
       unordered_map<int,int> map;
       int res = sumKutils(root,k,0,map);
        return res;
    }

    int main() {
  
    // Create a sample tree:
    //        8
    //      /  \
    //     4    5
    //    / \    \
    //   3   2    2
	//  / \   \
    // 3  -2   1

    Node* root = new Node(8);
    root->left = new Node(4);
    root->right = new Node(5);
    root->left->left = new Node(3);
    root->left->right = new Node(2);
    root->right->right = new Node(2);
  	root->left->left->left = new Node(3);
  	root->left->left->right = new Node(-2);
    root->left->right->right = new Node(1);

    int k = 7; 

    cout << sumK(root, k) << endl;
    return 0;
}