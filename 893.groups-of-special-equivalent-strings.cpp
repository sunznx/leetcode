class Solution {
public:
    map<string, int> m;

    int numSpecialEquivGroups(vector<string>& A) {
        int ans = 0;
        for (int i = 0; i < A.size(); i++) {
            normalize(A[i]);
            if (m[A[i]] == 0) {
                ans += 1;
            }
            m[A[i]] += 1;
        }

        return ans;
    }

    void normalize(string &s) {
        int len = s.size();

        string s1 = "";
        string s2 = "";
        for (int i = 0; i < len; i+=2) {
            s1 += s[i];
        }
        for (int i = 1; i < len; i+=2) {
            s2 += s[i];
        }
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());

        for (int i = 0; i < s1.size(); i++) {
            s[2*i] = s1[i];
        }
        for (int i = 0; i < s2.size(); i++) {
            s[2*i+1] = s2[i];
        }
    }
};
