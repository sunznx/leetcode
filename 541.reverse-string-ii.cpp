class Solution {
public:
    string reverseStr(string s, int k) {
        int len = s.size();
        if (len <= 1 || k <= 1) {
            return s;
        }

        for (int i = 0; i < len; i+=2*k) {
            if (i+k > len-1) {
                s = reverseStr(s, i, len-1);
            } else if (i + 2*k > len-1 && i + k < len-1) {
                s = reverseStr(s, i, i+k-1);
            } else {
                s = reverseStr(s, i, i+k-1);
            }
        }
        return s;
    }

    string reverseStr(string s, int l, int r) {
        int len = s.size();
        if (r >= len) {
            return s;
        }

        while (l < r) {
            char t = s[l];
            s[l] = s[r];
            s[r] = t;
            l++;
            r--;
        }

        return s;
    }
};
