// CreateTime: 2021-02-09 23:00:17
class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int len = arr.size();

        int ans = 1;
        int sub = 1;
        int cmp = 0;

        for (int i = 1; i < len; i++) {
            auto preCmp = cmp;

            if (arr[i] > arr[i-1]) {
                cmp = 1;
            } else if (arr[i] < arr[i-1]) {
                cmp = -1;
            } else {
                cmp = 0;
            }

            if (cmp == 0) {
                sub = 1;
            } else if ((preCmp == 0 && cmp != 0) || (preCmp == 1 && cmp == -1) || (preCmp == -1 && cmp == 1)) {
                sub++;
            } else {
                sub = 2;
            }

            ans = max(ans, sub);
        }
        return ans;
    }
};
