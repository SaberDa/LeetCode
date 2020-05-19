#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <deque>

using namespace std;

bool isValid(string &s) {
    int sum = 0;
    for (auto i : s) {
        if (i == '(') {
            sum ++;
        } else if (i == ')') {
            sum--;
        }
        if (sum < 0) {
            return false;
        }
    }
    return sum == 0;
}

vector<string> removeInvalidParentheses(string s) {
    unordered_set<string> dic;
    vector<string> res;
    deque<string> cur;
    deque<string> next;
    
    cur.push_back(s);
    while (!cur.empty()) {
        s = cur.front();
        cur.pop_front();
        if (isValid(s)) {
            res.push_back(s);
            continue;
        }
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != '(' && s[i] != ')') {
                continue;
            }
            string temp = s.substr(0, i) + s.substr(i + 1);
            if (dic.count(temp) == 0) {
                next.push_back(temp);
                dic.insert(temp);
            }
        }
        if (cur.empty() && res.size() == 0) {
            swap(cur, next);
        }
    }

    return res;
}
