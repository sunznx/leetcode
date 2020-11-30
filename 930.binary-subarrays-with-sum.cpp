// CreateTime: 2020-11-30 01:25:41
class Solution {
public:
    int numSubarraysWithSum(vector<int>& A, int S) {
        int ans = 0;

        int sum = 0;
        unordered_map<int, int> p;
        p[0] = 1;

        for (int i = 0; i < A.size(); i++) {
            auto x = A[i];
            sum += x;

            if (sum >= S) {
                ans += p[sum - S];
            }

            p[sum]++;
        }

        return ans;
    }
};
