// CreateTime: 2019-12-03 08:15:32
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *sortList(ListNode *head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }

        ListNode *fast;
        ListNode *slow;

        fast = slow = head;

        while (fast->next != NULL && fast->next->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
        }

        ListNode *mid = slow->next;
        slow->next = NULL;

        /* slow is mid */
        ListNode *l1 = sortList(head);
        ListNode *l2 = sortList(mid);
        return merge(l1, l2);
    }

    ListNode *merge(ListNode *l1, ListNode *l2) {
        ListNode t(-1);
        ListNode *p = &t;

        while (l1 != NULL && l2 != NULL) {
            if (l2->val < l1->val) {
                p->next = l2;
                p = p->next;
                l2 = l2->next;
            } else {
                p->next = l1;
                p = p->next;
                l1 = l1->next;
            }
        }

        while (l1 != NULL) {
            p->next = l1;
            p = p->next;
            l1 = l1->next;
        }

        while (l2 != NULL) {
            p->next = l2;
            p = p->next;
            l2 = l2->next;
        }

        return t.next;
    }
};
