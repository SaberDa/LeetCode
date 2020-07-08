#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res = "";
        vector<TreeNode*> cur;
        cur.push_back(root);
        while (!cur.empty()) {
            vector<TreeNode*> next;
            for (auto node : cur) {
                res += (node == NULL ? "" : to_string(node->val)) + ",";
                if (node != NULL) {
                    next.push_back(node->left);
                    next.push_back(node->right);
                }
            }
            swap(cur, next);
        }
        while (!res.empty() && res.back() == ',') res.pop_back();
        return res;
    }

    TreeNode *helper(string& s, int& i) {
        string val;
        while (i < s.size() && s[i] != ',') val += s[i++];
        i++;
        return val.empty() ? NULL : new TreeNode(stoi(val));
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        TreeNode root;
        vector<TreeNode*> cur;
        cur.push_back(&root);
        data = "," + data;
        int i = 0;
        while (!cur.empty()) {
            vector<TreeNode*> next;
            for (auto node : cur) {
                if (node != NULL) {
                    next.push_back(node->left = helper(data, i));
                    next.push_back(node->right = helper(data, i));
                }
            }
            swap(cur, next);
        }
        return root.right;
    }

};