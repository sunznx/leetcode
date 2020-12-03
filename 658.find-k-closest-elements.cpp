// CreateTime: 2020-12-03 23:06:09
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int l = 0;
        int r = arr.size()-1;

        while (l < r) {
            int m = (l+r) / 2;

            if (arr[m] < x) {
                l = m+1;
            } else if (arr[m] >= x) {
                r = m;
            }
        }

        if (arr[l] <= x) {
            r = l+1;
        } else if (arr[l] > x) {
            r = l;
            l = l-1;
        }


        vector<int> ans;
        while (ans.size() != k) {
            if (r == arr.size()) {
                ans.insert(ans.begin(), arr[l--]);
            } else if (l < 0) {
                ans.push_back(arr[r++]);
            } else if (abs(arr[l]-x) <= abs(arr[r]-x)) {
                ans.insert(ans.begin(), arr[l--]);
            } else {
                ans.push_back(arr[r++]);
            }
        }

        return ans;
    }
};
