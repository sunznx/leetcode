class Solution {
public:
    string reverseWords(string s) {
        int len = s.size();
        if (len <= 1) {
            return s;
        }

        int l = 0;
        while (1) {
            while (s[l] == ' ' && l <= len-1) {
                l++;
            }
            if (l >= len-1) {
                break;
            }

            int r = l+1;
            while (s[r] != ' ' && r <= len-1) {
                r++;
            }
            r = r-1;
            s = reverseStr(s, l, r);
            l = r+1;
        }

        return s;
    }

    string reverseStr(string s, int l, int r) {
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
