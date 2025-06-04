 #include <bits/stdc++.h>
 #include <iostream>
 using namespace std;

bool twoSum(vector<int>& arr, int target) {
    int n = arr.size();
    unordered_set<int> set;
    for (int i =0;i<n;i++){
        int complement = target - arr[i];
        if(set.find(complement) != set.end())
            return true;
        else
            set.insert(arr[i]);
    }
    return false;
    
}

int main(){
    vector<int> arr = {1, 4, 45, 6, 10, 8};
    cout << twoSum(arr,16) << endl;
    return 1;
}