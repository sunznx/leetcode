// CreateTime: 2019-12-15 09:46:17
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int len = nums.size();
        
        vector<int> arr;
        
        for (int i = 0; i < len; i++) {
            auto x = nums[i];

            int l = 0;
            int r = arr.size()-1;
            while (l < r) {
                int mid = (l+r) / 2;
                if (arr[mid] < x) {
                    l = mid+1;
                } else if (arr[mid] >= x) {
                    r = mid;
                }
            }

            if (l >= arr.size() || x > arr[arr.size()-1]) {
                arr.push_back(x);
            } else if (x < arr[l]) {
                arr[l] = x;
            }
        }
        
        return arr.size();
    }
};
