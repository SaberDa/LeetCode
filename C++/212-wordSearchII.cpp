#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct TrieNode {
    string word;
    TrieNode* next[26];
};

TrieNode *root;

void buildTree(vector<string>& words) {
    root = new TrieNode();
    for (auto x : words) {
        TrieNode *node = root;
        for (auto c : x) {
            if (!node->next[c - 'a']) node->next[c - 'a'] = new TrieNode();
            node = node->next[c - 'a'];
        }
        node->word = x;
    }
}

void backTrack(vector<vector<char>>& board, vector<string>& res, TrieNode* node, int r, int c, int m, int n) {
    if (r < 0 || c < 0 || r == m || c == n || board[r][c] == '0' || !node->next[board[r][c] - 'a']) {
        return;
    }
    node = node->next[board[r][c] - 'a'];
    if (node->word.size() > 0) {
        res.push_back(node->word);
        node->word = "";
    }
    char temp = board[r][c];
    board[r][c] = '0';
    backTrack(board, res, node, r, c + 1, m, n);
    backTrack(board, res, node, r, c - 1, m, n);
    backTrack(board, res, node, r + 1, c, m, n);
    backTrack(board, res, node, r - 1, c, m, n);
    board[r][c] = temp;
}

vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    vector<string> res;
    if (board.empty() || words.empty()) {
        return res;
    }
    buildTree(words);
    int m = board.size();
    int n = board[0].size();
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            backTrack(board, res, root, i, j, m, n);
        }
    }
    return res;
}