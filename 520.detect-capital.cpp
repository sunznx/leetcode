class Solution {
public:
    bool detectCapitalUse(string word) {
        int len = word.size();
        int hasLower = 0;
        int hasUpper = 0;
        for (int i = 0; i < len; i++) {
            if (! ('A' <= word[i] && word[i] <= 'Z')) {
                hasLower += 1;
            } else if ('A' <= word[i] && word[i] <= 'Z') {
                hasUpper += 1;
            }
        }

        if (hasUpper == 0 && hasLower > 0) {
            return true;
        } else if (hasUpper > 0 && hasLower == 0) {
            return true;
        } else if (('A' <= word[0] && word[0] <= 'Z') && hasUpper == 1) {
            return true;
        }

        return false;
    }
};
