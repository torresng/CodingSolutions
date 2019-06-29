#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
  public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        int pn = preorder.size();
        int in = inorder.size();
        _preorder = preorder;
        _inorder = inorder;
        for (int i = 0; i < in; ++i) {
            map[inorder[i]] = i;
        }
        return dfs(0, pn - 1, 0, in - 1);
    }

  private:
    vector<int> _preorder, _inorder;
    unordered_map<int, int> map;

    TreeNode *dfs(int pl, int pr, int il, int ir) {
        if (pl > pr) {
            return nullptr;
        }
        int x = _preorder[pl];
        TreeNode *root = new TreeNode(x);
        int k = map[x];

        auto left = dfs(pl + 1, pl + k - il, il, k - 1);
        auto right = dfs(pl + 1 + k - il, pr, k + 1, ir);
        root->left = left;
        root->right = right;

        return root;
    }
};

bool compare(TreeNode *root1, TreeNode *root2) {
    if (root1 == nullptr && root2 == nullptr) {
        return true;
    }
    if (root1 == nullptr || root2 == nullptr) {
        return false;
    }
    if (root1->val != root2->val) {
        return false;
    }
    return compare(root1->left, root2->left) &&
           compare(root1->right, root2->right);
}

void test_case_1() {
    vector<int> preorder{3, 9, 20, 15, 7};
    vector<int> inorder{9, 3, 15, 20, 7};

    TreeNode *ans = new TreeNode(3);
    TreeNode *p1 = new TreeNode(9);
    TreeNode *p2 = new TreeNode(20);
    TreeNode *p3 = new TreeNode(15);
    TreeNode *p4 = new TreeNode(7);
    ans->left = p1;
    ans->right = p2;
    p2->left = p3;
    p2->right = p4;

    TreeNode *res = Solution().buildTree(preorder, inorder);

    assert(compare(res, ans) == true);
}

int main(void) {
    test_case_1();

    return 0;
}
