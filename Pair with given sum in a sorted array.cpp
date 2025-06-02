 #include<iostream>
#include <bits/stdc++.h>
using namespace std;
 int countPairs(vector<int> &arr, int target) {
        int n=arr.size();
        int res=0,left=0,right=n-1;
        while(left< right){
           
            if(arr[left]+arr[right] > target)
                right--;
            
            else if(arr[left]+arr[right] < target)
                left++;
            
            else{
                int cnt1=0,cnt2=0,ele1=arr[left],ele2=arr[right];
                while(left<= right && arr[left]==ele1){
                    left++;
                    cnt1++;
                }
                while(left<= right && arr[right]==ele2){
                    right--;
                    cnt2++;
                }
                if(ele1==ele2)
                    res+=(cnt1*(cnt1 -1))/2;
                else
                    res+=(cnt1*cnt2);
            }
        }
        return res; 
    }

int main(){
vector<int> a ={-1, 1, 5, 5, 7};
cout<<countPairs(a,6);
return 0;
}