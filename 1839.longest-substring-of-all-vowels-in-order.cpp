// CreateTime: 2021-04-25 10:40:50
class Solution {
public:
    int longestBeautifulSubstring(string word) {
        int ans = 0;

        vector<int> m(256);
        int len = word.size();
        int l = 0;
        for (int r = 0; r < len; r++) {
            if (r > 0 && word[r] < word[r-1]) {
                fill(m.begin(), m.end(), 0);
                l = r;
            }

            auto x = word[r];
            m[x]++;

            if (ok(m)) {
                ans = max(ans, r-l+1);
            }
        }
        return ans;
    }

    bool ok(vector<int> &m) {
        bool a = m['a'] > 0;
        bool e = m['e'] > 0;
        bool i = m['i'] > 0;
        bool o = m['o'] > 0;
        bool u = m['u'] > 0;
        return u > 0 && o > 0 && i > 0 && e > 0 && a > 0;
    }
};