#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int getMin(string s) {
    return ((s[0] - '0') * 10 + (s[1] - '0')) * 60 + ((s[3] - '0') * 10 + (s[4] - '0'));
}

int findMinDifference(vector<string>& timePoints) {
    int ans = INT_MAX;
    vector<int> dp(timePoints.size() + 1);
    for (int i = 0; i < timePoints.size(); i++) {
        dp[i] = getMin(timePoints[i]);
    }
    sort(dp.begin(), dp.begin() + timePoints.size());
    dp[timePoints.size()] = dp[0] + getMin("24:00");
    for (int i = 1; i < dp.size(); i++) {
        ans = min(ans, dp[i] - dp[i - 1]);
    }
    return ans;
}