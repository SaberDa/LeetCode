#include <iostream>
#include <string>

using namespace std;

string minRemoveToMakeValid(string s) {
        int count = 0;
        string temp;
        string res;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                count++;
            } else if (s[i] == ')') {
                if (count == 0) {
                    continue;
                }
                count--;
            }
            temp += s[i];
        }
        for (int i = temp.size() - 1; i >= 0; i--) {
            if (temp[i] == '(' && count > 0) {
                count--;
                continue;
            }
            res += temp[i];
        }
        reverse(res.begin(), res.end());
        return res;
}