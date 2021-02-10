// CreateTime: 2021-02-10 12:04:13
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> m1;
        unordered_map<char, int> m2;

        for (auto &x: t) {
            m2[x]++;
        }

        string ans;
        int need = m2.size();
        int cnt = 0;

        int l = 0;
        for (int r = 0; r < s.size(); r++) {
            auto x = s[r];
            m1[x]++;

            if (m2.find(x) != m2.end() && m2[x] == m1[x]) {
                cnt++;
            }

            while (cnt == need) {
                if (ans == "" || ans.size() > r-l+1) {
                    ans = s.substr(l, r-l+1);
                }

                auto y = s[l++];
                m1[y]--;

                if (m2.find(y) != m2.end() && m2[y] == m1[y]+1) {
                    cnt--;
                }
            }
        }

        return ans;
    }
};
