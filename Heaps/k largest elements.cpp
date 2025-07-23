#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> kLargest(vector<int>& arr, int k) {
    // Your code here
    priority_queue<int,vector<int>,greater<int>> minh(arr.begin(),arr.begin()+k);
    
    for(int i=k;i<arr.size();i++){
        if(minh.top() < arr[i]){
            minh.pop();
            minh.push(arr[i]);
        }
    }
    vector<int> res;
        while(!minh.empty()){
            res.push_back(minh.top());
            minh.pop();
        }
        reverse(res.begin(),res.end());
    return res;
    
}


int main() {
    vector<int> arr = {1, 23, 12, 9, 30, 2, 50};
    int k = 3;
  
  	vector<int> res = kLargest(arr, k);
  	for(int ele : res)
      	cout << ele << " ";
  	
  	return 0;
}