
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int res = 0;

void DFS(TreeNode* node, int sum) {
    if (!node) return;
    if (node->val == sum) res++;
    DFS(node->left, sum - node->val);
    DFS(node->right, sum - node->val);
}

int pathSum(TreeNode* root, int sum) {
    if (root) {
        DFS(root, sum);
        pathSum(root->left, sum);
        pathSum(root->right, sum);
    }
    return res;
}