#include<iostream>
#include<bits/stdc++.h>
using namespace std;

 vector<int> productExceptSelf(vector<int>& arr) {
        int n=arr.size();
        int prod=1,zeros=0,idx;
        for(int i=0;i<n;i++){
            if(arr[i]== 0){
                zeros++;
                idx=i;
            }
            else
                prod*=arr[i];
        }
        vector<int> prefixSum(arr.size(),0);
        if(zeros==0)
            for(int i=0;i<n;i++)
                prefixSum[i]=prod/arr[i];
        else if (zeros==1)
            prefixSum[idx] = prod;
        return prefixSum;
        
    }

    int main() {
    vector<int> arr = {10, 3, 5, 6, 2};
    vector<int> res = productExceptSelf(arr);

    for (int val : res)
        cout << val << " ";
}