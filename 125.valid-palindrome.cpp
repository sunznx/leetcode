class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0;
        int r = s.size()-1;

        while (l < r) {
            if (!check(s[l])) {
                l += 1;
                continue;
            }
            if (!check(s[r])) {
                r -= 1;
                continue;
            }
            if (tolower(s[l]) == tolower(s[r])) {
                l += 1;
                r -= 1;
            } else {
                return false;
            }
        }

        return true;
    }

    bool check(char c) {
        if ('a' <= c && c <= 'z') {
            return true;
        }

        if ('A' <= c && c <= 'Z') {
            return true;
        }

        if ('0' <= c && c <= '9') {
            return true;
        }

        return false;
    }
};
