// CreateTime: 2019-11-30 18:15:46
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int len = nums.size();
        if (len == 0) {
            return false;
        }
        
        int k = -0x7fffffff;
        stack<int> stk;

        for (int i = len-1; i >= 0; i--) {
            if (nums[i] < k) {
                return true;
            }

            while (!stk.empty() && nums[i] > stk.top()) {
                k = stk.top();
                stk.pop();
            }
            stk.push(nums[i]);
        }
        
        return false;
    }
};

