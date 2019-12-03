// CreateTime: 2019-12-01 06:26:59
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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        auto p = head;
        ListNode *prev = NULL;
        while (--m && p) {
            prev = p;
            p = p->next;
            --n;
        }

        ListNode *h2 = p;
        while (--n && p->next != NULL) {
            auto n = p->next;
            p->next = n->next;
            n->next = h2;
            h2 = n;
        }

        if (prev) {
            prev->next = h2;
            return head;
        } else {
            return h2;
        }
    }
};