#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> removeComments(vector<string>& source) {
    vector<string> res;
    bool flag = false;
    string temp = "";
    for (auto& s : source) {
        for (int i = 0; i < s.size();) {
            if (!flag) {
                if (i + 1 == s.size()) temp += s[i++];
                else {
                    string m = s.substr(i, 2);
                    if (m == "/*") {
                        flag = true;
                        i += 2;
                    } else if (m == "//") break;
                    else temp += s[i++];
                }
            } else {
                if (i + 1 == s.size()) i++;
                else {
                    string m = s.substr(i, 2);
                    if (m == "*/") {
                        flag = false;
                        i += 2;
                    } else i++;
                }
            }
        }
        if (temp.size() && !flag) {
            res.push_back(temp);
            temp = "";
        }
    }
    return res;
}