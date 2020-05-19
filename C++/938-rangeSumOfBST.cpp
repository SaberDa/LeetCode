#include <iostream>
#include <vector>
#include <stack>

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
public:
    int rangeSumBST(TreeNode *root, int L, int R) {
        if (!root) {
            return 0;
        }
        int sum = rangeSumBST(root->left, L, R);
        if (root->val > R) {
            return sum;
        }
        if (root->val >= L) {
            sum += root->val;
        }
        sum += rangeSumBST(root->right, L, R);
        return sum;
    }

    int rangeSumBSTInOrder(TreeNode *root, int L, int R) {
        while (root && (root->val > R || root->val < L)) {
            if (root->val > R) {
                root = root->left;
            }
            if (root->val < L) {
                root = root->right;
            }
        }
        int sum = 0;
        stack<TreeNode*> st;
        while (root || st.size()) {
            while (root) {
                st.push(root);
                root = root->left;
            }
            root = st.top();
            st.pop();
            if (root->val > R) {
                break;
            }
            if (root->val >= L) {
                sum += root->val;
            }
            root = root->right;
        }
        return sum;
    }
};