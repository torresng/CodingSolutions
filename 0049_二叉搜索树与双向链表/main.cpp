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
    TreeNode *convert(TreeNode *root) {
        if (!root) {
            return NULL;
        }
        auto sides = dfs(root);
        return sides.first;
    }

    pair<TreeNode *, TreeNode *> dfs(TreeNode *root) {
        if (!root->left && !root->right) {
            return {root, root};
        }
        if (root->left && root->right) {
            auto lsides = dfs(root->left), rsides = dfs(root->right);
            lsides.second->right = root, root->left = lsides.second;
            root->right = rsides.first, rsides.first->left = root;
            return {lsides.first, rsides.second};
        }
        if (root->left) {
            auto lsides = dfs(root->left);
            lsides.second->right = root, root->left = lsides.second;
            return {lsides.first, root};
        }
        if (root->right) {
            auto rsides = dfs(root->right);
            root->right = rsides.first, rsides.first->left = root;
            return {root, rsides.second};
        }
    }
};
