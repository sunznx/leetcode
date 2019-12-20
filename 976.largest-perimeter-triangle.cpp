// CreateTime: 2019-12-21 01:07:29
class Solution {
public:
    int largestPerimeter(vector<int>& A) {
        sort(A.rbegin(), A.rend());
        
        int len = A.size();
        for (int i = 0; i < len; i++) {
            for (int j = i+1; j < len; j++) {
                for (int k = j+1; k < len; k++) {
                    if (ok(A[i], A[j], A[k])) {
                        return A[i] + A[j] + A[k];
                    } else {
                        break;
                    }
                }
            }
        }
        return 0;
    }
    
    inline bool ok(int k1, int k2, int k3) {
        if (! (k1+k2 > k3 && k1+k3 > k2 && k2+k3 > k1)) {
            return false;
        }
        
        if (! (abs(k1-k2) < k3 && abs(k1-k3) < k2 && abs(k2-k3) < k1)) {
            return false;
        }

        return true;
    }
};
