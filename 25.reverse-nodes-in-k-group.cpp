// CreateTime: 2019-11-20 14:03:37
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        bool isFirst = true;

        auto p = head;
        ListNode *last = NULL;
        while (p != NULL) {
            auto subHead = reverseK(p, k);
            auto newLast = p;

            if (subHead == NULL) {
                break;
            }

            if (isFirst) {
                isFirst = false;
                head = subHead;
            } else if (last != NULL) {
                last->next = subHead;
            }
            last = newLast;
            p = newLast->next;
        }
        return head;
    }

    ListNode* reverseK(ListNode *p, int k) {
        ListNode *head = p;

        auto t = p;
        ListNode *last = NULL;
        for (int i = 0; i < k; i++) {
            if (t == NULL) {
                return NULL;
            }

            last = t;
            t = t->next;
        }


        head = last;

        while (p != head) {
            auto next = p->next;
            p->next = head->next;
            head->next = p;
            p = next;
        }

        return head;
    }
};
