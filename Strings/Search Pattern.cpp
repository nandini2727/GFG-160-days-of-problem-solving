#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> search(string &pat, string &txt) {
    vector<int> res;
    int n = txt.size();
    int m = pat.size();

    for (int i = 0; i <= n - m; i++) {
        int j = 0;

        // compare pattern with substring 
        // starting at index i
        while (j < m && txt[i + j] == pat[j]) {
            j++;
        }

        // if full pattern matched
        if (j == m) {
            res.push_back(i);
        }
    }

    return res;
}

int main() {
    string txt = "aabaacaadaabaaba";
    string pat = "aaba";

    vector<int> res = search(pat, txt);
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << " ";

    return 0;
}