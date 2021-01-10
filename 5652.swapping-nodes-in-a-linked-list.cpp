// CreateTime: 2021-01-10 10:38:02
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
    ListNode* swapNodes(ListNode* head, int k) {
        unordered_map<int, ListNode *> m; 

        ListNode *p1 = head;
        ListNode *p2 = head;
        
        int step = 0;
        for (auto p = head; p != NULL; p = p->next) {
            step++;
            if (step == k) {
                p1 = p;
            }
            if (step > k) {
                p2 = p2->next;
            }
        }
        
        if (p1 == p2) {
            return head;
        }
        
        swap(p1->val, p2->val);
        return head;
    }
};