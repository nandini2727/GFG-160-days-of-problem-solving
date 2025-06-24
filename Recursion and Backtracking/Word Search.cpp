#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool findWord(vector<vector<char>> &mat,string &word, int i, int j, int wIdx){
        int wlen=word.length();
        int n =mat.size();
        int m =mat[0].size();
        if(wIdx ==wlen)
            return true;
        if(i<0||j<0||i>=n||j>=m)
            return false;
        if(mat[i][j] == word[wIdx]){
            char temp = mat[i][j];
            mat[i][j] = '#';
            
            bool res=findWord(mat,word,i-1,j,wIdx+1)||
                    findWord(mat,word,i+1,j,wIdx+1)||
                    findWord(mat,word,i,j-1,wIdx+1)||
                    findWord(mat,word,i,j+1,wIdx+1);
            mat[i][j]=temp;
            return res;
        }
        return false;
    }
bool isWordExist(vector<vector<char>>& mat, string& word) {
    int wlen=word.length();
    int n =mat.size();
    int m =mat[0].size();
    
    if(wlen> n*m)
        return false;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mat[i][j]== word[0]){
                if(findWord(mat,word,i,j,0))
                    return true;
            }
        }
    }
    return false;
}
int main() {
    vector<vector<char>> mat = { {'a', 'x', 'm', 'y'}, 
                                  {'b', 'g', 'd', 'f'}, 
                                  {'x', 'e', 'e', 't'}, 
                                  {'r', 'a', 'k', 's'} };
  	string word = "geeks";	
    cout << (isWordExist(mat, word) ? "true" : "false");

    return 0;
}