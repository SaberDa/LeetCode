#include <isotream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(NULL), right(NULL) {}
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {} 
};

class Solution {
private:
    int height(TreeNode *root) {
        if (!root) {
            return 0;
        }
        return max(height(root->left), height(root->right)) + 1;
    }
public:
    int diameterOfBinaryTree(TreeNode *root) {
        if (!root) {
            return 0;
        }
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        int leftDia = diameterOfBinaryTree(root->left);
        int rightDia = diameterOfBinaryTree(root->right);

        return max(leftHeight+rightHeight, max(leftDia, rightDia));
    }
};