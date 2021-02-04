class Solution {
public:

    unordered_map<TreeNode*, vector<TreeNode*>> mp;

    void build(TreeNode* parent, TreeNode *child) {
        if (parent) {
            mp[parent].push_back(child);
            mp[child].push_back(parent);
        }
        if (child->left) build(child, child->left);
        if (child->right) build(child, child->right);
    }

    vector<int> distanceK(TreeNode *root, TreeNode *target, int K) {
        build(NULL, root);
        unordered_set<TreeNode*> dict;
        vector<TreeNode*> stack;
        vector<int> res;
        stack.push_back(target);
        dict.insert(target);
        int step = 0;
        while (step < K && !stack.empty()) {
            vector<TreeNode*> temp;
            for (auto x : stack) {
                for (auto it : mp[x]) {
                    if (!dict.count(it)) {
                        dict.insert(it);
                        temp.push_back(it);
                    }
                }
            }
            step++;
            stack = temp;
        }
        for (auto it : stack) res.push_back(it->val);
        return res;
    }
};