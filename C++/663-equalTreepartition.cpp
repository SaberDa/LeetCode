#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int DFS(TreeNode *node, vector<int>& temp) {
    if (!node) return 0;
    int left = DFS(node->left, temp);
    int right = DFS(node->right, temp);
    int sum = node->val + left + right;
    temp.push_back(sum);
    return sum;
}

bool checkEqualTree(TreeNode* root) {
    if (!root) return false;
    vector<int> temp;
    int sum = DFS(root, temp);
    temp.pop_back();
    return (sum % 2 == 0) && find(temp.begin(), temp.end(), sum / 2) != temp.end();
}