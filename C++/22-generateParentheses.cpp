#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> generateParenthesis(int n) {
        vector<string> res;
        if (n == 0) {
            return res;
        }
        helper(res, 1, 0, 1, "(", n);
        return res;
}

    void helper(vector<string>& res, int open, int close, int pos, string temp, int len) {
        if (pos == 2 * len) {
            res.push_back(temp);
            return;
        }
        if (open > close) {
            helper(res, open, close + 1, pos + 1, temp + ")", len);
        }
        if (open < len) {
            helper(res, open + 1, close, pos + 1, temp + "(", len);
        }
        return;
    }