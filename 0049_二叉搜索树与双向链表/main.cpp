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
    TreeNode* convert(TreeNode* root) {
        if(root == nullptr) { return root; }
        auto sides = dfs(root);
        return sides.first;
    }
    pair<TreeNode*, TreeNode*> dfs(TreeNode *root) {
        if(root->left && root->right) { 
            auto lsides = dfs(root->left);
            auto rsides = dfs(root->right);
            lsides.second->right = root, root->left = lsides.second;
            rsides.first->left = root, root->right = rsides.first;
            return {lsides.first, rsides.second};
        }
        if(root->left) {
            auto lsides = dfs(root->left);
            lsides.second->right = root, root->left = lsides.second;
            return {lsides.first, root};
        }
        if(root->right) {
            auto rside = dfs(root->right);
            rsides.first->left = root, root->right = rsides.first;
            return {root, rsides.second};
        }
        return {root, root};
    }
};s
