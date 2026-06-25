/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int dfs(TreeNode* root, int& cameras) {
        if (!root) return 2;
        int left = dfs(root->left, cameras);
        int right = dfs(root->right, cameras);
        if (left == 0 || right == 0) {
            cameras++;
            return 1;
        }
        if (left == 1 || right == 1) {
            return 2;
        }
        return 0;
    }
    int minCameraCover(TreeNode* root) {
        int cameras = 0;
        if (dfs(root, cameras) == 0) {
            cameras++;
        }
        return cameras;
    }
};