/**
 * Definition for singly-linked list with a random pointer.
 * struct ListNode {
 *     int val;
 *     ListNode *next, *random;
 *     ListNode(int x) : val(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
  public:
    ListNode *copyRandomList(ListNode *head) {
        for (auto p = head; p;) {
            auto np = new ListNode(p->val);
            auto next = p->next;
            p->next = np;
            np->next = next;
            p = next;
        }

        for (auto p = head; p; p = p->next->next) {
            if (p->random) {
                p->next->random = p->random->next;
            }
        }

        auto dummy = new ListNode(-1);
        auto cur = dummy;
        for (auto p = head; p; p = p->next) {
            cur->next = p->next;
            cur = cur->next;
            p->next = p->next->next;
        }
        return dummy->next;
    }
};
