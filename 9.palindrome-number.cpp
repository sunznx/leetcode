class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }

        if (x == 0) {
            return true;
        }

        string s = "";
        while (x) {
            int m = x % 10;
            x = x / 10;
            s += (char) (m + '0');
        }

        for (int i = 0; i <= s.size()/2; i++) {
            if (s[i] != s[s.size()-1-i]) {
                return false;
            }
        }

        return true;
    }
};
