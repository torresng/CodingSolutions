#include <iostream>
#include <vector>

using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
  public:
    vector<int> printListReversingly(ListNode *head) {
        vector<int> res;
        while (head) {
            res.push_back(head->val);
            head = head->next;
        }

        return vector<int>(res.rbegin(), res.rend());
    }
};

bool compare(vector<int> &arr1, vector<int> &arr2) {
    if (arr1.size() != arr2.size()) {
        return false;
    }

    for (int i = 0; i < arr1.size(); ++i) {
        if (arr1[i] != arr2[i]) {
            return false;
        }
    }
    return true;
}

void test_case_1() {
    ListNode *head = new ListNode(2);
    ListNode *p1 = new ListNode(3);
    ListNode *p2 = new ListNode(5);
    head->next = p1;
    p1->next = p2;
    vector<int> ans{5, 3, 2};

    vector<int> res = Solution().printListReversingly(head);
    assert(compare(res, ans) == true);
}

int main(void) {
    test_case_1();

    return 0;
}
