#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int maxLen(vector<int> &arr) {
        // Your code here
        int n=arr.size();
        unordered_map<int,int> map;
        int prefSum=0,res=0;
        for(int i=0;i<n;i++){
            prefSum+=arr[i]==0?-1:1;
            if(prefSum==0)
                res=i+1;
            if(map.find(prefSum)!=map.end())
                res=max(res,i-map[prefSum]);
            else
                map[prefSum]=i;
        }
        return res;
    }

int main() {
    vector<int> arr = {1, 0, 0, 1, 0, 1, 1};
  
    cout << maxLen(arr) << endl;
    return 0;
}