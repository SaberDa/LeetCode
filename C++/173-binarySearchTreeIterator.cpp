#include <iostream>
#include <stack>

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {} 
};

class BSTIterator {
private:
    stack<TreeNode *> s;

    void load(stack<TreeNode*>& s, TreeNode *root) {
        if (!root) {
            return;
        }
        s.push(root);
        load(s, root->left);
    }

public:
    BSTIterator(TreeNode *root) {
        load(s, root);
    }   

    int next() {
        TreeNode *next = s.top();
        s.pop();
        if (next->right) {
            load(s, next->right);
        }
        return next->val;
    }

    bool hasNext() {
        if (!s.empty()) {
            return true;
        } else {
            return false;
        }
    }
};