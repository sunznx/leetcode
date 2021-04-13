// CreateTime: 2021-04-14 00:10:46
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        bool hasK2 = false;
        int k2;

        stack<int> stk;

        for (int i = nums.size()-1; i >= 0; i--) {
            auto x = nums[i];

            if (hasK2 && x < k2) {
                return true;
            }

            while (stk.size() && x > stk.top()) {
                k2 = stk.top();
                stk.pop();
                hasK2 = true;
            }

            stk.push(x);
        }

        return false;
    }
};
