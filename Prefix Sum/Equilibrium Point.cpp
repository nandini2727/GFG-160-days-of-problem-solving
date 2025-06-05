#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int findEquilibrium(vector<int> &arr) {
        int prefixsum=0,tot=0 ,n=arr.size();
        for(int ele:arr)
            tot+=ele;
        for(int i=0;i<n;i++){
            int suffixSum=tot-prefixsum-arr[i];
            if(prefixsum==suffixSum)
                return i;
            prefixsum+=arr[i];
        }
        return -1;

    }

    int main() {
    vector<int> arr = { 1, 7, 3, 6, 5, 6 };

    cout << findEquilibrium(arr) << endl;
    return 0;
}
