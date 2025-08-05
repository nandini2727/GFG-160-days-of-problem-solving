#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> nextLargerElement(vector<int>& arr) {
        stack<int> st;
        vector<int> res(arr.size(),-1);
        
        for(int i=arr.size()-1;i>=0;i--){
            while(!st.empty() && st.top()<=arr[i])
                st.pop();
            if(!st.empty()){
                res[i]=st.top();
            }
            st.push(arr[i]);
        }
        return res;
    } 

    int main() {

    vector<int> arr = {6, 8, 0, 1, 3};
    vector<int> res = nextLargerElement(arr);

    for (int x : res) {
        cout << x << " ";
    }

    return 0;
}