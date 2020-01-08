// CreateTime: 2020-01-09 00:31:42
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;

        int k = 0;
        int len = nums.size();
        int l;
        while (k < len) {
            l = 1;
            while (k+1 < len && (long long)nums[k]+1 == (long long)nums[k+1]) {
                k++;
                l++;
            }
            k++;

            if (l == 1) {
                res.push_back(to_string(nums[k-1]));
            } else {
                res.push_back(to_string((long long)nums[k-1]-l+1) + "->" + to_string(nums[k-1]));
            }
        }

        return res;
    }
};
