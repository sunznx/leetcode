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
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        
        auto p = head;
        bool isFirst = true;
        ListNode *last = NULL;
        
        while (p != NULL) {
            auto next = p->next;
            if (next == NULL) {
                break;
            }
            
            p->next = next->next;
            next->next = p;
            
            if (isFirst) {
                isFirst = false;
                head = next;
                last = p;
            } else if (last != NULL) {
                last->next = next;
                last = p;
            }
            
            p = p->next;
        }
        
        return head;
    }
};
