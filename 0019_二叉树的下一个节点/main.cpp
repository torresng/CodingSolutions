#include <iostream>

using namespace std;

/**
 * Definition for a binary tree node.
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode *father;
    TreeNode(int x) : val(x), left(NULL), right(NULL), father(NULL) {}
};

class Solution {
  public:
    TreeNode *inorderSuccessor(TreeNode *p) {
        if (p->right) {
            p = p->right;
            while (p->left) {
                p = p->left;
            }
            return p;
        }

        while (p->father && p->father->right == p) {
            p = p->father;
        }
        return p->father;
    }
};

void test_case_1() {
    TreeNode *root = new TreeNode(2);
    TreeNode *p1 = new TreeNode(1);
    TreeNode *p2 = new TreeNode(3);
    root->left = p1;
    root->right = p2;

    assert(Solution().inorderSuccessor(root) == p2);
}

int main(void) {
    test_case_1();

    return 0;
}
