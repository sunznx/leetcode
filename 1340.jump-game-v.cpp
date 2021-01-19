// CreateTime: 2021-01-18 09:15:56
class Solution {
public:
    int ans = 0;
    int len = 0;
    deque<int> que;
    vector<int> ll;
    vector<int> rr;
    vector<int> f;

    int maxJumps(vector<int>& arr, int d) {
        init(arr, d);

        for (int i = 0; i < len; i++) {
            walk(arr, i, d);
            ans = max(ans, f[i]);
        }

        return ans;
    }

    void walk(vector<int> &arr, int x, int d) {
        if (!isValid(x)) {
            return;
        }

        if (f[x] != -1) {
            return;
        }

        f[x] = 1;

        for (int i = x-1; isValid(i) && x-i <= d && arr[x] > arr[i]; i--) {
            walk(arr, i, d);
            f[x] = max(f[x], f[i]+1);
        }
        for (int i = x+1; isValid(i) && i-x <= d && arr[x] > arr[i]; i++) {
            walk(arr, i, d);
            f[x] = max(f[x], f[i]+1);
        }
    }

    inline bool isValid(int x) {
        return 0 <= x && x <= len-1;
    }

    void init(vector<int> &arr, int d) {
        len = arr.size();
        ll.resize(len, -1);
        rr.resize(len, -1);
        f.resize(len, -1);
    }
};
