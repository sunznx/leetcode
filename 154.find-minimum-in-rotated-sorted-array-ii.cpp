// // CreateTime: 2019-11-23 18:10:19
// #include <iostream>
// #include <cstdio>
// #include <cstdlib>
// #include <cstring>
// #include <string>
// #include <sstream>
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

// CreateTime: 2019-11-23 17:58:46
class Solution {
public:
    int res;
    int findMin(vector<int>& nums) {
        res = nums[0];
        findMin(nums, 0, nums.size()-1);
        return res;
    }

    void findMin(vector<int>& nums, int l, int r) {
        res = min(res, nums[l]);
        while (l < r) {
            int m = (l+r+1) / 2;

            if (nums[l] == nums[r]) {
                findMin(nums, l, m-1);
                findMin(nums, m, r);
                return;
            }

            if (nums[m] < nums[l]) {
                res = min(res, nums[m]);
                r = m-1;
            } else {
                l = m;
            }
        }
    }
};

// int main(void) {
//     Solution s;
//     vector<int> v = {1,2,2,2,0,1,1};
//     cout << s.findMin(v) << endl;

//     return 0;
// }
