// CreateTime: 2020-12-04 07:53:13
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int l = 0;
        int r = arr.size()-1;

        while (l < r) {
            int m = (l+r) / 2;

            if (arr[m] >= arr[m+1]) {
                r = m;
            } else if (arr[m] < arr[m+1]) {
                l = m+1;
            }
        }

        return l;
    }
};
