// CreateTime: 2021-03-19 08:13:26
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
    ListNode* reverseList(ListNode* head) {
        ListNode *p = head;
        ListNode *newList = NULL;

        while (p) {
            auto next = p->next;
            p->next = newList;
            newList = p;
            p = next;
        }

        return newList;
    }
};
