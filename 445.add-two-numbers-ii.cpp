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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *prev1 = NULL;
        ListNode *prev2 = NULL;
        ListNode *p = NULL;
        ListNode *next = NULL;

        // rev l1
        p = l1;
        while (p != NULL) {
            next = p->next;
            if (prev1 == NULL) {
                p->next = NULL;
            } else {
                p->next = prev1;
            }

            prev1 = p;
            l1 = p;
            p = next;
        }

        // rev l2
        p = l2;
        while (p != NULL) {
            next = p->next;
            if (prev2 == NULL) {
                p->next = NULL;
            } else {
                p->next = prev2;
            }

            prev2 = p;
            l2 = p;
            p = next;
        }

        // res
        ListNode *res = NULL;
        int carry = 0;
        while ((l1 != NULL || l2 != NULL) || carry == 1) {
            int val1;
            int val2;
            int val;

            if (l1 != NULL && l2 != NULL) {
                val1 = l1->val;
                val2 = l2->val;
                l1 = l1->next;
                l2 = l2->next;
            } else if (l1 == NULL && l2 == NULL) {
                val1 = 0;
                val2 = 0;
            } else if (l1 == NULL) {
                val1 = 0;
                val2 = l2->val;
                l2 = l2->next;
            } else if (l2 == NULL) {
                val2 = 0;
                val1 = l1->val;
                l1 = l1->next;
            }

            val = val1 + val2 + carry;
            p = new ListNode(val % 10);
            p->next = res;
            res = p;

            if (val >= 10) {
                carry = 1;
            } else {
                carry = 0;
            }
        }

        return res;
    }
};
