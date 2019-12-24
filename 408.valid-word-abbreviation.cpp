// CreateTime: 2019-12-24 14:52:40
class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int len1 = word.size();
        int len2 = abbr.size();

        int k1 = 0;
        int k2 = 0;
        while (k1 < len1 && k2 < len2) {
            if (word[k1] == abbr[k2]) {
                k1++;
                k2++;
            } else if ('1' <= abbr[k2] && abbr[k2] <= '9') {
                int v = 0;
                while (k2 < len2 && '0' <= abbr[k2] && abbr[k2] <= '9') {
                    v = v * 10 + (abbr[k2++] - '0');
                }
                k1 += v;
            } else {
                return false;
            }
        }

        return k1 == len1 && k2 == len2;
    }
};
