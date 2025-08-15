#include<iostream>
#include<bits/stdc++.h>
using namespace std;

 vector<int> calculateSpan(vector<int>& arr) {
        // code here
        stack<int> st;
        vector<int> span;
        
        for(int i=0;i<arr.size();i++){
            while(!st.empty() && arr[st.top()] <=arr[i])
                st.pop();
            
            if(st.empty())
                span.push_back(i+1);
            else
                span.push_back(i-st.top());
            st.push(i);
        }
        return span;
    }

int main() {
    vector<int> arr = {10, 4, 5, 90, 120, 80};
    vector<int> span = calculateSpan(arr);
     for (int x : span) {
        cout << x << " ";
    }
    return 0;
}