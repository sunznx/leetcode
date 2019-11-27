// CreateTime: 2019-11-27 16:28:43
class Solution {
public:
    int smallestRangeI(vector<int>& A, int K) {
        int len = A.size();
        int minv = A[0];
        int maxv = A[0];
        for (int i = 1; i < len; i++) {
            minv = min(minv, A[i]);
            maxv = max(maxv, A[i]);
        }

        int distance = maxv - minv;
        return max(0, distance-2*K);
    }
};
