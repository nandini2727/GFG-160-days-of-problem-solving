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

void serializePreorder(Node *root, vector<int> &arr){
    if(root == nullptr){
        arr.push_back(-1);
        return;
    }
    arr.push_back(root->data);
    serializePreorder(root->left,arr);
    serializePreorder(root->right,arr);
}
vector<int> serialize(Node *root) {
    vector<int> arr;
    serializePreorder(root,arr);
    return arr;
}
Node *deSerializePreorder(int &i,vector<int> &arr){
    if(arr[i]==-1){
        i++;
        return nullptr;
    }
    Node *root = new Node(arr[i]);
    i++;
    
    root->left=deSerializePreorder(i,arr);
    root->right=deSerializePreorder(i,arr);
    
    return root;
}

// Function to deserialize a list and construct the tree.
Node *deSerialize(vector<int> &arr) {
    int i =0;
    return deSerializePreorder( i , arr);
    
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

int main() {

    // Create a hard coded tree
    //       10
    //     /    \
    //    20    30
    //  /   \
    // 40  60
    Node* root = new Node(10);        
    root->left = new Node(20);        
    root->right = new Node(30);       
    root->left->left = new Node(40);
    root->left->right = new Node(60); 
    
    vector<int> arr = serialize(root);
    Node* res = deSerialize(arr);
    
    printLevelOrder(res);
}