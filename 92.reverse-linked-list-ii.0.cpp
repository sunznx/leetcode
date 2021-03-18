// CreateTime: 2021-03-18 23:25:15
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (left == 1 && right == 1) {
            return head;
        }

        ListNode *p;
        ListNode *last = NULL;

        p = head;
        for (int i = 1; i < left; i++) {
            last = p;
            p = p->next;
        }

        ListNode *newList = NULL;
        ListNode *firstP = p;
        for (int i = left; i <= right; i++) {
            auto next = p->next;

            p->next = newList;
            newList = p;

            p = next;
        }
        firstP->next = p;

        if (last) {
            last->next = newList;
        } else {
            return newList;
        }

        return head;
    }
};
