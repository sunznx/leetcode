class Solution {
public:

    bool isAnagram(string s, string t) {
        int P = 131;

        vector<unsigned int> p(27);
        p[0] = 1;
        for (int i = 1; i <= 26; i++) {
            p[i] = p[i-1] * P;
        }

        unsigned int ans1 = calcHash(p, s);
        unsigned int ans2 = calcHash(p, t);
        return ans1 == ans2;
    }

    unsigned int calcHash(vector<unsigned int> &p, string &s) {
        int n = s.size();

        unsigned int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += p[s[i]-'a'];
        }
        return ans;
    }
};

