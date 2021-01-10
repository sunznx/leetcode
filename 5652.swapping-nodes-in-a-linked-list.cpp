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

        int step = 0;
        auto p = head;
        while (p) {
            step++;
            m[step] = p;
            p = p->next;
        }

        int k1 = k;
        int k2 = m.size()-k+1;
        swap(m[k1]->val, m[k2]->val);
        
        return head;
    }
};