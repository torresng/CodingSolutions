/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
  public:
    ListNode *findKthToTail(ListNode *pListHead, int k) {
        int n = 0;
        for (auto p = pListHead; p; p = p->next) {
            n++;
        }
        if (k > n) {
            return nullptr;
        }
        auto p = pListHead;
        for (int i = 0; i < n - k; i++) {
            p = p->next;
        }
        return p;
    }
};
