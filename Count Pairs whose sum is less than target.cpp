#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int countPairs(vector<int> &arr, int target) {
        sort(arr.begin(),arr.end());
        int res=0,n=arr.size();
        int left=0,right=n-1;
        while(left< right){
            int sum=arr[left]+arr[right];
            if(sum>=target)
                right--;
            else if(sum < target){
                res+=right-left;
                left++;
            }
        }
        return res;
        
    }

int main(){
     vector<int> a ={7, 2, 5, 3};
    cout<<countPairs(a,8);
    return 0;
}