// CreateTime: 2020-11-24 00:09:32
class Solution {
public:
    int longestMountain(vector<int>& A) {
        int len = A.size();
        if (len == 0) {
            return 0;
        }

        vector<int> l(len);
        vector<int> r(len);
        
        for (int i = 1; i < len; i++) {
            if (A[i] > A[i-1]) {
                l[i] = l[i-1] + 1;
            }
        }
        
        for (int i = len-2; i >= 0; i--) {
            if (A[i] > A[i+1]) {
                r[i] = r[i+1] + 1;
            }
        }
        
        int ans = 0;
        for (int i = 0; i < len; i++) {
            if (l[i] > 0 && r[i] > 0) {
                ans = max(ans, l[i]+r[i]+1);                
            }
        }

        return ans;
    }
};
