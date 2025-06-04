#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void setMatrixZeroes(vector<vector<int>> &mat) {
        int n= mat.size();
        int m = mat[0].size();
        int c1=1;
        for(int i = 0; i<n;i++){
            for(int j = 0;j<m;j++){
                if(mat[i][j] == 0){
                    mat[i][0]=0;
                    if(j==0)
                        c1=0;
                    else
                        mat[0][j]=0;
                }
            }
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(mat[0][j]==0|| mat[i][0]==0)
                    mat[i][j]=0;
            }
        }
        if(mat[0][0]==0)
            for(int j = 0;j<m;j++)
                mat[0][j]=0;
        if(c1==0)
            for(int i = 0 ;i<n;i++)
                mat[i][0]=0;
    }

    int main() {
    vector<vector<int> > mat = { { 0, 1, 2, 0 },
                                 { 3, 4, 0, 2 },
                                 { 1, 3, 1, 5 } };

    setMatrixZeroes(mat);
    for (int i = 0; i < mat.size(); i++) {
        for (int j = 0; j < mat[0].size(); j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}