#include<iostream>
#include<bits/stdc++.h>
using namespace std;

    void nQueenUtil(int j,int n,vector<int>&bored,vector<bool>&rows,vector<bool>&diag1,vector<bool>&diag2,vector<vector<int>> &res){
        if(j>n){
            res.push_back(bored);
            return;
        }
        for(int i = 1;i<=n;i++){
            if(!rows[i] && !diag1[i+j] && !diag2[i-j+n]){
                
                rows[i]=diag1[i+j]=diag2[i-j+n]=true;
                bored.push_back(i);
                
                nQueenUtil(j+1,n,bored,rows,diag1,diag2,res);
                
                bored.pop_back();
                rows[i]=diag1[i+j]=diag2[i-j+n]=false;
                
            }
        }
    }
    vector<vector<int>> nQueen(int n) {
        vector<vector<int>> res;
        vector<int> bored;
        vector<bool> rows(n+1,false);
        vector<bool> diag1(2*n+1,false);
        vector<bool> diag2(2*n+1,false);
        nQueenUtil(1,n,bored,rows,diag1,diag2,res);
        return res;
    }

    int main() {
    int n = 4;
    vector<vector<int>> res = nQueen(n);

    for (int i = 0; i < res.size(); i++) {
        cout << "[";
        for (int j = 0; j < n; ++j) {
            cout << res[i][j];
            if (j != n - 1)
                cout << " ";
        }
        cout << "]\n";
    }
    return 0;
}