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
    bool isPalindrome(ListNode* head) {
        ListNode *slow = head;
        ListNode *fast = head;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // rev slow
        ListNode *newHead = NULL;
        while (slow != NULL) {
            ListNode *next = slow->next;
            slow->next = newHead;
            newHead = slow;
            slow = next;
        }

        while (newHead != NULL) {
            if (newHead->val != head->val) {
                return false;
            }

            head = head->next;
            newHead = newHead->next;
        }

        return true;
    }
};



// class Solution {
// public:
//     ListNode* reverseList(ListNode* head) {
//         if (head == NULL) {
//             return NULL;
//         }

//         ListNode *helper = NULL;
//         ListNode *p = head;
//         while (p != NULL) {
//             ListNode *next = p->next;
//             if (helper == NULL) {
//                 helper = p;
//                 helper->next = NULL;
//             } else {
//                 p->next = helper;
//                 helper = p;
//             }
//             p = next;
//         }

//         return helper;
//     }

//     bool isPalindrome(ListNode* head) {
//         if (head == NULL || head->next == NULL) {
//             return true;
//         }

//         ListNode *fast = head->next;
//         ListNode *slow = head;

//         while (fast != NULL && fast->next != NULL) {
//             fast = fast->next->next;
//             slow = slow->next;
//         }

//         ListNode *left = head;
//         ListNode *right = reverseList(slow->next);

//         while (1) {
//             if (right == NULL) {
//                 return true;
//             }

//             if (left->val != right->val) {
//                 return false;
//             }

//             left = left->next;
//             right = right->next;
//         }

//         return false;
//     }
// };
