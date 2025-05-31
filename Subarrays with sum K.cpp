#include<iostream>
#include <bits/stdc++.h>
using namespace std;

int countSubarrays(vector<int> &arr, int k) {
    unordered_map<int,int> prefixSums;
    int res =0,currSum=0;
    for(int i=0;i<arr.size();i++){
        currSum+=arr[i];
        if(currSum==k)
            res++;
        if(prefixSums.find(currSum-k) !=prefixSums.end())
            res+=prefixSums[currSum-k];
        
        prefixSums[currSum]++;
    }
    return res;
}

int main(){
    vector<int> a ={10, 2, -2, -20, 10};
    cout<<countSubarrays(a,-10);
    return 0;
}