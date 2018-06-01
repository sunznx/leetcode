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
    ListNode* oddEvenList(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }

        ListNode *l1 = head;
        ListNode *l2 = head->next;
        ListNode *p = head;

        bool save_last = true;
        ListNode *last = NULL;

        while (p != NULL && p->next != NULL) {
            if (save_last) {
                last = p;
            }

            ListNode *next = p->next;
            p->next = next->next;
            p = next;
            save_last = !save_last;
        }

        if (last->next != NULL) {
            last = last->next;
        }
        last->next = l2;

        return l1;
    }
};
