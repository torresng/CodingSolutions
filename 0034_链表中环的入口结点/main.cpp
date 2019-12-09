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
    ListNode *entryNodeOfLoop(ListNode *head) {
        auto i = head, j = head;
        while (i && j) {
            i = i->next;
            j = j->next;
            if (j) {
                j = j->next;
            }
            if (i == j) {
                i = head;
                while (i != j) {
                    i = i->next;
                    j = j->next;
                }
                return i;
            }
        }
        return 0;
    }
};
