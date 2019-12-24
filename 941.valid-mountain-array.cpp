// CreateTime: 2019-12-24 14:58:20
class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        int len = A.size();

        if (len <= 2) {
            return false;
        }

        bool down = false;
        bool isFirst = true;
        for (int i = 1; i < len; i++) {
            if (A[i] == A[i-1]) {
                return false;
            }

            if (!down && A[i-1] > A[i]) {
                if (isFirst && i != 1) {
                    isFirst = false;
                    down = true;
                } else {
                    return false;
                }
            }

            if (down && A[i-1] < A[i]) {
                return false;
            }
        }

        return down == true;
    }
};
