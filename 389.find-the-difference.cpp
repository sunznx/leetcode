// CreateTime: 2020-12-18 23:50:57
class Solution {
public:
    char findTheDifference(string s, string t) {
        char ans = 0;
        for (int i = 0; i < s.size(); i++) {
            ans = (ans ^ s[i]);
        }

        for (int i = 0; i < t.size(); i++) {
            ans = (ans ^ t[i]);
        }
        return ans;
    }
};
