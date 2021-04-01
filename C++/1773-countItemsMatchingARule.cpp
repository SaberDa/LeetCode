class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int count = -1;
        if (ruleKey == "type") count = 0;
        else if (ruleKey == "color") count = 1;
        else if (ruleKey == "name") count = 2;
        int res = 0;
        for (auto it : items) {
            if (it[count] == ruleValue) res++;
        }
        return res;
    }
};