// CreateTime: 2021-04-05 10:05:56
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
    ListNode* partition(ListNode* head, int x) {
        ListNode *prev = NULL;
        ListNode *p1 = NULL;

        ListNode *newList = NULL;
        ListNode *p2 = NULL;

        p1 = head;
        while (p1) {
            auto next = p1->next;

            if (p1->val < x) {
                if (newList == NULL) {
                    newList = p2 = p1;
                } else {
                    p2->next = p1;
                    p2 = p1;
                }

                if (prev == NULL) {
                    head = next;
                } else {
                    prev->next = next;
                }
            } else {
                prev = p1;
            }

            p1 = next;
        }

        if (newList) {
            p2->next = head;
            return newList;
        }
        return head;
    }
};
