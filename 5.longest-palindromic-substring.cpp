// CreateTime: 2021-03-01 19:28:31
class Solution {
public:
    string ans = "";

    string longestPalindrome(string s) {
        int len = s.size();
        for (int i = 0; i < len; i++) {
            tryExpand2(s, i, i);
            tryExpand2(s, i, i+1);
        }
        return ans;
    }

    void tryExpand(string &s, int k1, int k2) {
        int len = s.size();
        while (k1 >= 0 && k2 < len) {
            if (s[k1] == s[k2]) {
                if (k2-k1+1 > ans.size()) {
                    ans = s.substr(k1, k2-k1+1);
                }

                k1--;
                k2++;
            } else {
                break;
            }
        }
    }

    void tryExpand2(string &s, int k1, int k2) {
        int len = s.size();
        while (k1 >= 0 && k2 < len && s[k1] == s[k2]) {
            if (k2-k1+1 > ans.size()) {
                ans = s.substr(k1, k2-k1+1);
            }

            k1--;
            k2++;
        }
    }
};
