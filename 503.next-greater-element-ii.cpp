// CreateTime: 2020-01-18 01:28:59
class Solution {
  public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int len = nums.size();
        if (len == 0) {
            return {};
        }

        for (int i = 0; i < len; i++) {
            nums.push_back(nums[i]);
        }

        stack<int> s;
        vector<int> res(len);
        for (int i = 0; i < 2*len; i++) {
            while (s.size() != 0 && nums[i] > nums[s.top()]) {
                if (nums[i] > nums[s.top()]) {
                    res[s.top()] = nums[i];
                    s.pop();
                }
            }

            if (i < len) {
                s.push(i);
            }
        }

        while (s.size()) {
            res[s.top()] = -1;
            s.pop();
        }

        return res;
    }
};
