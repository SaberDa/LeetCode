#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

struct TrieNode {
    bool isWord;
    TrieNode* next[26];
    TrieNode(): isWord(false) {
        memset(next, NULL, sizeof(next));
    }
};

class MagicDictionary {
private:
    TrieNode* root;

    void buildTree(string s) {
        TrieNode *node = root;
        for (auto c : s) {
            if (!node->next[c - 'a']) node->next[c - 'a'] = new TrieNode();
            node = node->next[c - 'a'];
        }
        node->isWord = true;
    }

    bool find(TrieNode* node, string s) {
        for (auto c : s) {
            if (node->next[c - 'a']) node = node->next[c - 'a'];
            else return false;
        }
        return node->isWord;
    }

public:
    /** Initialize your data structure here. */
    MagicDictionary() {
        root = new TrieNode();
    }

    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict) {
        for (string s : dict) buildTree(s);
    }

    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(string word) {
        TrieNode *node = root;
        for (int i = 0; i < word.size(); i++) {
            char c = word[i];
            for (int j = 0; j < 26; j++) {
                if (node->next[j] == node->next[c - 'a']) continue;
                if (node->next[j] && find(node->next[j], word.substr(i + 1))) return true;
            }
            if (node->next[c - 'a']) node = node->next[c - 'a'];
        }
        return false;
    }
};