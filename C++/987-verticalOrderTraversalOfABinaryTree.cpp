#include <iostream>
#include <vector>
#include <map>
#include <set>

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
    map<int, map<int, set<int>>> mp;
    void DFS(TreeNode *root, int x, int y, map<int, map<int, set<int>>>& mp) {
        if (root != nullptr) {
            mp[x][y].insert(root->val);
            DFS(root->left, x - 1, y + 1, mp);
            DFS(root->right, x + 1, y + 1, mp);
        }
    }
public:
    vector<vector<int>> verticalTraversal(TreeNode *root) {
        vector<vector<int>> res;
        if (!root) {
            return res;
        }
        DFS(root, 0, 0, mp);
        for (auto it : mp) {
            vector<int> temp;
            for (auto p : it.second) {
                temp.insert(temp.end(), p.second.begin(), p.second.end());
            }
            res.push_back(temp);
        }
        return res;
    }
};