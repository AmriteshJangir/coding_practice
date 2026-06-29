class Solution {
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        if (root == NULL) return root;
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        while (!q.empty()) {
            int sz = q.size();
            vector<TreeNode*> nodes;
            vector<int> vals;
            for (int i = 0; i < sz; i++) {
                TreeNode* node = q.front();
                q.pop();
                if (level % 2 == 1) {
                    nodes.push_back(node);
                    vals.push_back(node->val);
                }
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            if (level % 2 == 1) {
                reverse(vals.begin(), vals.end());
                for (int i = 0; i < vals.size(); i++)
                    nodes[i]->val = vals[i];
            }
            level++;
        }
        return root;
    }
};