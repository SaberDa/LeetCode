#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    struct TrieNode {
        bool isWord;
        TrieNode *next[26];
        TrieNode(): isWord(false) {
            memset(next, NULL, sizeof(next));
        }
    };

    TrieNode *root;

    void buildTree(string s) {
        TrieNode *node = root;
        for (auto c : s) {
            if (!node->next[c - 'a']) node->next[c - 'a'] = new TrieNode();
            node = node->next[c - 'a'];
        }
        node->isWord = true;
    }

public:

    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        root = new TrieNode();
        for (auto s : words) buildTree(s);
        vector<string> res;
        for (auto s : words) {
            int n = s.size();
            if (n == 0) continue;
            vector<bool> dp(n + 1, false);
            dp[0] = true;
            for (int i = 0; i < n; i++) {
                if (dp[i] == false) continue;
                TrieNode *node = root;
                for (int j = i; j < n; j++) {
                    if (!node->next[s[j] - 'a']) break;
                    node = node->next[s[j] - 'a'];
                    if (i == 0 && j == n - 1) continue;
                    if (node->isWord) dp[j + 1] = true;
                }
                if (dp[n]) {
                    res.push_back(s);
                    break;
                }
            }
        }
        return res;
    }

};