#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<TreeNode*> DFS(int l , int r) {
    vector<TreeNode*> res;
    if (l > r) {
        return {NULL};
    }
    for (int = l; i <= r; i++) {
        auto left = DFS(l, i-1);
        auto right = DFS(i + 1, r);
        for (auto x : left) {
            for (auto y : right) {
                TreeNode *root = new TreeNode(i);
                root->left = x;
                root->right = y;
                res.push_back(root);
            }
        }
    }
    return res;
}

int numTrees(int n) {
    if (n <= 1) {
        return n;
    }
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            dp[i] += dp[j] * dp[i - j - 1];
        }
    }
    return dp.back();
}