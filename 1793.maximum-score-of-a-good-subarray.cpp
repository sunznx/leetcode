// CreateTime: 2021-03-14 11:30:48
class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int len = nums.size();
        vector<int> l(len);
        vector<int> r(len);
        stack<int> stk;

        stk = stack<int>();
        for (int i = 0; i < len; i++) {
            auto x = nums[i];
            while (stk.size() && nums[stk.top()] >= x) {
                stk.pop();
            }

            if (stk.size() == 0) {
                l[i] = i;
            } else {
                l[i] = i-stk.top()-1;
            }

            stk.push(i);
        }

        stk = stack<int>();
        for (int i = len-1; i >= 0; i--) {
            auto x = nums[i];
            while (stk.size() && nums[stk.top()] >= x) {
                stk.pop();
            }

            if (stk.size() == 0) {
                r[i] = len-1-i;
            } else {
                r[i] = stk.top()-i-1;
            }

            stk.push(i);
        }

        int ans = 0;
        for (int i = 0; i < len; i++) {
            auto x = nums[i];
            if (i-l[i] <= k && k <= i+r[i]) {
                ans = max(ans, (l[i]+r[i]+1) * x);
            }
        }
        return ans;
    }
};