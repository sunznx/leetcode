// CreateTime: 2021-02-19 17:33:46
class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int ans = 0;
        int k = 0;
        int l = 0;
        for (int r = 0; r < A.size(); r++) {
            auto x = A[r];
            if (x == 0) {
                k++;
            }

            while (k > K) {
                auto y = A[l++];
                if (y == 0) {
                    k--;
                }
            }

            ans = max(ans, r-l+1);
        }

        return ans;
    }
};
