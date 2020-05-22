#include <iostream>
#include <vector>
#include <unordered_map>

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
    vector<TreeNode*> DFS(int l, int r) {
        vector<TreeNode*> res;
        if (l > r) {
            return {NULL};
        }
        for (int i = l; i <= r; i++) {
            auto left = DFS(l, i - 1);
            auto right = DFS(i + 1, r);
            for (auto x : left) {
                for (auto y : right) {
                    TreeNode* root = new TreeNode(i);
                    root->left = x;
                    root->right = y;
                    res.push_back(root);
                }
            }
        }
        return res;
    }
public:
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) {
            return {};
        }
        return DFS(1, n);
    }
};