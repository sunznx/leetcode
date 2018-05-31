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
        while (l1 != NULL || l2 != NULL) {
            ListNode *p = (ListNode *) malloc (sizeof(ListNode));

            int val;
            if (l2 == NULL) {
                val = l1->val;
                l1 = l1->next;
            } else if (l1 == NULL) {
                val = l2->val;
                l2 = l2->next;
            } else if (l1->val < l2->val) {
                val = l1->val;
                l1 = l1->next;
            } else {
                val = l2->val;
                l2 = l2->next;
            }
            
            p->val = val;
            p->next = NULL;

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
