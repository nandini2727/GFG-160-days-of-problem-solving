#include<iostream>
#include<bits/stdc++.h>
using namespace std;

  bool isBalanced(string& k) {
        stack<char> st;
        for (int i=0;i<k.size();i++){
            if(k[i]=='('||k[i]=='{'||k[i]=='[')
                st.push(k[i]);
            else if(k[i]==')'){
                if(st.empty()||st.top() !='(') return false;
                st.pop();
            }
            else if(k[i]=='}'){
                if(st.empty()||st.top() !='{') return false;
                st.pop();
            }
            else if(k[i]==']'){
                if(st.empty()||st.top() !='[') return false;
                st.pop();
            }
        }
        if(st.empty())
            return true;
        else
            return false;
    }

    int main() {  
    string s = "{([])}";
    if (isBalanced(s))
        cout << "true";
    else
        cout << "false";
    return 0;
}