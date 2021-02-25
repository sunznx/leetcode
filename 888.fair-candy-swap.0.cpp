// CreateTime: 2021-02-25 19:21:24
class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        int s1 = accumulate(A.begin(), A.end(), 0);
        int s2 = accumulate(B.begin(), B.end(), 0);

        int avg = (s1+s2) / 2;
        int k = avg-s1;

        sort(B.begin(), B.end());

        for (auto &x: A) {
            int l = 0;
            int r = B.size()-1;

            while (l <= r) {
                int m = (l+r) / 2;
                if (B[m]-x == k) {
                    return {x, B[m]};
                } else if (B[m]-x > k) {
                    r = m-1;
                } else {
                    l = m+1;
                }
            }
        }
        return {0, 0};
    }
};
