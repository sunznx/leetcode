class Solution {
public:
    int myAtoi(string str) {
        int len = str.size();

        bool sign = false;

        const int MAXN = 2147483647;
        const int MINN = -2147483648;

        int idx = 0;
        while (idx < len) {
            if (str[idx] == ' ') {
                idx++;
                continue;
            } else if (str[idx] == '+') {
                idx++;
                break;
            } else if (str[idx] == '-') {
                idx++;
                sign = !sign;
                break;
            } else {
                break;
            }
        }
        while (idx < len) {
            if (str[idx] == '0') {
                idx++;
            } else {
                break;
            }
        }

        if (overflow(str, idx, sign)) {
            if (sign) {
                return MINN;
            }
            return MAXN;
        }

        int ans = 0;
        for (int i = idx; i < len; i++) {
            if (! ('0' <= str[i] && str[i] <= '9')) {
                break;
            }
            ans = ans * 10 + (str[i] - '0');
        }

        if (sign) {
            return -ans;
        }
        return ans;
    }

    inline bool overflow(string &str, int idx, bool sign) {
        int len = 0;
        int strlen = str.size();
        for (int i = idx; i < strlen; i++) {
            if (! ('0' <= str[i] && str[i] <= '9')) {
                break;
            }
            len += 1;
        }

        if (len < 10) {
            return false;
        }
        if (len > 10) {
            return true;
        }

        if (sign) {
            return str[idx+0] > '2'
                || str[idx+0] == '2' && str[idx+1] > '1'
                || str[idx+0] == '2' && str[idx+1] == '1' && str[idx+2] > '4'
                || str[idx+0] == '2' && str[idx+1] == '1' && str[idx+2] == '4' && str[idx+3] > '7'
                || str[idx+0] == '2' && str[idx+1] == '1' && str[idx+2] == '4' && str[idx+3] == '7' && str[idx+4] > '4'
                || str[idx+0] == '2' && str[idx+1] == '1' && str[idx+2] == '4' && str[idx+3] == '7' && str[idx+4] == '4' && str[idx+5] > '8'
                || str[idx+0] == '2' && str[idx+1] == '1' && str[idx+2] == '4' && str[idx+3] == '7' && str[idx+4] == '4' && str[idx+5] == '8' && str[idx+6] > '3'
                || str[idx+0] == '2' && str[idx+1] == '1' && str[idx+2] == '4' && str[idx+3] == '7' && str[idx+4] == '4' && str[idx+5] == '8' && str[idx+6] == '3' && str[idx+7] > '6'
                || str[idx+0] == '2' && str[idx+1] == '1' && str[idx+2] == '4' && str[idx+3] == '7' && str[idx+4] == '4' && str[idx+5] == '8' && str[idx+6] == '3' && str[idx+7] == '6' && str[idx+8] > '4'
                || str[idx+0] == '2' && str[idx+1] == '1' && str[idx+2] == '4' && str[idx+3] == '7' && str[idx+4] == '4' && str[idx+5] == '8' && str[idx+6] == '3' && str[idx+7] == '6' && str[idx+8] == '4' && str[idx+9] >= '8';
        }

        return str[idx+0] > '2'
            || str[idx+0] == '2' && str[idx+1] > '1'
                || str[idx+0] == '2' && str[idx+1] == '1' && str[idx+2] > '4'
                || str[idx+0] == '2' && str[idx+1] == '1' && str[idx+2] == '4' && str[idx+3] > '7'
                || str[idx+0] == '2' && str[idx+1] == '1' && str[idx+2] == '4' && str[idx+3] == '7' && str[idx+4] > '4'
                || str[idx+0] == '2' && str[idx+1] == '1' && str[idx+2] == '4' && str[idx+3] == '7' && str[idx+4] == '4' && str[idx+5] > '8'
                || str[idx+0] == '2' && str[idx+1] == '1' && str[idx+2] == '4' && str[idx+3] == '7' && str[idx+4] == '4' && str[idx+5] == '8' && str[idx+6] > '3'
                || str[idx+0] == '2' && str[idx+1] == '1' && str[idx+2] == '4' && str[idx+3] == '7' && str[idx+4] == '4' && str[idx+5] == '8' && str[idx+6] == '3' && str[idx+7] > '6'
                || str[idx+0] == '2' && str[idx+1] == '1' && str[idx+2] == '4' && str[idx+3] == '7' && str[idx+4] == '4' && str[idx+5] == '8' && str[idx+6] == '3' && str[idx+7] == '6' && str[idx+8] > '4'
                || str[idx+0] == '2' && str[idx+1] == '1' && str[idx+2] == '4' && str[idx+3] == '7' && str[idx+4] == '4' && str[idx+5] == '8' && str[idx+6] == '3' && str[idx+7] == '6' && str[idx+8] == '4' && str[idx+9] >= '7';
    }
};



