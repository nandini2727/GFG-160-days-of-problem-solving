#include<iostream>
#include<bits/stdc++.h>
using namespace std;

 void genPermutation(int n,string &curr,unordered_map<char,int> &cnt, vector<string> &res){
    if(curr.size()==n){ 
    res.push_back(curr);
    return;
    }
    for(pair<char,int>it:cnt){
    char c=it.first;
    int count=it.second;
    if(count==0)
        continue;
    curr.push_back(c);
    cnt[c]--;
    genPermutation(n,curr,cnt,res);
    curr.pop_back();
    cnt[c]++;
    }

}
vector<string> findPermutation(string &s) {
    vector<string> res;
    unordered_map<char,int> cnt;
    
    for(char c:s)
        cnt[c]++;
    string curr="";
    genPermutation(s.size(),curr,cnt,res);
    return res;
}

int main() {
    string s = "ABC";
    vector<string> res = findPermutation(s);

    for (string perm: res)
        cout << perm << " ";

    return 0;
}