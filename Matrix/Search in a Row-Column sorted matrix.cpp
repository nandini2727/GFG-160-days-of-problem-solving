#include<iostream>
#include<bits/stdc++.h>
using namespace std;

 bool matSearch(vector<vector<int>> &mat, int x) {
        int n=mat.size(),m=mat[0].size();
        int i=0,j=m-1;
        while(i<n && j>=0){
            if(x>mat[i][j]){
                i++;
            }
            else if(x<mat[i][j]){
                j--;
            }
            else{
                return true;
            }
        }
        return false;
    }

int main() {
    vector<vector<int>> mat = {{3, 30, 38},
                               {20, 52, 54},
                               {35, 60, 69}};
    int x = 35;
    if(matSearch(mat, x)) 
        cout << "true";
    else 
        cout << "false";
    return 0;
}