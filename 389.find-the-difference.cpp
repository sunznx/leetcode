class Solution {
public:
    char findTheDifference(string s, string t) {
        int len1 = s.size();
        int len2 = t.size();

        int res = 0;
        for (int i = 0; i < len1; i++) {
            res = (res ^ (s[i] - 'a'));
        }

        for (int i = 0; i < len2; i++) {
            res = (res ^ (t[i] - 'a'));
        }

        return (char)(res + 'a');
    }
};
