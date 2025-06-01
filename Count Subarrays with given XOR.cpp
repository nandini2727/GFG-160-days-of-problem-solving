#include<iostream>
#include<bits/stdc++.h>
using namespace std;
long subarrayXor(vector<int> &arr, int k) {
    unordered_map<int,int> map;
    int prefiXor =0,res=0;
    for(int val: arr){
        prefiXor ^=val;
        res=res+map[prefiXor ^ k];
        if(prefiXor==k)
            res++;
        map[prefiXor]++;
        
    }
    return  res;
}

int main(){
     vector<int> a ={10, 2, -2, -20, 10};
    cout<<subarrayXor(a,6);
    return 0;
}