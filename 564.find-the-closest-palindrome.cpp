// CreateTime: 2021-03-12 12:36:51
class Solution {
public:
    typedef long long LL;

    string nearestPalindromic(string n) {
        int len = n.size();

        if (n.size() == 1) {
            if (n[0] == '0') {
                return "-1";
            }
            return string(1, n[0]-1);
        }

        LL num = stoll(n);

        string s1 = n;
        string s2 = n;
        string s3 = n;

        string p1;
        string p2;
        string p3;

        if (len % 2 == 0) {
            p1 = n.substr(0, len/2);
            p3 = n.substr(len/2);
        } else {
            p1 = n.substr(0, len/2);
            p2 = n.substr(len/2, 1);
            p3 = n.substr(len/2+1);
        }

        // 保持 p1 不变的情况
        if (p2.size() == 0) {
            s1 = p1 + rev(p1);
        } else {
            string ss1 = n;
            string ss2 = n;
            string ss3 = n;

            // p2 不变
            ss1 = p1 + p2 + rev(p1);

            // p2+1
            if (p2[0] != '9') {
                ss2 = p1 + string(1, p2[0]+1) + rev(p1);
            }

            // p2-1
            if (p2[0] != '0') {
                ss3 = p1 + string(1, p2[0]-1) + rev(p1);
            }

            LL n1 = stoll(ss1);
            LL n2 = stoll(ss2);
            LL n3 = stoll(ss3);
            LL diff1 = abs(n1 - num);
            LL diff2 = abs(n2 - num);
            LL diff3 = abs(n3 - num);

            if (diff2 > 0 && (diff2 <= diff1 || diff1 == 0) && (diff2 <= diff3 || diff3 == 0)) {
                s1 = ss2;
            }

            if (diff1 > 0 && (diff1 <= diff2 || diff2 == 0) && (diff1 <= diff3 || diff3 == 0)) {
                s1 = ss1;
            }

            if (diff3 > 0 && (diff3 <= diff1 || diff1 == 0) && (diff3 <= diff2 || diff2 == 0)) {
                s1 = ss3;
            }
        }

        // p1+1 的情况
        if (p1 == string(p1.size(), '9')) {
            s2 = string(1, '1') + string(n.size()-1, '0') + string(1, '1');
        } else {
            LL k = stoll(p1);
            string newP1 = to_string(k+1);
            if (p2.size()) {
                s2 = newP1 + string(1, '0') + rev(newP1);
            } else {
                s2 = newP1 + rev(newP1);
            }
        }

        // prefix-1 的情况
        if (p1 == string(1, '1') + string(p1.size()-1, '0')) {
            s3 = string(n.size()-1, '9');
        } else {
            LL k = stoll(p1);
            string newP1 = to_string(k-1);
            if (p2.size()) {
                s3 = newP1 + string(1, '9') + rev(newP1);
            } else {
                s3 = newP1 + rev(newP1);
            }
        }

        LL n1 = stoll(s1);
        LL n2 = stoll(s2);
        LL n3 = stoll(s3);
        LL diff1 = abs(n1 - num);
        LL diff2 = abs(n2 - num);
        LL diff3 = abs(n3 - num);

        if (diff3 > 0 && (diff3 <= diff1 || diff1 == 0) && (diff3 <= diff2 || diff2 == 0)) {
            return s3;
        }

        if (diff1 > 0 && (diff1 <= diff2 || diff2 == 0) && (diff1 <= diff3 || diff3 == 0)) {
            return s1;
        }

        if (diff2 > 0 && (diff2 <= diff1 || diff1 == 0) && (diff2 <= diff3 || diff3 == 0)) {
            return s2;
        }

        return n;
    }

    string rev(string &s) {
        string r = s;
        reverse(r.begin(), r.end());
        return r;
    }
};
