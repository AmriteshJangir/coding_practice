// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//  * };
//  */

// class Solution {
// public:
//     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//         if (!root) return NULL;
//         TreeNode* curr = root;
//         while (curr) {
//             if (p->val < curr->val && q->val < curr->val) {
//                 curr = curr->left;
//             }
//             else if (p->val > curr->val && q->val > curr->val) {
//                 curr = curr->right;
//             }
//             else{
//                 return curr;
//             }
//         }
//         return NULL;
//     }
// };
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (p->val < root->val && q->val < root->val) {
            return lowestCommonAncestor(root->left, p, q);
        }
        if (p->val > root->val && q->val > root->val) {
            return lowestCommonAncestor(root->right, p, q);
        }
        return root;
    }
};