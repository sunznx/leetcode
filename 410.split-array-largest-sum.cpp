// CreateTime: 2021-01-23 17:43:58
class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        auto l = *max_element(nums.begin(), nums.end());
        auto r = accumulate(nums.begin(), nums.end(), 0);

        while (l < r) {
            int mid = (l+r) / 2;
            if (check(nums, m, mid)) {
                r = mid;
            } else {
                l = mid+1;
            }
        }

        return l;
    }

    bool check(vector<int> &nums, int m, int x) {
        long long sum = 0;
        int cnt = 1;
        for (int i = 0; i < nums.size(); i++) {
            if (sum + nums[i] > x) {
                cnt++;
                sum = nums[i];
            } else {
                sum += nums[i];
            }
        }
        return cnt <= m;
    }
};
