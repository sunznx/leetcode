// CreateTime: 2019-12-09 00:32:23
class Solution {
public:
    int fixedPoint(vector<int>& A) {
        int len = A.size();
        
        int l = 0;
        int r = len-1;
        
        while (l < r) {
            int m = (l+r) / 2;
            
            if (A[m] < m) {
                l = m+1;
            } else {
                r = m;
            }
        }
        
        if (A[l] == l) {
            return l;
        }

        return -1;
    }
};
