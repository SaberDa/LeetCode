class Solution {
public:

    void DFS(TreeNode *node, int &sum) {
        if (!node) return;
        if (node->val % 2 == 0) {
            if (node->left) {
                if (node->left->left) sum += node->left->left->val;
                if (node->left->right) sum += node->left->right->val;
            }
            if (node->right) {
                if (node->right->left) sum += node->right->left->val;
                if (node->right->right) sum += node->right->right->val;
            }
        }
        DFS(node->left, sum);
        DFS(node->right, sum);
    }

    int sumEvenGrandparent(TreeNode* root) {
        if (!root) return NULL;
        int sum = 0;
        DFS(root, sum);
        return sum;
    }
};