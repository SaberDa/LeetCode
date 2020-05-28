#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* sortedArrayToBST(vector<int>& nums) {
    if (nums.empty()) {
        return NULL;
    }
    TreeNode *cur = new TreeNode(nums[nums.size() / 2]);
    vector<int> left(nums.begin(), nums.begin() + nums.size() / 2);
    vector<int> right(nums.begin() + nums.size() / 2 + 1, nums.end());
    cur->left = sortedArrayToBST(left);
    cur->right = sortedArrayToBST(right);
    return cur;
}