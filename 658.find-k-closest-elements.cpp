class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> res(k, 0);
        int l = 0;
        int r = arr.size()-1;

        int m;
        while (l <= r) {
            m = (l+r) / 2;
            if (arr[m] == x) {
                break;
            } else if (arr[m] > x) {
                r = m-1;
            } else if (arr[m] < x) {
                l = m+1;
            }
        }

        int i = m;
        int j = m+1;
        for (int t = 0; t < k; t++) {
            if (i < 0) {
                res[t] = arr[j++];
            } else if (j == arr.size()) {
                res[t] = arr[i--];
            } else {
                int diff1 = abs(arr[i] - x);
                int diff2 = abs(arr[j] - x);
                if (diff1 <= diff2) {
                    res[t] = arr[i--];
                } else {
                    res[t] = arr[j++];
                }
            }
        }
        sort(res.begin(), res.end());

        return res;
    }
};
