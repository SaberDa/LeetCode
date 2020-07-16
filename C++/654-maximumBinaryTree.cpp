#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode *helper(vector<int>& nums, int l, int r) {
    if (l == r) return NULL;
    int maxPos = max_element(nums.begin() + l, nums.begin() + r) - nums.begin();
    TreeNode *node = new TreeNode(nums[maxPos]);
    node->left = helper(nums, l, maxPos);
    node->right = helper(nums, maxPos + 1, r);
    return node;
}

TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
    if (nums.empty()) return NULL;
    return helper(nums, 0, nums.size());
}