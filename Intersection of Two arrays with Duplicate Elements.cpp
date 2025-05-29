#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> intersectionWithDuplicates(vector<int>& a, vector<int>& b) {
        unordered_set<int> se(a.begin(),a.end());
        vector<int> ans ;
        for(int i=0;i<b.size();i++){
            if(se.find(b[i]) != se.end()){
                ans.push_back(b[i]);
                se.erase(b[i]);
            }
        }
        return ans;
    }

int main(){
    vector<int> a ={1, 2, 1, 3, 1};
    vector<int> b ={3, 1, 3, 4, 1};
    for (int idx : intersectionWithDuplicates(a,b)) {
       
            cout << idx << " ";    
    }
    return 0;
}