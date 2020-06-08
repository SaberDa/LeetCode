#include <iostream>
#include <vector>

using namespace std;

struct TrieNode {
    bool isWord;
    vector<TrieNode*> next;
    TrieNode():isWord(false) {
        next = vector<TrieNode*>(26, NULL);
    }
};

class Trie {
private:
    TrieNode *root;
    TrieNode* find(string s) {
        TrieNode *node = root;
        for (auto c : s) {
            if (!node->next[c - 'a']) return NULL;
            node = node->next[c - 'a'];
        }
        return node;
    }
public:
    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode *node = root;
        for (auto c : word) {
            if (!node->next[c - 'a']) {
                node->next[c - 'a'] = new TrieNode();
            }
            node = node->next[c - 'a'];
        }
        node->isWord = true;
    }

    bool search(string word) {
        TrieNode *node = find(word);
        return node && node->isWord;
    }

    bool startsWith(string prefix) {
        TrieNode *node = find(prefix);
        return node;
    }
};