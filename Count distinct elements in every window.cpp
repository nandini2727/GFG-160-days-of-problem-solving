#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector<int> countDistinct(vector<int> &arr, int k) {
    int n=arr.size();
    vector<int> res;
    unordered_map<int,int> map;
    for(int i=0;i<k;i++){
        map[arr[i]]++;
    }
    res.push_back(map.size());
    for(int i=k;i<n;i++){
        map[arr[i]]++;
        map[arr[i-k]]--;
        if(map[arr[i-k]]==0)
            map.erase(arr[i-k]);
        res.push_back(map.size());
    }
    return res;
}

int main(){
vector<int> arr = {1, 2, 1, 3, 4, 2, 3};
    int target = 4;
    vector<int> res = countDistinct(arr, target);
    for (int ele : res)
        cout << ele << " ";
    return 0;
}