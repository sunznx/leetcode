// CreateTime: 2019-12-03 07:49:09
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *last = NULL;
        ListNode *head = NULL;
        ListNode *p = NULL;

        while (l1 != NULL || l2 != NULL) {
            if (l2 == NULL) {
                p = l1;
                l1 = l1->next;
            } else if (l1 == NULL) {
                p = l2;
                l2 = l2->next;
            } else if (l1->val < l2->val) {
                p = l1;
                l1 = l1->next;
            } else {
                p = l2;
                l2 = l2->next;
            }

            if (head == NULL) {
                head = last = p;
            } else {
                last->next = p;                
            }

            last = p;
        }

        return head;
    }
};
