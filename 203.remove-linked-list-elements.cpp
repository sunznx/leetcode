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
    ListNode* removeElements(ListNode* head, int val) {
        while (head != NULL && head->val == val) {
            head = head->next;
        }

        if (head == NULL) {
            return head;
        }

        ListNode *p = head;
        while (p->next != NULL) {
            ListNode *q = p->next;
            if (q->val == val) {
                p->next = q->next;
            } else {
                p = p->next;
            }
        }

        return head;
    }
};
