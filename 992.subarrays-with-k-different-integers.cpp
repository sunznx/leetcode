// CreateTime: 2020-12-01 07:45:55
class Solution {
public:
    int subarraysWithKDistinct(vector<int>& A, int K) {
        return numberOfNotMoreThan(A, K) - numberOfNotMoreThan(A, K-1);
    }

    int numberOfNotMoreThan(vector<int> &A, int K) {
        int ans = 0;

        int l = 0;
        int r = 0;

        int len = A.size();

        unordered_map<int, int> window;

        while (r < len) {
            int x = A[r++];
            window[x]++;

            while (window.size() > K) {
                auto y = A[l++];
                window[y]--;
                if (window[y] == 0) {
                    window.erase(y);
                }
            }

            ans += r-l;
        }

        return ans;
    }
};
