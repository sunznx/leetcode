// CreateTime: 2019-11-30 18:15:46
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int len = nums.size();
        if (len == 0) {
            return false;
        }
        
        int k = -0x7fffffff;
        deque<int> que;

        for (int i = len-1; i >= 0; i--) {
            if (nums[i] < k) {
                return true;
            }

            while (!que.empty() && nums[i] > que.back()) {
                k = que.back();
                que.pop_back();
            }
            que.push_back(nums[i]);
        }
        
        return false;
    }
};

