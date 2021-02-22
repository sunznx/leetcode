// CreateTime: 2021-02-22 14:16:54
class Solution {
public:
    int findBestValue(vector<int>& arr, int target) {
        int len = arr.size();

        sort(arr.begin(), arr.end());

        vector<int> p(len);
        for (int i = 1; i < len; i++) {
            p[i] = p[i-1] + arr[i-1];
        }

        int l = 0;
        int r = *max_element(arr.begin(), arr.end());

        while (l < r) {
            int m = (l+r) / 2;
            if (calcSum(p, arr, m) >= target) {
                r = m;
            } else {
                l = m+1;
            }
        }

        int sum1 = calcSum(p, arr, l);
        int sum2 = calcSum(p, arr, l-1);
        if (abs(sum1-target) < abs(sum2-target)) {
            return l;
        }

        return l-1;
    }

    int calcSum(vector<int> &p, vector<int>& arr, int val) {
        int len = arr.size();
        int l = 0;
        int r = len-1;
        while (l < r) {
            int m = (l+r) / 2;
            if (arr[m] >= val) {
                r = m;
            } else {
                l = m+1;
            }
        }
        return p[l]+val*(len-l);
    }
};
