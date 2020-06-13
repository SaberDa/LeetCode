#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode() : val(0), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}    
};

int DFS(TreeNode* root, unordered_map<int, int>& mp) {
    if (!root) return 0;
    int l = DFS(root->left, mp);
    int r = DFS(root->right, mp);
    int sum = root->val + l + r;
    mp[sum]++;
    return sum;
}

vector<int> findFrequentTreeSum(TreeNode* root) {
    vector<int> res;
    if (!root) return res;
    unordered_map<int, int> mp;
    DFS(root, mp);
    int maxFreq = 0;
    for (auto x : mp) {
        if (x.second > maxFreq) {
            res.clear();
            res.push_back(x.first);
            maxFreq = x.second;
        } else if (x.second == maxFreq) 
            res.push_back(x.first);
    }
    return res;
}