#include <iostream>
#include <vector>
#include <deque>

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {} 
};

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if (!root) {
            return res;
        }
        deque<TreeNode*> curLevel;
        deque<TreeNode*> nextLevel;
        curLevel.push_back(root);

        while (!curLevel.empty()) {
            TreeNode *temp = curLevel.front();
            curLevel.pop_front();
            
            if (temp->left) {
                nextLevel.push_back(temp->left);
            }
            if (temp->right) {
                nextLevel.push_back(temp->right);
            }

            if (curLevel.empty()) {
                res.push_back(temp->val);
                swap(curLevel, nextLevel);
            }
        }

        return res;
    }
}