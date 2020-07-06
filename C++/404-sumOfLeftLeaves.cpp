#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void DFS(TreeNode *node, int& sum) {
    if (!node) return;
    if (node->left) {
        if (!node->left->left && !node->left->right) sum += node->left->val;
    }
    DFS(node->left, sum);
    DFS(node->right, sum);
}

int sumOfLeftLeaves(TreeNode *root) {
    int sum = 0;
    DFS(root, sum);
    return sum;
}