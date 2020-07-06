#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void DFS(TreeNode *node, TreeNode *cur, int len, int& res) {
    if (!cur) return;
    len = (node && cur->val == node->val + 1) ? len + 1 : 1;
    res = max(res, len);
    DFS(cur, cur->left, len, res);
    DFS(cur, cur->right, len, res);
}

int longestConsecutive(TreeNode *root) {
    int res = 0;
    DFS(NULL, root, 0, res);
    return res;
}