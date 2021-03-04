// CreateTime: 2021-03-04 10:15:43
class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0;
        int r = s.size()-1;

        while (l < r) {
            while (l < r && !isOk(s[l])) {
                l++;
            }

            while (l < r && !isOk(s[r])) {
                r--;
            }

            if (l < r && !isEqual(s[l], s[r])) {
                return false;
            }
            l++;
            r--;
        }

        return true;
    }

    bool isEqual(char c1, char c2) {
        if (isNum(c1) && isNum(c2)) {
            return c1 == c2;
        } else if (isNum(c1) || isNum(c2)) {
            return false;
        }

        int s1 = 0;
        int s2 = 0;
        if (isUpper(c1)) {
            s1 = c1 - 'A' + 10;
        } else {
            s1 = c1 - 'a' + 10;
        }

        if (isUpper(c2)) {
            s2 = c2 - 'A' + 10;
        } else {
            s2 = c2 - 'a' + 10;
        }
        return s1 == s2;
    }

    bool isOk(char c) {
        return isNum(c) || isLower(c) || isUpper(c);
    }

    bool isNum(char c) {
        return '0' <= c && c <= '9';
    }

    bool isLower(char c) {
        return 'a' <= c && c <= 'z';
    }

    bool isUpper(char c) {
        return 'A' <= c && c <= 'Z';
    }
};
