class Solution {
public:
    bool isCousins(TreeNode *root, int x, int y) {
        deque<TreeNode*> cur, next;
        cur.push_back(root);
        bool siblings = false, cousin = false;
        while (!cur.empty() && !cousin) {
            while (!cur.empty()) {
                auto node = cur.front();
                cur.pop_front();
                if (node == NULL) siblings = false;
                else {
                    if (node->val == x || node->val == y) {
                        if (!cousin) cousin = siblings = true;
                        else return !siblings;
                    }
                    next.push_back(node->left);
                    next.push_back(node->right);
                    next.push_back(NULL);
                }
            }
            swap(cur, next);
        }
        return false;
    }
};