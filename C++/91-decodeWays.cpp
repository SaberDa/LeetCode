#include <iostream>
#include <string>
#include <vector>

using namespace std;

int numDecodings(string s) {
    if (s.empty()) {
        return 1;
    }
    int n = s.size();
    vector<int> dp(n + 1, 0);
    dp[n] = 1;
    dp[n - 1] = (s[n-1] == '0') ? 0 : 1;
    for (int i = n - 2; i >= 0; i--) {
        if (s[i] == '0') {
            dp[i] = 0;
        } else if (s[i] == '1' || (s[i] == '2' && s[i+1] <= '6')) {
            dp[i] = dp[i + 1] + dp[i + 2];
        } else {
            dp[i] = dp[i + 1];
        }
    }
    return dp[0];
}