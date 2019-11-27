// CreateTime: 2019-11-27 12:21:10
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        int len = A.size();

        int l = 0;
        int r = 1;
        while (true) {
            while (l < len && A[l] % 2 == 0) {
                l += 2;
            }
            while (r < len && A[r] % 2 == 1) {
                r += 2;
            }

            if (l > len || r > len) {
                break;
            }

            swap(A[l], A[r]);
        }

        return A;
    }
};