// CreateTime: 2021-01-10 10:38:02
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        int step = 0;
        int len = 0;
        auto p = head;
        while (p) {
            len++;
            p = p->next;
        }

        int k1 = k;
        int k2 = len-k+1;
        if (k1 == k2) {
            return head;
        }

        p = head;
        int *x1;
        int *x2;
        while (p) {
            step++;
            if (step == k1) {
                x1 = &(p->val);
            }
            if (step == k2) {
                x2 = &(p->val);
            }
            p = p->next;
        }

        auto t = *x1;
        *x1 = *x2;
        *x2 = t;
        return head;
    }
};