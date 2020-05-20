#include <isotream>
#include <cmath>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    int DFS(TreeNode *root, int maxV, int minV) {
        int cur = root->val;
        int diff = max(abs(cur - maxV), abs(cur - minV));
        if (cur > maxV) {
            maxV = cur;
        }
        if (cur < minV) {
            minV = cur;
        }
        if (root->left) diff = max(diff, DFS(root->left, maxV, minV));
        if (root->right) diff = max(diff, DFS(root->right, maxV, minV));
        return diff;
    }
public:
    int maxAncestorDiff(TreeNode *root) {
        if (!root) {
            return 0;
        }
        int diff = 0;
        int maxV = root->val;
        int minV = root->val;

        if (root->left) diff = max(diff, DFS(root->left, maxV, minV));
        if (root->right) diff = max(diff, DFS(root->right, maxV, minV));
        return diff;
    }
};