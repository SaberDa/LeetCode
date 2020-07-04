#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct TrieNode {
    int sum;
    TrieNode *next[26];
    TrieNode() : sum(0) {
        memset(next, NULL, sizeof(next));
    }
};

class MapSum {
private:

    TrieNode *root;
    unordered_map<string, int> mp;

public:

    MapSum() {
        root = new TrieNode();
    }

    void insert(string key, int val) {
        bool change = false;
        if (mp.count(key)) change = true;
        TrieNode *node = root;
        for (auto c : key) {
            if (!node->next[c - 'a']) node->next[c - 'a'] = new TrieNode();
            node = node->next[c - 'a'];
            node->sum += change ? val - mp[key] : val;
        }
        mp[key] = val;
    }

    int sum(string prefix) {
        TrieNode *node = root;
        for (auto c : prefix) {
            if (!node->next[c - 'a']) return 0;
            node = node->next[c - 'a'];
        }
        return node->sum;
    }
};