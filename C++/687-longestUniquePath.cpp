
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int DFS(TreeNode *node, int& res) {
    if (!node) return 0;
    int left = DFS(node->left, res);
    int right = DFS(node->right, res);
    if (!node->left || node->left->val != node->val) left = 0;
    if (!node->right || node->right->val != node->val) right = 0;
    res = max(res, left + right);
    return max(left, right) + 1;
}

int longestUnivaluePath(TreeNode* root) {
    int res = 0;
    DFS(root, res);
    return res;
}