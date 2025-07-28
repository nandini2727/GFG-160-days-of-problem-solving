#include<iostream>
#include<bits/stdc++.h>
using namespace std;

 vector<double> getMedian(vector<int> &arr) {
        priority_queue<int> maxHeap;
        priority_queue<int,vector<int>,greater<int>> minHeap;
        vector<double> res;
        
        for(int i=0;i<arr.size();i++){
            maxHeap.push(arr[i]);
            
            int temp = maxHeap.top();
            maxHeap.pop();
            minHeap.push(temp);
            
            if(minHeap.size() > maxHeap.size()){
                int temp = minHeap.top();
                minHeap.pop();
                maxHeap.push(temp);   
            }
            
            double median;
            
            if(maxHeap.size() != minHeap.size())
                median = maxHeap.top();
            else
                median = double (maxHeap.top()+minHeap.top())/2;
            
            res.push_back(median);
        }
        return res;
    }

int main() {
    vector<int> arr = {5, 15, 1, 3, 2, 8};
    vector<double> res = getMedian(arr);
    cout << fixed << setprecision(2);
    
    for (double median: res) 
        cout << median << " ";
    return 0;
}