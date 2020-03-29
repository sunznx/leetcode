// CreateTime: 2020-03-29 18:03:23
class Solution {
public:
    vector<int> m1;
    vector<int> m2;
    bool checkInclusion(string s1, string s2) {

        auto l1 = s1.size();
        auto l2 = s2.size();
        if (l1 > l2) {
            return false;
        }

        m1.resize(26, 0);
        m2.resize(26, 0);

        for (int i = 0; i < s1.size(); i++) {
            m1[s1[i]-'a']++;
            m2[s2[i]-'a']++;
        }

        if (check()) {
            return true;
        }

        for (int i = l1; i < s2.size(); i++) {
            m2[s2[i]-'a']++;
            m2[s2[i-l1]-'a']--;
            if (check()) {
                return true;
            }
        }

        return false;
    }

    bool check() {
        for (int i = 0; i < 26; i++) {
            if (m1[i] != m2[i]) {
                return false;
            }
        }
        return true;
    }
};