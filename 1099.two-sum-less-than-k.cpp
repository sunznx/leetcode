// CreateTime: 2019-12-24 17:29:45
class Solution {
public:
    int twoSumLessThanK(vector<int>& A, int K) {
        int len = A.size();

        int ans = -1;

        for (int i = 0; i < len; i++) {
            for (int j = i+1; j < len; j++) {
                int S = A[i] + A[j];
                if (S < K) {
                    ans = max(ans, S);
                }
            }
        }
        
        return ans;
    }
};
