// CreateTime: 2021-03-07 10:34:01
class Solution {
public:
    int minElements(vector<int>& nums, int limit, int goal) {
        long long s = 0;
        for (auto &x: nums) {
            s += x;
        }
        long long k = (long long)(goal)-s;

        return abs(k) / limit + (abs(k) % limit != 0);
    }
};