// CreateTime: 2021-04-17 10:17:52
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        multiset<long long> S;

        int l = 0;
        for (int r = 0; r < nums.size(); r++) {
            auto x = nums[r];

            auto iter = S.insert(x);
            if (next(iter, 1) != S.end() && abs(*next(iter, 1) - x) <= t) {
                return true;
            }
            if (iter != S.begin() && abs(*prev(iter, 1) - x) <= t) {
                return true;
            }

            if (S.size() >= k+1) {
                S.erase(S.find(nums[l++]));
            }
        }
        return false;
    }
};
