// CreateTime: 2020-12-01 03:07:41
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0;
        int r = numbers.size()-1;

        while (l < r) {
            auto x = numbers[l] + numbers[r];
            if (x == target) {
                return {l+1, r+1};
            } else if (x > target) {
                r--;
            } else if (x < target) {
                l++;
            }
        }
        return {-1, -1};
    }
};
