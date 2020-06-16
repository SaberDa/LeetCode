#include <iostream>
#include <unordered_map>
#include <vector>

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
    string ans = "";

    void buildTree(string& s) {
        TrieNode *node = root;
        for (auto c : s) {
            if (!node->next[c - 'a']) node->next[c - 'a'] = new TrieNode();
            node = node->next[c - 'a'];
        }
        node->isWord = true;
    }

    void DFS(TrieNode* node, string temp) {
        for (int i = 0; i < 26; i++) {
            if (node->next[i] && node->next[i]->isWord) {
                temp += (char)(i + 'a');
                if (temp.size() > ans.size()) ans = temp;
                else if (temp.size() == ans.size() && ans > temp) ans = temp;
                DFS(node->next[i], temp);
                temp.pop_back();
            }
        }
    }

public:
    string longestWord(vector<string>& words) {
        root = new TrieNode();
        for (auto s : words) buildTree(s);
        DFS(root, "");
        return ans;
    }
};

