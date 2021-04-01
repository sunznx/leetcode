// CreateTime: 2021-04-01 13:00:15
class Solution {
public:
    vector<int> m1;
    vector<int> m2;

    bool checkInclusion(string s1, string s2) {
        m1.resize(256);
        m2.resize(256);

        for (auto &x: s1) {
            m1[x]++;
        }

        int l = 0;
        for (int r = 0; r < s2.size(); r++) {
            auto x = s2[r];
            m2[x]++;

            if (r-l+1 == s1.size()) {
                if (check()) {
                    return true;
                }
                auto y = s2[l++];
                m2[y]--;
            }
        }
        return false;
    }

    bool check() {
        for (char i = 'a'; i <= 'z'; i++) {
            if (m1[i] != m2[i]) {
                return false;
            }
        }
        return true;
    }
};
