class Solution {
public:

    struct TreeNode {
        int sum;
        int val;

        TreeNode *left, *right;

        TreeNode(int x, int y) : val(x), sum(y), left(NULL), right(NULL) {}
    };

    TreeNode *buildTree(TreeNode *node, int i, int val, int count, vector<int> &res) {
        if (!node) {
            node = new TreeNode(val, 1);
            res[i] = count;
            return node;
        }
        if (val > node->val) node->right = buildTree(node->right, i, val, count + node->sum, res);
        else {
            node->sum++;
            node->left = buildTree(node->left, i, val, count, res);
        }
        return node;
    }

    vector<int> countSmaller(vector<int> &nums) {
        vector<int> res(nums.size());
        if (nums.empty()) return res;
        TreeNode *root = NULL;
        for (int i = nums.size() - 1; i >= 0; i--) root = buildTree(root, i, nums[i], 0, res);
        return res;
    }

};