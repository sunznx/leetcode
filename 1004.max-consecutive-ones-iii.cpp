// CreateTime: 2020-12-01 03:31:48
class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int l = 0;
        int r = 0;

        int ans = 0;

        int usedK = 0;
        int curLen = 0;

        for (int i = 0; i < A.size(); i++) {
            auto x = A[r++];

            if (x == 0) {
                usedK++;
            }

            while (usedK > K) {
                auto y = A[l++];
                if (y == 0) {
                    usedK--;
                }
            }

            ans = max(ans, r-l);
        }

        return ans;
    }
};
