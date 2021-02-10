// CreateTime: 2021-02-10 10:46:07
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> m1;
        unordered_map<char, int> m2;

        for (auto &x: s1) {
            m1[x]++;
        }

        int need = m1.size();
        int cnt = 0;

        int l = 0;
        for (int r = 0; r < s2.size(); r++) {
            auto x = s2[r];
            m2[x]++;

            if (m1.find(x) != m1.end() && m1[x] == m2[x]) {
                cnt++;
            }

            if (r-l+1 == s1.size()) {
                if (cnt == need) {
                    return true;
                }

                auto y = s2[l++];
                if (m1.find(y) != m1.end() && m1[y] == m2[y]) {
                    cnt--;
                }
                m2[y]--;
            }
        }

        return false;
    }
};
