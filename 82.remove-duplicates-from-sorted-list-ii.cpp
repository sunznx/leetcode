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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *prev = NULL;
        ListNode *p = head;

        while (p != NULL && p->next != NULL) {
            ListNode *q = p->next;
            if (p->val == q->val) {

                // find next
                ListNode *next = q->next;
                while (next != NULL && next->val == p->val) {
                    next = next->next;
                }

                p = next;
                if (prev == NULL) { // is first node
                    head = next;
                } else {
                    prev->next = next;
                }
            } else {
                prev = p;
                p = p->next;
            }
        }

        return head;
    }
};
