/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == NULL || headB == NULL) {
            return NULL;
        }

        ListNode *n1 = headA;
        ListNode *n2 = headB;

        bool switched = false;

        while (n1 != NULL && n2 != NULL) {
            if (n1 == n2) {
                return n1;
            }

            n1 = n1->next;
            n2 = n2->next;

            if (n1 == NULL && n2 == NULL && switched == true) {
                return NULL;
            }

            if (n1 == NULL) {
                n1 = headB;
                switched = true;
            }
            if (n2 == NULL) {
                n2 = headA;
                switched = true;
            }
        }

        return NULL;
    }
};
