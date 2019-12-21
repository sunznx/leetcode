// CreateTime: 2019-12-21 09:29:11
class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        if (A.size() == 0 || A[0].size() == 0) {
            return 0;
        }
        
        int row = A.size();
        int col = A[0].size();
        
        int ans = 0;
        for (int i = 0; i < col; i++) {
            char pre = 0;
            int deleted = 0;
            for (int j = 0; j < row; j++) {
                if (A[j][i] < pre) {
                    deleted = 1;
                    break;
                }
                pre = A[j][i];
            }
            
            ans += deleted;
        }
        return ans;
    }
};
