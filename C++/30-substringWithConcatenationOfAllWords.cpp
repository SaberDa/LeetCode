#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        if (words.empty()) {
            return res;
        }
        unordered_map<string, int> counts;
        unordered_map<string, int> recode;
        for (auto str : words) {
            counts[str]++;
        }
        int len = words[0].size();
        int num = words.size();
        int limit = s.size();
        for (int i = 0; i < len; i++) {
            int left = i;
            int sum = 0;
            recode.clear();
            for (int j = i; j <= limit - len; j += len) {
                string word = s.substr(j, len);
                if (counts.count(word)) {
                    recode[word]++;
                    sum++;
                    while (recode[word] > counts[word]) {
                        recode[s.substr(left, len)]--;
                        sum--;
                        left += len;
                    }
                    if (sum == num) {
                        res.push_back(left);
                    }
                } else {
                    recode.clear();
                    sum = 0;
                    left = j + len;
                }
            }
        }
        return res;
}