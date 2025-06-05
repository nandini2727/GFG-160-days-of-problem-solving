#include<iostream>
#include<bits/stdc++.h>
using namespace std;

 int maxWater(vector<int> &arr) {
        int n=arr.size();
        int left =0 ,right=n-1;
        int res =0;
        while(left<right){
            int maxWat = min(arr[left],arr[right]) * (right-left);
            res=max(res,maxWat);
            if(arr[left]<=arr[right])
                left++;
            else
                right--;
        }
        return res;
    }
int main(){

    vector<int> a ={1, 5, 4, 3};
    cout<<maxWater(a);
    return 0;
}