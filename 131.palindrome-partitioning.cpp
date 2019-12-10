// CreateTime: 2019-12-09 08:33:39
class Solution {
public:
    vector<vector<string>> res;
    vector<string> v;

    vector<vector<string>> partition(string s) {
        dfs(s, 0);
        return res;
    }

    void dfs(string &s, int step) {
        if (step == s.size()) {
            res.push_back(v);
            return;
        }

        if (v.size() == 0 || isPalindrome(v[v.size()-1])) {
            v.push_back(string(1, s[step]));
            dfs(s, step+1);
            v.pop_back();
        }


        if (v.size()) {
            v[v.size()-1].push_back(s[step]);
            if (step+1 != s.size() || isPalindrome(v[v.size()-1])) {
                dfs(s, step+1);
            }
            v[v.size()-1].pop_back();
        }
    }

    bool isPalindrome(string& s) {
        int l = 0;
        int r = s.size()-1;

        while (l < r) {
            if (s[l] == s[r]) {
                l++;
                r--;
            } else {
                return false;
            }
        }
        return true;
    }
};