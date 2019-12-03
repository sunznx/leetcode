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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == NULL) {
            return head;
        }

        int total_num = 0;
        ListNode *p = head;

        while (p != NULL) {
            total_num++;
            p = p->next;
        }

        int nth = total_num - n;
        int index = 0;

        ListNode *prev = NULL;
        p = head;
        for (int i = 0; i < nth; i++) {
            prev = p;
            p = p->next;
        }

        if (prev == NULL) {     // first node here
            head = head->next;
        } else {
            prev->next = p->next;
        }

        return head;
    }
};
