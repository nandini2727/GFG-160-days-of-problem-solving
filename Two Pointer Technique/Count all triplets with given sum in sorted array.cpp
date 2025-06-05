#include<iostream>
#include<bits/stdc++.h>
using namespace std; 
int countTriplets(vector<int> &arr, int target) {
        int res=0;
        int n=arr.size();
        for(int i=0;i<n-2;i++){
            int j=i+1,k=n-1;
            while(j<k){
                int sum=arr[i]+arr[j]+arr[k];
                if(sum < target)
                    j++;
                else if( sum > target)
                    k--;
                else if( sum == target)
                {
                    int ele1=arr[j],ele2=arr[k];
                    int cnt1=0, cnt2=0;
                    while(j<=k&&arr[j]==ele1){
                        j++;
                        cnt1++;
                    }
                    while(j<=k&&arr[k]==ele2){
                        k--;
                        cnt2++;
                    }
                    if(ele1==ele2)
                        res+=(cnt1 * (cnt1-1))/2;
                    else
                        res+=(cnt1 * cnt2);
                }
            }
        }
        return res;
    }
int main(){
    vector<int> arr={-3, -1, -1, 0, 1, 2};
    int target=-2;
    cout<<countTriplets(arr,target);
    return 0;
}