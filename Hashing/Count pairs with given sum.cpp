 #include <bits/stdc++.h>
 #include <iostream>
 using namespace std;

int countPairs(vector<int> &arr, int target) {
    int n=arr.size(),count=0;
    unordered_map<int,int> map;
    for(int i =0;i<n;i++){
        int complement = target - arr[i];
        if(map.find(complement) != map.end())
            count +=map[complement];
        map[arr[i]]++;
    }
    return count;
}

int main(){
    vector<int> arr = {1,5,7,-1,5};
    cout << countPairs(arr,6) << endl;
    return 1;
}