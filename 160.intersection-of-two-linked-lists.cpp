/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// class Solution {
// public:
//     ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
//         int len1 = 0;
//         int len2 = 0;

//         ListNode *p1 = headA;
//         ListNode *p2 = headB;

//         while (p1) {
//             len1++;
//             p1 = p1->next;
//         }
//         while (p2) {
//             len2++;
//             p2 = p2->next;
//         }

//         p1 = headA;
//         p2 = headB;
//         while (len1 != len2 && p1 && p2) {
//             if (p1 == p2) {
//                 return p1;
//             }

//             if (len1 > len2) {
//                 p1 = p1->next;
//                 len1--;
//             }
//             if (len2 > len1) {
//                 p2 = p2->next;
//                 len2--;
//             }
//         }

//         while (p1 && p2) {
//             if (p1->val == p2->val) {
//                 return p1;
//             }
//             p1 = p1->next;
//             p2 = p2->next;
//         }

//         return NULL;
//     }
// };



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
