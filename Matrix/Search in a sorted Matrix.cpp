#include<iostream>
#include<bits/stdc++.h>
using namespace std;

 bool searchMatrix(vector<vector<int>> &mat, int x) {
        int n= mat.size(), m =mat[0].size();
        int lo=0, hi= n*m-1;
        while(lo<=hi){
            int mid = (lo+hi)/2;
            int row=mid/m;
            int col=mid%m;
            if(x==mat[row][col])
                return true;
            else if(x<mat[row][col])
                hi=mid-1;
            else 
                lo=mid+1;
        }
        return false;
        
    }

int main() {
    vector<vector<int>> mat = {{1, 5, 9}, {14, 20, 21}, {30, 34, 43}};
    int x = 14;

    if (searchMatrix(mat, x))
        cout << "true";
    else
        cout << "false";

    return 0;
}