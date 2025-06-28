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

Node *buildTreeRec(int left,int right,vector<int> &preorder,unordered_map<int,int> &map,int &index){
    if(left>right)
        return nullptr;
        
    int rootval=preorder[index];
    index++;
    
    Node *root=new Node(rootval);
    int num=map[rootval];
    
    root->left=(buildTreeRec(left,num-1,preorder,map,index));
    root->right=(buildTreeRec(num+1,right,preorder,map,index));
    
    return root;
    
}
Node *buildTree(vector<int> &inorder, vector<int> &preorder) {
    int index =0;
    unordered_map<int,int> map;
    int n=inorder.size();
    for(int i=0;i<n;i++){
        map[inorder[i]]=i;
    }
    Node *root = buildTreeRec(0,n-1,preorder,map,index);
    return root;
}


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


int main() {
    vector<int> inorder = {3, 1, 4, 0, 5, 2};
    vector<int> preorder = {0, 1, 3, 4, 2, 5};
    Node *root = buildTree(inorder, preorder);

    printLevelOrder(root);

    return 0;
}