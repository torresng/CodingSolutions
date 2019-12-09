/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
  public:
    void mirror(TreeNode *root) {
        if (!root) {
            return;
        }
        mirror(root->left);
        mirror(root->right);
        swap(root->left, root->right);
    }
};
