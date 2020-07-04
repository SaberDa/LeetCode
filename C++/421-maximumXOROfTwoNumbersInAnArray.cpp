#include <iostream>
#include <vector>

using namespace std;

struct TrieNode {
    TrieNode *next[2];
    TrieNode() {
        memset(next, NULL, sizeof(next));
    }
};

class Solution {
private:

    TrieNode *root;

    void buildTree(int num) {
        TrieNode *node = root;
        for (int i = 31; i >= 0; i--) {
            int index = ((num >> i) & 1);
            if (!node->next[index]) node->next[index] = new TrieNode();
            node = node->next[index];
        }
    }

    int calc(int num) {
        TrieNode *node = root;
        int res = 0;
        for (int i = 31; i >= 0; i--) {
            int index = ((num >> i) & 1) ? 0 : 1;
            if (node->next[index]) {
                res <<= 1;
                res |= 1;
                node = node->next[index];
            } else {
                res <<= 1;
                res |= 0;
                node = node->next[index ? 0 : 1];
            }
        }
        return res;
    }

public:

    int findMaximumXOR(vector<int>& nums) {
        int res = 0;
        root = new TrieNode();
        for (auto x : nums) buildTree(x);
        for (auto x : nums) {
            res = max(res, calc(x));
        }
        return res;
    } 

};