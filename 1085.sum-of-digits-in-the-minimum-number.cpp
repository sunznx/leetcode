// CreateTime: 2019-12-09 07:00:33
class Solution {
public:
    int sumOfDigits(vector<int>& A) {
        int len = A.size();

        if (len == 0) {
            return 0;
        }

        int minv = A[0];
        for (int i = 1; i < len; i++) {
            minv = min(minv, A[i]);
        }
        
        int res = 0;

        while (minv) {
            res += minv % 2;
            minv = minv / 10;
        }
        
        return res % 2 == 0;
    }
};
