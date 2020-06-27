#include <iostream>
#include <queue>
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
        if (!root) return "NULL,";
        return to_string(root->val) + "," + serialize(root->left) + serialize(root->right);
    }

    // Decodes your encoded data to tree
    TreeNode* deserialize(string data) {
        queue<string> q;
        string s;
        for (int i = 0; i < data.size(); i++) {
            if (data[i] == ',') {
                q.push(s);
                s = "";
                continue;
            }
            s += data[i];
        }
        if (s.size()) q.push(s);
        return helper(q);
    }

    TreeNode* helper(queue<string>& q) {
        string s = q.front();
        q.pop();
        if (s == "NULL") return NULL;
        TreeNode *node = new TreeNode(stoi(s));
        node->left = helper(q);
        node->right = helper(q);
        return node;
    }
};