#include <isotream>
#include <vector>
#include <string>

using namespace std;

vector<string> restoreIpAddress(string s) {
    vector<string> res;
    helper(res, s, 0, "", 0);
    return res;
}

void helper(vector<string>& res, string s, int pos, string temp, int count) {
    if (count > 4) {
        return;
    }
    if (pos >= s.size()) {
        if (count == 4) {
            temp.pop_back();
            res.push_back(temp);
        }
        return;
    }
    if ((s[pos] != '0') && (pos < s.size() - 2) && (stoi(s.substr(pos, 3)) < 256)) {
        helper(res, s, pos + 3, temp + s.substr(pos, 3) + ".", count + 1);
    }
    if ((s[pos]!= '0') && (pos < s.size() - 1)) {
        helper(res, s, pos + 2, temp + s.substr(pos, 2) + ".", count + 1);
    }
    helper(res, s, pos + 1, temp + s.substr(pos, 1) + ".", count + 1);
}