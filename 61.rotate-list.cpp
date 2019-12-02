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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || head->next == NULL || k == 0) {
            return head;
        }

        int total_num = 0;
        ListNode *p = head;
        while (p != NULL) {
            p = p->next;
            total_num++;
        }

        if (k >= total_num) {
            k = k % total_num;
        }

        int nth = total_num - k;

        ListNode *prev = NULL;
        p = head;
        for (int i = 0; i < nth; i++) {
            prev = p;
            p = p->next;
        }

        if (prev == NULL || k == 0) {     // first node or last node
            return head;
        }

        ListNode *oriHead = head;
        prev->next = NULL;
        head = p;
        while (p->next != NULL) {
            p = p->next;
        }
        p->next = oriHead;

        return head;
    }
};
