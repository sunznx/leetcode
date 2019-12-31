// CreateTime: 2019-12-31 12:27:55
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
    ListNode* middleNode(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        
        auto slow = head;
        auto fast = head;
        
        while (fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        
        if (fast->next) {
            return slow->next;
        }
        return slow;
    }
};
