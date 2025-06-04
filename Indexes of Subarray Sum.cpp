#include<iostream>
#include<bits/stdc++.h>
using namespace std;

 vector<int> subarraySum(vector<int> &arr, int target) {
        int s=0,e=0,n=arr.size();
        vector<int> res;
        int currSum=0;
        for(int i=0;i<n;i++){
            currSum+=arr[i];
            if(currSum>=target){
                e=i;
                while(currSum >target && s < e){
                    currSum-=arr[s];
                    s++;
                }
                if(currSum ==target){
                    res.push_back(s+1);
                    res.push_back(e+1);
                    return res;
                }
            }
            
        }
        return {-1};
    }
int main(){
vector<int> arr = {15, 2, 4, 8, 9, 5, 10, 23};
    int target = 23;
    vector<int> res = subarraySum(arr, target);
    for (int ele : res)
        cout << ele << " ";
    return 0;
}