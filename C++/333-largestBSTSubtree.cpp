#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool helper(TreeNode *node, int& res, int& minVal, int& maxVal) {
    if (!node) return true;
    int lmin = INT_MIN, lmax = INT_MAX, lCount = 0;
    bool left = helper(node->left, lCount, lmin, lmax);
    int rmin = INT_MIN, rmax = INT_MAX, rCount = 0;
    bool right = helper(node->right, rCount, rmin, rmax);

    if (left && right) {
        if ((!node->left || node->val > lmax) && (!node->right || node->val < rmin)) {
            res = lCount + rCount + 1;
            minVal = node->left ? lmin : node->val;
            maxVal = node->right ? rmax : node->val;
            return true;
        }
    }

    res = max(lCount, rCount);
    return false;
}

int largestBSTSubtree(TreeNode* root) {
    int res = 0;
    int minVal = INT_MIN, maxVal = INT_MAX;
    helper(root, res, minVal, maxVal);
    return res;
}