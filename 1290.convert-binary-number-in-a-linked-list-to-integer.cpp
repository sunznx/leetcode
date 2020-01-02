// CreateTime: 2020-01-02 09:53:59
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
    int getDecimalValue(ListNode* head) {
        int res = 0;
        
        auto p = head;
        while (p) {
            res = res * 2 + p->val;
            p = p->next;
        }

        return res;
    }
};
