// CreateTime: 2020-11-30 01:25:41
class Solution {
public:
    int numSubarraysWithSum(vector<int>& A, int S) {
        int ans = 0;

        unordered_map<int, int> m;
        m[0] = 1;

        int sum = 0;
        for (int i = 0; i < A.size(); i++) {
            sum += A[i];
            ans += m[sum-S];
            m[sum]++;
        }

        return ans;
    }
};
