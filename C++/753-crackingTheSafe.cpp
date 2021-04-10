class Solution {
public:
    string crackSafe(int n, int k) {
        string ans;
        unordered_map<string, int> mp;
        for (int i = 0; i < n - 1; i++) {
            ans += '0';
        }
        for (int i = 0; i < pow(k, n); i++) {
            string temp = ans.substr(ans.size() - n + 1, n - 1);
            mp[temp] = (mp[temp] + 1) % k;
            ans += ('0' + mp[temp]);
        }
        return ans;
    }
};