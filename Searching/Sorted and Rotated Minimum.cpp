 #include<iostream>
#include<bits/stdc++.h>
using namespace std;

int findMin(vector<int>& arr) {
        int min=INT_MAX;
        for(int i=0;i<arr.size();i++){
            if(arr[i]<min)
                min=arr[i];
        }
        return min;
        
    }
    int main() {
    vector<int> arr = {5, 6, 1, 2, 3, 4};
    cout << findMin(arr) << endl;
    return 0;
}