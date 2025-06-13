 #include<iostream>
#include<bits/stdc++.h>
using namespace std;

int countFreq(vector<int>& arr, int target) {
        int count=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]==target)
                count++;
        }
        return count;
    }
    
int main() {
    vector<int> arr = {1, 2, 2, 2, 2, 3, 4, 7, 8, 8};
    int target = 2;
    cout<< countFreq(arr, target);
    return 0;
}