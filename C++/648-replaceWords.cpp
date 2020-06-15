#include <iostream>
#include <string>

using namespace std;

struct TrieNode {
    bool isWord;
    TrieNode* next[26];
    TrieNode(): isWord(false) {
        memset(next, NULL, sizeof(next));
    }
};

class Solution {
private:
    TrieNode *root;

    void buildTree(string& s) {
        TrieNode *node = root;
        for (auto c : s) {
            if (!node->next[c - 'a']) node->next[c - 'a'] = new TrieNode();
            node = node->next[c - 'a'];
        }
        node->isWord = true;
    }

    pair<string, int> match(string& s, int pos) {
        int i = pos;
        TrieNode *node = root;
        while (i < s.size() && s[i] != ' ' && !node->isWord && node->next[s[i] - 'a']) {
            node = node->next[s[i] - 'a'];
            i++;
        }
        int j = i;
        while (i < s.size() && s[i] != ' ') i++;
        if (node->isWord) return {s.substr(pos, j - pos), i};
        return {s.substr(pos, i - pos), i};
    }

public:
    string replaceWords(vector<string>& dict, string sentence) {
        string res = "";
        if (dict.empty() || sentence.empty()) return res;
        root = new TrieNode();
        for (string& s : dict) buildTree(s);
        for (int i = 0; i < sentence.size();) {
            pair<string, int> nextWord = match(sentence, i);
            res += nextWord.first + " ";
            i = nextWord.second + 1;
        }
        res.pop_back();
        return res;
    }
};