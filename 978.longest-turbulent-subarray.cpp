// CreateTime: 2021-02-09 23:00:17
class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int len = arr.size();

        int ans = 1;
        int sub = 1;
        int mark = 0;

        for (int i = 1; i < len; i++) {
            auto preMark = mark;

            if (arr[i] > arr[i-1]) {
                mark = 1;
            } else if (arr[i] < arr[i-1]) {
                mark = -1;
            } else {
                mark = 0;
            }

            if (mark == 0) {
                sub = 1;
            } else if ((preMark == 0 && mark != 0) || (preMark == 1 && mark == -1) || (preMark == -1 && mark == 1)) {
                sub++;
            } else {
                sub = 2;
            }

            ans = max(ans, sub);
        }
        return ans;
    }
};
