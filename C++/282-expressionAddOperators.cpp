#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> addOperators(string num, int target) {
    vector<string> res;
    string path = "";
    backtrack(res, num, target, 0, 0, 0, path);
    return res;
}

void backtrack(vector<string>& res, string& num, int target, int pos,  long long sum, long long multiply, string& path) {
    if (pos == num.size()) {
        if (sum == target) {
            res.push_back(path);
        }
        return;
    }
    for (int i = pos; i < num.size(); i++) {
        string cur = num.substr(pos, i - pos + 1);
        if (cur[0] == '0' && cur.size() > 1) {
            continue;
        }
        long long curNum = stoll(cur.c_str());
        if (pos == 0) {
            path = cur;
            backtrack(res, num, target, i+1, curNum, curNum, path);
            path.clear();
        } else {
            path.push_back('+');
            path.append(cur);
            backtrack(res, num, target, i+1, sum + curNum, curNum, path);

            path[path.length() - cur.length() - 1] = '-';
            backtrack(res, num, target, i+1, sum - curNum, -curNum, path);

            path[path.length() - cur.length() - 1] = '*';
            backtrack(res, num, target, i+1, sum - multiply + multiply *curNum, multiply * curNum, path);

            path.erase(path.length() - cur.length() - 1);
        }
    }
}   
