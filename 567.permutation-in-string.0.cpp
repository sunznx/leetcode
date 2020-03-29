// CreateTime: 2020-03-29 18:03:23
class Solution {
public:
    vector<int> m;
    bool checkInclusion(string s1, string s2) {
        auto l1 = s1.size();
        auto l2 = s2.size();
        if (l1 > l2) {
            return false;
        }

        m.resize(26, 0);

        for (int i = 0; i < s1.size(); i++) {
            m[s1[i]-'a']++;
            m[s2[i]-'a']--;
        }

        if (check()) {
            return true;
        }

        for (int i = l1; i < s2.size(); i++) {
            m[s2[i]-'a']--;
            m[s2[i-l1]-'a']++;
            if (check()) {
                return true;
            }
        }

        return false;
    }

    bool check() {
        for (auto &c: m) {
            if (c != 0) {
                return false;
            }
        }
        return true;
    }
};