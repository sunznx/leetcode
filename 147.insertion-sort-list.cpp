// // CreateTime: 2019-11-20 11:49:52
// #include <iostream>
// #include <cstdio>
// #include <cstdlib>
// #include <cstring>
// #include <string>
// #include <cmath>
// #include <algorithm>
// #include <queue>
// #include <deque>
// #include <vector>
// #include <list>
// #include <stack>
// #include <map>
// #include <set>
// #include <unordered_set>
// #include <unordered_map>

// using namespace std;

// struct ListNode {
//     int val;
//     struct ListNode *next;

//     ListNode(int val, struct ListNode *next = NULL) {
//         this->val = val;
//         this->next = next;
//     }

//     ListNode(vector<int> &nums) {
//         this->val = nums[0];
//         auto last = this;
//         for (int i = 1; i < nums.size(); i++) {
//             auto n = new struct ListNode(nums[i]);
//             last->next = n;
//             last = n;
//         }
//     }

//     void show() {
//         cout << "show: " << endl;
//         cout << val << endl;

//         auto l = this->next;
//         while (l != NULL) {
//             cout << l->val << endl;
//             l = l->next;
//         }
//         cout << endl;
//     }
// };

// CreateTime: 2019-12-03 11:49:39
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
    ListNode* insertionSortList(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }

        int step = 0;

        auto prev = head;
        while (prev->next != NULL) {
            step ++;
            auto last = prev->next;

            ListNode *pp = NULL;
            auto p = head;
            while (last->val > p->val && last != p) {
                pp = p;
                p = p->next;
            }

            if (pp == NULL) {
                prev->next = last->next;
                last->next = head;
                head = last;
            } else if (last == p) {
                prev = prev->next;
            } else {
                prev->next = last->next;
                last->next = p;
                pp->next = last;
            }
        }

        return head;
    }
};

// int main(void) {
//     vector<int> v = {-1, 5, 3, 4, 0};
//     ListNode *l = new ListNode(v);

//     Solution s;
//     l = s.insertionSortList(l);
//     l->show();

//     return 0;
// }
