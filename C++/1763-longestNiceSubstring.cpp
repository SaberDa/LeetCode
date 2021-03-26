class Solution {
public:
    string longestNiceSubstring(string s) {
        string res = "";
        int length = 0;
        for (int i = 0; i < s.size(); i++) {
            vector<bool> upper(26), lower(26);
            for (int j = i; j < s.size(); j++) {
                if (isupper(s[j])) upper[s[j] - 'A'] = true;
                else lower[s[j] - 'a'] = true;
                int cur = j - i + 1;
                if (cur > length) {
                    int k = 0;
                    while (k < 26) {
                        if (upper[k] != lower[k]) break;
                        k++;
                    }
                    if (k == 26) {
                        length = cur;
                        res = s.substr(i, length);
                    }
                }
            }
        }
        return res;
    }
};