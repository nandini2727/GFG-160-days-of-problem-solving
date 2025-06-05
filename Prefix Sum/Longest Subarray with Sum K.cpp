#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int longestSubarray(vector<int>& arr, int k) {
        unordered_map<int,int> map;
        int res=0,n=arr.size(),prefSum=0;
        for(int i=0;i<n;i++){
            prefSum +=arr[i];
            if(prefSum == k)
                res=i+1;
            else if(map.find(prefSum-k) !=map.end())
                res=max(res,i-map[prefSum-k]);
            
            if(map.find(prefSum)==map.end())
                map[prefSum]=i;
        }
        return res;
        
}

int main() {
    vector<int> arr = {10, 5, 2, 7, 1, -10};
    int k = 15;
    cout << longestSubarray(arr, k) << endl;
}