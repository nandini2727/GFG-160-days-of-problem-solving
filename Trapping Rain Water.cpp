#include<iostream>
#include<bits/stdc++.h>
using namespace std;

 int maxWater(vector<int> &arr) {
       int n=arr.size();
       int res= 0;
       int left=1,right=n-2;
       int lmax=arr[0],rmax=arr[n-1];
       while(left<=right){
           if(rmax<=lmax){
               res+=max(0,rmax-arr[right]);
               if(arr[right]>rmax)
                 rmax=arr[right];
               right--;
           }
           else{
               res+=max(0,lmax-arr[left]);
               if(arr[left]>lmax) lmax=arr[left];
               left++;
           }
       }
      return res;
    }
int main(){

    vector<int> a ={3, 0, 1, 0, 4, 0, 2};
    cout<<maxWater(a);
    return 0;
}
    