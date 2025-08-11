#include<iostream>
#include<bits/stdc++.h>
using namespace std;

 int maxLength(string& s) {
        stack<int> st;
        st.push(-1);
        int maxlen=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(')
                st.push(i);
            else{
                st.pop();
                if(st.empty()){
                    st.push(i);
                }
                else{
                    maxlen=max(maxlen,i-st.top());
                }
            }
            
        }
        return maxlen;
    }

    int main() {
    string s = ")()())"; 
    cout << maxLength(s) << endl;

    return 0;
}