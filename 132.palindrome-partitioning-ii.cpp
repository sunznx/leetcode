// CreateTime: 2021-03-09 08:13:17
class Solution {
public:
    vector<int> m;

    int minCut(string s) {
        m.resize(s.size(), -1);
        return minCut(s, 0);
    }

    int minCut(string &s, int step) {
        int len = s.size();

        if (step == s.size()) {
            return 0;
        }

        if (isPalindrome(s, step, len-1)) {
            return m[step] = 0;
        }

        if (m[step] >= 0) {
            return m[step];
        }

        m[step] = (len-step)-1;

        for (int i = step; i < len; i++) {
            if (isPalindrome(s, step, i)) {
                m[step] = min(m[step], 1+minCut(s, i+1));
            }
        }

        return m[step];
    }

    bool isPalindrome(string &s, int i, int j) {
        while (i < j) {
            if (s[i] != s[j]) {
                return false;
            }

            i++;
            j--;
        }
        return true;
    }
};
