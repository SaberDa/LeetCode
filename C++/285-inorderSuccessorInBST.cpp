#include <vector>
#include <queue>

using namespace std;


class Solution {
public:
    
    
    
    void BFS(TreeNode* root, vector<TreeNode*>& res) {
        if (!root) return;
        res.push_back(root);
        BFS(root->left, res);
        BFS(root->right, res);
    }
    
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        auto comp = [](TreeNode* a, TreeNode* b){return a->val > b->val;};
        priority_queue<TreeNode*, vector<TreeNode*>, decltype(comp)> pq(comp);
        vector<TreeNode*> res;
        BFS(root, res);
        for (auto it : res) pq.push(it);
        while (p != pq.top()) {
            pq.pop();
        }
        if (pq.size()) pq.pop();
        if (pq.empty()) return NULL;
        return pq.top();
    }
};