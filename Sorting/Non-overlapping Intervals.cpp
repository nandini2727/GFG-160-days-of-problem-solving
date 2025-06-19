#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int minRemoval(vector<vector<int>> &intervals) {
        sort(intervals.begin(),intervals.end());
        int count=0;
        int end=intervals[0][1];
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]<end){
                count++;
                end=min(intervals[i][1],end);
            }
            else
                end=intervals[i][1];
        }
        return count;
    }

    int main() {
    vector<vector<int>> intervals = 
    				{{1, 2}, {2, 3}, {3, 5}, {1, 4}};
    cout << minRemoval(intervals) << endl;
}