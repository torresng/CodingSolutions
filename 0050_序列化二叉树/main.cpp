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
    // Encodes a tree to a single string.
    string serialize(TreeNode *root) {
        string res;
        dfs_s(root, res);
        return res;
    }

    void dfs_s(TreeNode *root, string &res) {
        if (!root) {
            res += "null ";
            return;
        }
        res += to_string(root->val) + ' ';
        dfs_s(root->left, res);
        dfs_s(root->right, res);
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data) {
        int u = 0;
        return dfs_d(data, u);
    }

    TreeNode *dfs_d(string data, int &u) {
        if (u == data.size()) {
            return NULL;
        }
        int k = u;
        while (data[k] != ' ') {
            k++;
        }
        if (data[u] == 'n') {
            u = k + 1;
            return NULL;
        }
        int val = 0, sign = 1;
        if (u < k && data[u] == '-') {
            sign = -1, u++;
        }
        for (int i = u; i < k; i++) {
            val = val * 10 + data[i] - '0';
        }
        val *= sign;
        u = k + 1;
        auto root = new TreeNode(val);
        root->left = dfs_d(data, u);
        root->right = dfs_d(data, u);
        return root;
    }
};
