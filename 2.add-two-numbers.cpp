
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
        ListNode *head = NULL;
        ListNode *p = NULL;
        ListNode *last = NULL;
        int carry = 0;

        while ((l1 != NULL || l2 != NULL) || carry) {
            int val1;
            int val2;

            if (l1 == NULL) {
                val1 = 0;
            } else {
                val1 = l1->val;
                l1 = l1->next;
            }

            if (l2 == NULL) {
                val2 = 0;
            } else {
                val2 = l2->val;
                l2 = l2->next;
            }

            int val = (val1 + val2 + carry) % 10;

            p = new ListNode(val);

            if (head == NULL) {
                head = p;
            } else {
                last->next = p;
            }
            last = p;

            if (val1 + val2 + carry >= 10) {
                carry = 1;
            } else {
                carry = 0;
            }
        }

        return head;
    }
};
