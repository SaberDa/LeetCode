#include <iostream>
#include <stack>

using namespace std;

int calculate(string s) {
    stack<int> nums;
    int res = 0, temp = 0;
    char sign = '+';
    for (int i = 0; i < s.size(); i++) {
        if (isdigit(s[i])) {
            temp = temp * 10 + (s[i] - '0');
        }
        if (!isdigit(s[i]) && !isspace(s[i]) || i == s.size() - 1) {
            if (sign == '+') {
                nums.push(temp);
            } else if (sign == '-') {
                nums.push(-temp);
            } else if (sign == '*') {
                temp *= nums.top();
                nums.pop();
                nums.push(temp);
            } else if (sign == '/') {
                temp = nums.top() / temp;
                nums.pop();
                nums.push(temp);
            }
            sign = s[i];
            temp = 0;
        }
    }
    while (!nums.empty()) {
        res += nums.top();
        nums.pop();
    }
    return res;
}