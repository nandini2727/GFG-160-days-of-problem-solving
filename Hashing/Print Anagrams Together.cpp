#include<iostream>
#include <bits/stdc++.h>
using namespace std;

 string getHash(string str){
      string key;
      const int MAX_CHAR=26;
      vector<int> freq(MAX_CHAR,0);
      for(char ch: str)
            freq[ch-'a'] +=1;
      for(int i=0;i<MAX_CHAR;i++){
          key.append(to_string(freq[i]));
          key.append("$");
      }
      return key;
}
vector<vector<string>> anagrams(vector<string>& arr) {
    vector<vector<string>> res;
    unordered_map<string,int> map;
    for(int i =0;i<arr.size();i++){
        string key = getHash(arr[i]);
        if(map.find(key) == map.end()){
            map[key]=res.size();
            res.push_back({});
        }
        res[map[key]].push_back(arr[i]);
    }
    return res;
}

int main(){

    vector<string> arr = {"act", "god", "cat", "dog", "tac"};
    vector<vector<string>> triplets = anagrams(arr);

    for (const auto &triplet : triplets) {
        for (string idx : triplet) {
            cout << idx << " ";
        }
        cout << endl;
    }
    return 0;
}