// CreateTime: 2019-12-03 07:40:04
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
    void reorderList(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return;
        }

        ListNode *slow = head;
        ListNode *fast = head->next;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode *l1 = head;
        ListNode *l2 = slow->next;
        slow->next = NULL;

        // reverse
        ListNode *prev = NULL;
        ListNode *p = l2;
        while (p != NULL) {
            ListNode *next = p->next;
            if (prev != NULL) {
                p->next = prev;
            } else {
                p->next = NULL;
            }

            l2 = p;
            prev = p;
            p = next;
        }

        while (l1 != NULL || l2 != NULL) {
            ListNode *next1 = l1->next;
            ListNode *next2 = l2->next;

            l1->next = l2;
            l2->next = next1;
            l1 = next1;
            if (next2 != NULL) {
                l2 = next2;
            } else {
                break;
            }
        }
    }
};
