#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int squaredDis(vector<int> arr){
    return arr[0]*arr[0] + arr[1]*arr[1];
}
vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    priority_queue<pair <int,vector<int>>> maxh;
    for(int i =0 ;i<points.size();i++){
        int dist = squaredDis( points[i]);
        if(maxh.size()<k){
            maxh.push({dist,points[i]});
            
        }else{
            if(dist< maxh.top().first){
                maxh.pop();
                maxh.push({dist,points[i]});
            }
        }
    }
    vector<vector<int>> res;
    while(!maxh.empty()){
        res.push_back(maxh.top().second);
        maxh.pop();
    }
    return res;
}

int main() {
    vector<vector<int>> points = {{1, 3}, {-2, 2}, 
                            {5, -1}, {3, 2}, {1, 1}};
    int k = 3;
    
    vector<vector<int>> res = kClosest(points, k);
    
    for (vector<int> point: res) {
        cout << "[" << point[0] << ", " << point[1] << "] ";
    }

    return 0;
}