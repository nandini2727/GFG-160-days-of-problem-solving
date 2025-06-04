#include<iostream>
#include <bits/stdc++.h>
using namespace std;

int longestConsecutive(vector<int>& arr) {
    unordered_set<int> set;
    int res = 0;
    for(int var : arr)
        set.insert(var);
    for(int var :arr){
        if(set.find(var)!=set.end() && set.find(var-1)==set.end()){
            int curr=var,cnt=0;
            while(set.find(curr)!= set.end()){
                set.erase(curr);
                cnt++;
                curr++;
            }
            res=max(res,cnt);
        }
    }
    return res;
}

int main(){
    vector<int> a ={3, 1, 3, 4, 5, 1};
    cout<<longestConsecutive(a);
    return 0;
}