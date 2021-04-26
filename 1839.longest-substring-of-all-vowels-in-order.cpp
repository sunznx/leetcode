// CreateTime: 2021-04-25 10:40:50
class Solution {
public:
    vector<int> m;

    int longestBeautifulSubstring(string word) {
        int ans = 0;

        m.resize(256);
        int len = word.size();
        int l = 0;
        for (int r = 0; r < len; r++) {
            if (r > 0 && word[r] < word[r-1]) {
                fill(m.begin(), m.end(), 0);
                l = r;
            }

            auto x = word[r];
            m[x]++;

            while (check() == false) {
                auto y = word[l++];
                m[y]--;
            }

            if (ok()) {
                ans = max(ans, r-l+1);
            }
        }
        return ans;
    }

    bool check() {
        bool a = m['a'] > 0;
        bool e = m['e'] > 0;
        bool i = m['i'] > 0;
        bool o = m['o'] > 0;
        bool u = m['u'] > 0;

        if (u && (!a || !e || !i || !o)) {
            return false;
        }

        if (o && (!a || !e || !i)) {
            return false;
        }

        if (i && (!a || !e)) {
            return false;
        }

        if (e && (!a)) {
            return false;
        }
        return true;
    }

    bool ok() {
        bool a = m['a'] > 0;
        bool e = m['e'] > 0;
        bool i = m['i'] > 0;
        bool o = m['o'] > 0;
        bool u = m['u'] > 0;
        return u > 0 && o > 0 && i > 0 && e > 0 && a > 0;
    }
};