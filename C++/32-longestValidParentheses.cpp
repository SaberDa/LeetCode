#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int longestValidParentheses(string s) {
    if (s.empty()) return 0;
    stack<int> st;
    int n = s.size();
    vector<int> dp(n);
    int res = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') st.push(i);
        else {
            if (!st.empty()) {
                int index = st.top();
                st.pop();
                int len = i - index + 1;
                int temp = (index - 1 < 0) ? 0 : dp[index - 1];
                res = max(res, len + temp);
                dp[i] = len + temp;
            }
        }
    }
    return res;
}