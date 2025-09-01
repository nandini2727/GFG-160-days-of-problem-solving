#include <iostream>
#include <stack>
#include <string>
using namespace std;

string decodedString(string &s) {
    stack<int> numStack;
    stack<char> charStack;
    string temp = "";
    string res = "";

    for (int i = 0; i < s.length(); i++) {
        int cnt = 0;
      

        if (s[i] >= '0' && s[i] <= '9') {
            while (s[i] >= '0' && s[i] <= '9') {
                cnt = cnt * 10 + s[i] - '0';
                i++;
            }
            i--;
            numStack.push(cnt);
        }
        
        else if (s[i] == ']') {
            temp = "";

            cnt = numStack.top();
            numStack.pop();

            while (charStack.top() != '[') {
                temp = charStack.top() + temp;
                charStack.pop();
            }
            charStack.pop();

            
            for (int j = 0; j < cnt; j++)
                res = res.append(temp);

            
            for (int j = 0; j < res.length(); j++)
                charStack.push(res[j]);

            res = "";
        }
        else
            charStack.push(s[i]);
    }

    while (!charStack.empty()) {
        res = charStack.top() + res;
        charStack.pop();
    }

    return res;
}

int main() {
    string s = "3[b2[ca]]";
    cout << decodedString(s) << endl;
    return 0;
}