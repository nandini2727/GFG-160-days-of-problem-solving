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

vector<vector<int>> levelOrder(Node *root) {
        if(root ==nullptr)
            return {};
        queue<Node *> q;
        vector<vector<int>> res;
        q.push(root);
        int curr_level=0;
        while(!q.empty()){
            int len =q.size();
            res.push_back({});
            for(int i=0;i<len;i++){
                Node *node =q.front();
                q.pop();
                res[curr_level].push_back(node->data);
                
                if(node->left !=nullptr)
                    q.push(node->left);
                    
                if(node->right !=nullptr)
                    q.push(node->right);
                    
            }
            curr_level++;
        }
        return res;
    }
int main() {
    //      5
    //     / \
    //   12   13
    //   /  \    \
    //  7    14   2
    // /  \   /  \  / \
    //17 23 27  3  8  11

    Node *root = new Node(5);
    root->left = new Node(12);
    root->right = new Node(13);

    root->left->left = new Node(7);
    root->left->right = new Node(14);

    root->right->right = new Node(2);

    root->left->left->left = new Node(17);
    root->left->left->right = new Node(23);

    root->left->right->left = new Node(27);
    root->left->right->right = new Node(3);

    root->right->right->left = new Node(8);
    root->right->right->right = new Node(11);

    vector<vector<int>> res = levelOrder(root);

    for (vector<int> level : res) {
        cout << "[";
        for (int i = 0; i < level.size(); i++) {
            cout << level[i];
            if (i < level.size() - 1) cout << ", ";
        }
        cout << "] ";
    }

    return 0;
}