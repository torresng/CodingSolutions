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
    bool hasSubtree(TreeNode *pRoot1, TreeNode *pRoot2) {
        if (!pRoot1 || !pRoot2) {
            return false;
        }
        if (isPart(pRoot1, pRoot2)) {
            return true;
        }
        return hasSubtree(pRoot1->left, pRoot2) ||
               hasSubtree(pRoot1->right, pRoot2);
    }

    bool isPart(TreeNode *p1, TreeNode *p2) {
        if (!p2) {
            return true;
        }
        if (!p1 || p1->val != p2->val) {
            return false;
        }
        return isPart(p1->left, p2->left) && isPart(p1->right, p2->right);
    }
};
