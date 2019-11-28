// CreateTime: 2019-11-28 11:30:03
class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        int len = A.size();
        int l = 0;
        int r = len-1;

        while (l < r) {
            int mid = (l+r)/2;
            if (A[mid] < 0) {
                l = mid+1;
            } else {
                r = mid;
            }
        }

        if (A[l] < 0) {
            l = l + 1;
        }

        vector<int> res;
        int i = l;
        int j = l-1;
        for (int k = 0; k < len; k++) {
            if (i == len) {
                res.push_back(A[j] * A[j]);
                j--;
            } else if (j == -1) {
                res.push_back(A[i] * A[i]);
                i++;
            } else if (-A[j] < A[i]) {
                res.push_back(A[j] * A[j]);
                j--;
            } else {
                res.push_back(A[i] * A[i]);
                i++;
            }
        }

        return res;
    }
};