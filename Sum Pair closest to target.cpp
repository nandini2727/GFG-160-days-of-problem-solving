#include<iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> sumClosest(vector<int>& arr, int target) {
        sort(arr.begin(),arr.end());
        vector<int> res;
        int n=arr.size();
        int left =0, right=n-1, minDiff=INT_MAX;
        while(left<right){
            int sum=arr[left]+arr[right];
            
            if(abs(target-sum)<minDiff){
                minDiff=abs(target-sum);
                res={arr[left],arr[right]};
            }
            if(sum>target)
                right--;
            else if(sum< target)
                left++;
            else 
               return res;
            
        }
        return res;
    }

int main(){
    vector<int> a ={10, 30,20,5};
    for (int idx : sumClosest(a,25)) {
       
            cout << idx << " ";    
    }
    return 0;
}