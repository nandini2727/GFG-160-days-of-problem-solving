 #include<iostream>
#include<bits/stdc++.h>
using namespace std;

int kthElement(vector<int>& a, vector<int>& b, int k) {
        int n=a.size(),m=b.size();
        
        int last = 0;
        int i=0,j=0;
        for(int d=0;d<k;++d){
            if(i<n){
                if(j<m && a[i] > b[j]){
                    last=b[j];
                    j++;
                }
                else{
                    last = a[i];
                    i++;
                }
            }
            else if(j<m){
                last=b[j];
                j++;
            }
        }
        return last;
            
    }
    int main() {
    vector<int> a = {2, 3, 6, 7, 9};
    vector<int> b = {1, 4, 8, 10};
    int k = 5;

    cout << kthElement(a, b, k);
    return 0;
}