// CreateTime: 2019-11-27 12:22:44
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int len = A.size();
            
        int r = len-1;
        int l = 0;
        while (l < r) {
            if (A[l] % 2 == 1) {
                swap(A[l], A[r--]);
            } else {
                l++;
            }
        }
        return A;
    }
};
