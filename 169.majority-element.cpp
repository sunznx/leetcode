// CreateTime: 2019-11-22 13:56:33
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int len = nums.size();
        int l = 0;
        int r = len-1;

        stack<int> s;

        for (int i = 0; i < len; i++) {
            if (!s.empty() && s.top() != nums[i]) {
                s.pop();
            } else {
                s.push(nums[i]);
            }
        }

        return s.top();
    }
};
