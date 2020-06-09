#include <iostream>
#include <stack>

using namespace std;

int calculate(string s) {
    stack<int> nums, op;
    int res = 0, sign = 1;
    for (int i = 0; i < s.size(); i++) {
        char c = s[i];
        if (isdigit(c)) {
            int num = c - '0';
            while (i + 1 < s.size() && isdigit(s[i + 1])) {
                num = 10 * num + (s[i + 1] - '0');
                i++;
            }
            res += num * sign;
        } else if (c == '+') {
            sign = 1;
        } else if (c == '-') {
            sign = -1;
        } else if (c == '(') {
            nums.push(res);
            op.push(sign);
            res = 0, sign = 1;
        } else if (c == ')') {
            res *= op.top();
            op.pop();
            res += nums.top();
            nums.pop();
        }
    }
    return res;
}