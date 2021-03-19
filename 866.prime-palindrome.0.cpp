// CreateTime: 2021-03-19 19:39:53
class Solution {
public:
    int primePalindrome(int N) {
        string s = to_string(N);
        while (true) {
            if (isPalindrome(s) && isPrime(s)) {
                return stoi(s);
            }
            s = nextPalindrome(s);
        }
        return -1;
    }

    tuple<string, string, string> split(string &s) {
        int len = s.size();
        if (len % 2 == 1) {
            string p1 = s.substr(0, len/2);
            string p2 = s.substr(len/2, 1);
            string p3 = s.substr(len/2+1, len/2);
            return {p1, p2, p3};
        }

        string p1 = s.substr(0, len/2);
        string p2 = "";
        string p3 = s.substr(len/2, len/2);
        return {p1, p2, p3};
    }

    string nextPalindrome(string &s) {
        if (s == "9") {
            return "11";
        }

        if (s.size() == 1) {
            s[0] += 1;
            return s;
        }

        auto [p1, p2, p3] = split(s);
        if (stoi(rev(p1)) > stoi(p3)) {
            return p1 + p2 + rev(p1);
        }

        if (p2.size() == 0) {
            if (p1 == string(p1.size(), '9')) {
                return string(1, '1') + string(s.size()-1, '0') + string(1, '1');
            }

            p1 = to_string(stoi(p1)+1);
            return p1 + p2 + rev(p1);
        }

        if (p2[0] != '9') {
            p2[0] += 1;
            return p1 + p2 + rev(p1);
        }

        if (p1 == string(p1.size(), '9')) {
            return string(1, '1') + string(s.size()-1, '0') + string(1, '1');
        }

        p2[0] = '0';
        p1 = to_string(stoi(p1)+1);
        return p1 + p2 + rev(p1);
    }


    bool isPalindrome(string &s) {
        int len = s.size();
        for (int i = 0; i < len/2; i++) {
            if (s[i] != s[len-1-i]) {
                return false;
            }
        }
        return true;
    }

    bool isPrime(string &s) {
        int n = stoi(s);

        if (n <= 1) {
            return false;
        }

        if (n == 2) {
            return true;
        }

        if (n % 2 == 0) {
            return false;
        }

        for (int i = 3; i*i <= n; i+=2) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }

    string rev(string &s) {
        string r = s;
        reverse(r.begin(), r.end());
        return r;
    }
};
