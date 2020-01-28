// CreateTime: 2020-01-28 11:52:22
class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int> arr(n+1);
        for (int i = 0; i <= n; i++) {
            int l = max(0, i-ranges[i]);
            int r = min(n, i+ranges[i]);
            for (int k = l; k <= r; k++) {
                arr[k] = max(arr[k], min(n, i+ranges[i]));
            }
        }

        int res = 0;
        int end = 0;
        while (end != n) {
            if (arr[end] <= end) {
                return -1;
            }
            end = arr[end];
            res++;
        }

        return res;
    }
};


