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
    vector<vector<int>> printFromTopToBottom(TreeNode *root) {
        vector<vector<int>> res;
        if (!root) {
            return res;
        }

        queue<TreeNode *> q;
        q.push(root);
        q.push(nullptr);

        vector<int> level;
        while (q.size()) {
            auto t = q.front();
            q.pop();
            if (!t) {
                if (level.empty()) {
                    break;
                }
                res.push_back(level);
                level.clear();
                q.push(nullptr);
                continue;
            }
            level.push_back(t->val);
            if (t->left) {
                q.push(t->left);
            }
            if (t->right) {
                q.push(t->right);
            }
        }

        return res;
    }
};
