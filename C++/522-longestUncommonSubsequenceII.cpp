#include <string>
#include <vector>

using namespace std;

bool judge(string a, string b) {
    if (a.length() > b.length()) return false;
    int j = 0;
    for (int i = 0; i < b.size() && j < a.size(); i++) {
        if (a[j] == b[i]) j++;
    }
    return j == a.size();
}

int findLUSlength(vector<string> &strs) {
    int res = -1;
    for (int i = 0, j; i < strs.size(); i++) {
        for (j = 0; j < strs.size(); j++) {
            if (j == i) continue;
            if (judge(strs[i], strs[j])) break;
        }
        if (j == strs.size()) res = max(res, strs[i].size());
    }
    return res;
}