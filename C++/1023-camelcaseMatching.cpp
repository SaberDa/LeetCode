#include <iostream>
#include <vector>

using namespace std;

struct TrieNode {
    bool isWord;
    TrieNode* next[52];
    TrieNode(): isWord(false) {
        memset(next, NULL, sizeof(next));
    }
};

class Solution {

    TrieNode *root;

    void buildTree(string s) {
        TrieNode *node = root;
        for (auto c : s) {
            if (c >= 'a' && c <= 'z') {
                if (!node->next[c - 'a']) node->next[c - 'a'] = new TrieNode();
                node = node->next[c - 'a'];
            } else {
                if (!node->next[c - 'A' + 26]) node->next[c - 'A' + 26] = new TrieNode();
                node = node->next[c - 'A' + 26];
            }
        }
        node->isWord = true;
    }

    bool findWord(string s) {
        TrieNode *node = root;
        for (auto c : s) {
            if (c >= 'a' && c <= 'z') {
                if (node->next[c - 'a']) node = node->next[c - 'a'];
            } else {
                if (!node->next[c - 'A' + 26]) return false;
                node = node->next[c - 'A' + 26];
            }
        }
        return node->isWord;
    }

public:

    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        root = new TrieNode();
        vector<bool> res;
        buildTree(pattern);
        for (auto q : queries) {
            res.push_back(findWord(q));
        }
        return res;
    }
};