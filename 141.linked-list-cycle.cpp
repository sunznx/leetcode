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
    bool hasCycle(ListNode *head) {
        ListNode *fast = head;
        ListNode *slow = head;

        bool hasCircle = true;

        do {
            if (fast == NULL || fast->next == NULL) {
                hasCircle = false;
                break;
            }
            fast = fast->next->next;
            slow = slow->next;
        } while (fast != slow);

        return hasCircle;
    }
};
