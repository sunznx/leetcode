// CreateTime: 2019-12-21 01:07:29
class Solution {
public:
    int largestPerimeter(vector<int>& A) {
        sort(A.rbegin(), A.rend());

        int len = A.size();
        for (int i = 0; i <= len-3; i++) {
            auto j = i+1;
            auto k = j+1;
            if (A[j]+A[k] > A[i] && A[i]-A[k] < A[j]) {
                return A[i] + A[j] + A[k];
            }
        }
        return 0;
    }
};
