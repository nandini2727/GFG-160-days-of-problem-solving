#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> findTriplets(vector<int> &arr) {
    unordered_map<int,vector<vector<int>>> map;
    set<vector<int>> ans;
    
    int n=arr.size();
    for(int i = 0 ;i<n-1;i++){
        for(int j =i+1;j<n;j++){
            int sum =arr[i]+arr[j];
            map[sum].push_back({i,j});
        }
    }
    for(int i=0;i<n;i++){
        int rem=-arr[i];
        if(map.find(rem) != map.end()){
            for(auto j : map[rem])
                if(j[0] != i && j[1] != i)
                {
                    vector<int> curr = {i,j[0],j[1]};
                    sort(curr.begin(),curr.end());
                    ans.insert(curr);
                }
            
            
        }
    }
    
    return vector<vector<int>> (ans.begin(),ans.end());
}


int main(){

    vector<int> arr = {0, -1, 2, -3, 1};
    vector<vector<int>> triplets = findTriplets(arr);

    for (const auto &triplet : triplets) {
        for (int idx : triplet) {
            cout << idx << " ";
        }
        cout << endl;
    }
    return 0;
}