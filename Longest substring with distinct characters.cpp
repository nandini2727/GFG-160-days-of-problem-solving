#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int longestUniqueSubstr(string &s) {
    int n=s.size();
    vector<int> lastindex(26,-1);
    int start=0,res=0;
    for(int end=0;end<n;end++){
        start=max(start,lastindex[s[end]-'a']+1);
        lastindex[s[end]-'a']=end;
        res=max(res,end-start+1);
        
    }
    return res;
}

int main(){
    string s ="geeksforgeeks";
    cout<<longestUniqueSubstr(s);
    return 0;

}