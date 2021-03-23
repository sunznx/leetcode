// CreateTime: 2021-03-23 07:16:56
class Solution {
public:
    typedef long long LL;

    int superpalindromesInRange(string left, string right) {
        int ans = 0;

        LL l = sqrt(stoll(left));
        LL r = sqrt(stoll(right));
        string s = to_string(l);

        while (stoll(s) <= r) {
            string ss = to_string(stoll(s) * stoll(s));
            if (check(s) && check(ss)) {
                ans++;
            }
            s = nextPalindrome(s);
        }
        return ans;
    }

    bool check(string &s) {
        int len = s.size();
        for (int i = 0; i < len/2; i++) {
            if (s[i] != s[len-1-i]) {
                return false;
            }
        }
        return true;
    }

    string nextPalindrome(string &s) {
        int len = s.size();
        if (len == 1 && s[0] == '9') {
            return "11";
        } else if (len == 1) {
            return string(1, s[0]+1);
        }

        auto arr = split(s);
        auto p1 = arr[0];
        auto p2 = arr[1];
        auto p3 = arr[2];

        if (rev(p1) > p3) {
            return p1 + p2 + rev(p1);
        }

        if (p1 == string(p1.size(), '9')) {
            return string(1, '1') + string(len-1, '0') + string(1, '1');
        }

        if ((p2.size() == 0) || (p2.size() != 0 && p2[0] == '9')) {
            p1 = to_string(stoll(p1) + 1);
            if (p2.size()) {
                p2[0] = '0';
            }
            p3 = rev(p1);
        } else if (p2.size() && p2[0] < '9') {
            p1 = p1;
            p2[0] += 1;
            p3 = rev(p1);
        }

        return p1 + p2 + rev(p1);
    }

    vector<string> split(string &s) {
        vector<string> ans(3);

        int len = s.size();
        if (len % 2 == 0) {
            ans[0] = s.substr(0, len/2);
            ans[2] = s.substr(len/2, len/2);
        } else {
            ans[0] = s.substr(0, len/2);
            ans[1] = s.substr(len/2, 1);
            ans[2] = s.substr(len/2+1, len/2);
        }
        return ans;
    }

    string rev(string &s) {
        string r = s;
        reverse(r.begin(), r.end());
        return r;
    }
};
