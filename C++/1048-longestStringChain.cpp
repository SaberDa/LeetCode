class Solution {
public:
    int longestStrChain(vector<string> &words) {
        auto comp = [](string &a, string &b){ return a.size() < b.size(); };
        sort(words.begin(), words.end(), comp);
        unordered_map<string, int> dp;
        int res = 0;
        for (auto s : words) {
            for (int i = 0; i < s.size(); i++) {
                string temp = s.substr(0, i) + s.substr(i + 1);
                dp[s] = max(dp[s], dp.find(temp) == dp.end() ? 1 : dp[temp] + 1);
            }
            res = max(res, dp[s]);
        }
        return res;
    }
};