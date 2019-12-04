// CreateTime: 2019-12-03 11:49:39
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
    ListNode* insertionSortList(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }

        auto prev = head;
        while (prev->next != NULL) {
            auto last = prev->next;

            ListNode *pp = NULL;
            auto p = head;
            while (last->val > p->val && last != p) {
                pp = p;
                p = p->next;
            }

            if (pp == NULL) {
                prev->next = last->next;
                last->next = head;
                head = last;
            } else if (last == p) {
                prev = prev->next;
            } else {
                prev->next = last->next;
                last->next = p;
                pp->next = last;
            }
        }

        return head;
    }
};