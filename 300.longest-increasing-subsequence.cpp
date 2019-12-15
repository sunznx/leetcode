// CreateTime: 2019-12-15 09:46:17
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int len = nums.size();
        
        vector<int> m;
        
        for (int i = 0; i < len; i++) {
            int l = 0;
            int r = m.size()-1;
            while (l < r) {
                int mid = (l+r) / 2;
                if (m[mid] < nums[i]) {
                    l = mid+1;
                } else if (m[mid] >= nums[i]) {
                    r = mid;
                }
            }

            if (l >= m.size() || nums[i] > m[m.size()-1]) {
                m.push_back(nums[i]);
            } else if (nums[i] < m[l]) {
                m[l] = nums[i];
            }
        }
        
        return m.size();
    }
};
