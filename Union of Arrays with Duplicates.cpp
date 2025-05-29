#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int findUnion(vector<int>& a, vector<int>& b) {
        unordered_set<int> se(a.begin(),a.end());
        se.insert(b.begin(),b.end());
        return se.size();
        
}
int main(){
    vector<int> a ={1, 2, 1, 3, 1};
    vector<int> b ={3, 1, 3, 4, 1};
    cout<<findUnion(a,b);
    return 0;
}
