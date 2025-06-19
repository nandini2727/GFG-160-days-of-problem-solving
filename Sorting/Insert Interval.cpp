#include<iostream>
#include<bits/stdc++.h>
using namespace std;

 vector<vector<int>> mergeInterval(vector<vector<int>>&intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>res;
        res.push_back(intervals[0]);
        for(int i=1;i<intervals.size();i++){
            vector<int>& last=res.back();
            vector<int>& curr=intervals[i];
            if(curr[0]<=last[1])
                last[1]=max(last[1],curr[1]);
            else
                res.push_back(curr);
        }
        return res;
    }
    vector<vector<int>> insertInterval(vector<vector<int>> &intervals,
                                       vector<int> &newInterval) {
        intervals.push_back(newInterval);
        return mergeInterval(intervals);
    }
  int main() {
    vector<vector<int>> intervals = {{1, 3}, {4, 5}, {6, 7}, {8, 10}};
    vector<int> newInterval = {5, 6};
    
    vector<vector<int>> res = insertInterval(intervals, newInterval);
  	for (vector<int> interval: res) {
      	cout << interval[0] << " " << interval[1] << "\n";
    }
    return 0;
}