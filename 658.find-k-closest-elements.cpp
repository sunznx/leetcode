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
        vector<int> ll;
        vector<int> rr;
        for (int t = 0; t < k; t++) {
            if (i < 0) {
                rr.push_back(arr[j++]);
            } else if (j == arr.size()) {
                ll.push_back(arr[i--]);
            } else {
                int diff1 = abs(arr[i] - x);
                int diff2 = abs(arr[j] - x);
                if (diff1 <= diff2) {
                    ll.push_back(arr[i--]);
                } else {
                    rr.push_back(arr[j++]);
                }
            }
        }

        int idx = 0;

        for (int i = ll.size()-1; i >= 0; i--) {
            res[idx++] = ll[i];
        }
        for (int i = 0; i < rr.size(); i++) {
            res[idx++] = rr[i];
        }

        return res;
    }
};
