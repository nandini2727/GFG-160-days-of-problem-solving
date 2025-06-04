#include<iostream>
#include<bits/stdc++.h>
using namespace std;

 int countTriangles(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int res=0,n=arr.size();
        for(int i=2;i<n;i++){
            int left=0,right=i-1;
            while(left<right){
                if(arr[left]+arr[right]>arr[i])
                {
                    res+=right-left;
                    right--;
                }
                else
                    left++;
            }
        }
        return res;
    }
int main(){
    vector<int> a ={4, 6, 3, 7};
    cout<<countTriangles(a);
    return 0;

}